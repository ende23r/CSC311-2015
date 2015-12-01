//priorityqueue.c
//functions for creating and manipulating a priority queue data structure

#include "pqueue.h"

#define PQ_INITIAL_SIZE 4

//I wish this were private

void swap(int *arr, int ind1, int ind2) {
    if (ind1 != ind2) {
        int temp = arr[ind1];
        arr[ind1] = arr[ind2];
        arr[ind2] = temp;
    }
}

//This too
//Given a heap in proper shape, with an unsorted
//value in the root, sort the heap into order.

void sink(pQueuePointer pqp) {
    int moveThis = pqp->heap[1]; //get the value in the root
    int toHere = 1;

    bool keepSorting = true;
    while (keepSorting) {
        int child1 = -1;
        if(toHere*2 < pqp->nodes) {
            child1 = pqp->heap[(toHere * 2)];
        }
        
        int child2 = -1;
        if((toHere*2) + 1 < pqp->nodes) {
            child2 = pqp->heap[(toHere * 2) + 1];
        }
        
        if ((child1 > moveThis) || (child2 > moveThis)) {
            toHere = (child1 > child2) ? (toHere * 2) : (toHere * 2) + 1;
        } else {
            keepSorting = false;
        }
    }

    swap(pqp->heap, 1, toHere);
}

pQueuePointer newPQueue() {
    pQueuePointer pqp = (pQueuePointer) malloc(sizeof (pQueue));

    pqp->nodes = 0;
    pqp->size = PQ_INITIAL_SIZE;
    pqp->heap = (int*) malloc(sizeof (int) * PQ_INITIAL_SIZE);

    return pqp;
}

int removePQ(pQueuePointer pqp) {
    if (pqp->nodes > 0) {
        int max = pqp->heap[1];

        if (pqp->nodes > 1) {
            //put something in the first position to preserve shape.
            pqp->heap[1] = pqp->heap[(pqp->nodes)--];

            //rebuild the heap.
            sink(pqp);
        }

        //maybe downsize the heap?
        return max;
    }
    return -1;
}

void insertPQ(pQueuePointer pqp, int n) {
    int indexOfNew = ++(pqp->nodes);
    pqp->heap[indexOfNew] = n; //add the new element, then increment nodes

    //rebuild the heap
    int swapTo = indexOfNew;
    while ((swapTo > 1) && (n > pqp->heap[swapTo / 2])) {
        swapTo /= 2;
    }

    swap(pqp->heap, indexOfNew, swapTo);

    //upsize if needed
    if (pqp->nodes == pqp->size) {
        pqp->size *= 2;
        pqp->heap = (int *) realloc(pqp->heap, pqp->size);
    }
}

bool isEmptyPQ(pQueuePointer pqp) {
    return pqp->nodes == 0;
}

//print out the contents of the heap.

void printPQueue(pQueuePointer pqp) {
    printf("Priority Queue: ");

    int i;
    for (i = 1; i <= pqp->nodes; i++) {
        printf("%d, ", pqp->heap[i]);
    }
    printf("\n");
}