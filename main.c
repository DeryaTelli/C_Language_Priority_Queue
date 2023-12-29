#include <stdio.h>
#include <stdlib.h>
#define QUEUE_SIZE 13 

typedef struct priorityQueue {
    int data[QUEUE_SIZE + 1];
    int cnt;
} pqueue;

void swap(int *p1, int *p2) {
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

void initialize(pqueue *p) {
    p->cnt = 0;
}

void enqueue(pqueue *p, int x) {
    if (p->cnt == QUEUE_SIZE) {
        printf("Queue is full");
    } else {
        p->data[++p->cnt] = x;
        int index = p->cnt;
        while (index != 1 && p->data[index] < p->data[index / 2]) {
            swap(&p->data[index], &p->data[index / 2]);
            index = index / 2;
        }
    }
}

int deleteMin(pqueue *p) {
    if (p->cnt == 0) {
        printf("Queue is empty");
        return 0;
    } else {
        int min = p->data[1];
        p->data[1] = p->data[p->cnt--];
        int index = 1;
        while (2 * index <= p->cnt && (p->data[index] > p->data[2 * index] || p->data[index] > p->data[2 * index + 1])) {
            if (2 * index + 1 <= p->cnt) {
                if (p->data[2 * index] < p->data[2 * index + 1]) {
                    swap(&p->data[index], &p->data[2 * index]);
                    index = 2 * index;
                } else {
                    swap(&p->data[index], &p->data[2 * index + 1]); 
                    index = 2 * index + 1;
                }
            } else {
                swap(&p->data[index], &p->data[2 * index]);
                break;
            }
        }
        return min;
    }
}


int main() {
    pqueue myQueue;
    initialize(&myQueue);
    enqueue(&myQueue, 10);
    enqueue(&myQueue, 20);
    enqueue(&myQueue, 30);
    enqueue(&myQueue, 45);
    enqueue(&myQueue, 25);
    enqueue(&myQueue, 39);
    enqueue(&myQueue, 32);
    enqueue(&myQueue, 50);
    enqueue(&myQueue, 48);
    enqueue(&myQueue, 49);
    
    enqueue(&myQueue, 15);
    
    printf("Deleted min element: %d\n", deleteMin(&myQueue));
    printf("Deleted min element: %d\n", deleteMin(&myQueue));
  
  

    return 0;
}
