#include <stdio.h>

const unsigned int LIGHT_SPEED = 299792;

int main () {
    char class [] = "NCC-1701-D";
    unsigned int crew = 1000;
    unsigned int mission_length = 2345;
    unsigned long distance = 4321243214; // kilometer
    double light_speed = (double) distance / LIGHT_SPEED;
    double range = 12312.123;

    printf("Name                    Value\n");
    printf("---------------------------------\n");
    printf("Class                   %s\n", class);
    printf("Crew count              %i\n", crew);
    printf("Mission length, days    %i\n", mission_length);
    printf("Distance traveled, km   %ld\n", distance);
    printf("%% of light-speed        %8.2f\n", light_speed);
    printf("Current range, km       %8.3f\n", range);

    return 0;
}