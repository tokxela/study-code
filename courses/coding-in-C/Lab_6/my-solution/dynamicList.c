#include <stdio.h>
#include <stdlib.h>

typedef int data_type;

enum NODES_RETURNS {
    OK = 0,
    MEMORY_ERROR = 1,
    NODE_NOT_EXIST = 2
};

struct Node {
    data_type data;
    struct Node *pNext;
    struct Node *pPrev;
};

struct Queue {
    struct Node *pHead;
    struct Node *pTail;
};

struct Queue *create_queue() {
    struct Queue *p_queue = malloc(sizeof(*p_queue));
    if (!p_queue) {
        return 0;
    }
    p_queue->pHead = NULL;
    p_queue->pTail = NULL;
    return p_queue;
}


enum NODES_RETURNS create_first_element(struct Queue *p_queue, data_type data) {
    struct Node *p_element = malloc(sizeof(*p_element));
    if (!p_element) {
        return MEMORY_ERROR;
    }

    p_element->data = data;
    p_element->pNext = NULL;
    p_element->pPrev = NULL;

    p_queue->pHead = p_element;
    p_queue->pTail = p_element;

    return OK;
}

enum NODES_RETURNS add_element_head(struct Queue *p_queue, data_type data) {
    struct Node *p_element = malloc(sizeof(*p_element));
    if (!p_element) {
        return MEMORY_ERROR;
    } else if (p_queue->pHead == NULL) {
        return create_first_element(p_queue, data);
    }

    p_element->data = data;
    p_element->pPrev = NULL;
    p_element->pNext = p_queue->pHead;

    p_queue->pHead->pPrev = p_element;
    p_queue->pHead = p_element;

    return OK;
}

enum NODES_RETURNS add_element_tail(struct Queue *p_queue, data_type data) {
    struct Node *p_element = malloc(sizeof(*p_element));
    if (!p_element) {
        return MEMORY_ERROR;
    } else if (p_queue->pTail == NULL) {
        return create_first_element(p_queue, data);
    }

    p_element->data = data;
    p_element->pNext = NULL;
    p_element->pPrev = p_queue->pTail;


    p_queue->pTail->pNext = p_element;
    p_queue->pTail = p_element;

    return OK;
}

enum NODES_RETURNS insert_after_node(struct Queue *p_queue, struct Node *p_prev_element, data_type data) {
    struct Node *p_element = malloc(sizeof(*p_element));
    if (!p_element) {
        return MEMORY_ERROR;
    } else if (p_prev_element == NULL) {
        return NODE_NOT_EXIST;
    }
}

void display_queue(struct Queue *p_queue) {
    struct Node *p_current = p_queue->pHead;
    printf("List: ");
    while (p_current != NULL) {
        printf("%d <-> ", p_current->data);
        p_current = p_current->pNext;
    }
    printf("Ende\n");
}

int main() {
    struct Queue *q = create_queue();
    create_first_element(q, 123);
    add_element_head(q, 1234);
    add_element_tail(q, -1234);
    display_queue(q);
};