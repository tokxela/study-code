#include <stdio.h>

#define PATH_FILE_1 "sensor1.txt"
#define PATH_FILE_2 "sensor2.txt"

#define THRESHOLD_SENSOR_1 0.8
#define THRESHOLD_SENSOR_2 0.7

#define ARRAY_SIZE 3000

typedef struct {
    float time;
    double probability;
} SensorData;

typedef struct {
    int id;
    double threshold;
    SensorData data[ARRAY_SIZE];
    int object_detection[ARRAY_SIZE];
} Sensor;

/*
    Muss Daten aus Dateien auslesen und Threshold überprüfen
*/
int processingSensor(Sensor *p_sensor, FILE* file) {

    char buffer_line[256];

    for (int i = 0; i < ARRAY_SIZE; i++) {

        fgets(buffer_line, sizeof(buffer_line), file);

        if (sscanf(buffer_line, "%f %lf", &p_sensor->data[i].time, &p_sensor->data[i].probability) != 2) {
            printf("An error occurred while reading values.\n");
            return 2;
        }   
        if (p_sensor->data[i].probability > p_sensor->threshold) {
            p_sensor->object_detection[i] = 1;
        } else {
            p_sensor->object_detection[i] = 0;
        }
    }
    return 0;
}

void printIntervals(Sensor *sensor) {
    int in_interval = 0;
    for (int i = 0; i < ARRAY_SIZE; i++) {
        if (sensor->object_detection[i] == 1 && in_interval == 0) {
            printf("Start: %.2f s ", sensor->data[i].time);
            in_interval = 1;
        } else if (sensor->object_detection[i] == 0 && in_interval == 1) {
            printf("End: %.2f s\n", sensor->data[i-1].time);
            in_interval = 0;
        }
    }
    if (in_interval) printf("End: %.2f s\n", sensor->data[ARRAY_SIZE-1].time);
}

void printFusions(Sensor *sensor_1, Sensor *sensor_2) {
    int in_interval = 0;
    for (int i = 0; i < ARRAY_SIZE; i++) {
        if (sensor_2->object_detection[i] == 1 && sensor_1->object_detection[i] == 1 && in_interval == 0) {
            printf("Start: %.2f s ", sensor_1->data[i].time);
            in_interval = 1;
        } else if ((sensor_2->object_detection[i] == 0 || sensor_1->object_detection[i] == 0) && in_interval == 1) {
            printf("End: %.2f s\n", sensor_1->data[i-1].time);
            in_interval = 0;
        }

    }
    if (in_interval) {
        printf("End: %.2f s\n", sensor_1->data[ARRAY_SIZE-1].time);
    }
}

int main() {

    Sensor sensor_1;
    Sensor sensor_2;

    Sensor *p_sensor_1 = &sensor_1;
    Sensor *p_sensor_2 = &sensor_2;

    p_sensor_1->id = 1;
    p_sensor_1->threshold = THRESHOLD_SENSOR_1;
    p_sensor_2->id = 2;
    p_sensor_2->threshold = THRESHOLD_SENSOR_2;

    FILE* file1 = fopen(PATH_FILE_1, "r");
    FILE* file2 = fopen(PATH_FILE_2, "r");

    if (file1 == NULL || file2 == NULL) {
        printf("An error occured, while reading the files.\n");
        return 1;
    }

    if (processingSensor(&sensor_1, file1)) {
        printf("An error occured, while processing the data in file1.txt.\n");
        return 2;
    } else {
        fclose(file1);
    }
    if (processingSensor(&sensor_2, file2)) {
        printf("An error occured, while processing the data in file2.txt.\n");
        return 3;
    } else {
        fclose(file2);
    }


    printf("--- Object Detection Results ---\nSensor 1 detections:\n");
    printIntervals(p_sensor_1);
    printf("Sensor 2 detections:\n");
    printIntervals(p_sensor_2);

    printf("Fused signal (both sensors):\n");
    printFusions(p_sensor_1, p_sensor_2);
    return 0;
}