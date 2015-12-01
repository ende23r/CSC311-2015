/* 
 * File:   pqueue.h
 * Author: eandow16
 *
 * Header for Priority Queue functions
 * Created on November 30, 2015, 1:57 PM
 */

#ifndef HEAP_H
#define	HEAP_H

#ifdef	__cplusplus
extern "C" {
#endif

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
    
    typedef struct pqueue pQueue, *pQueuePointer;
    
    struct pqueue {
        int* heap;
        int nodes;
        int size;
    };

    pQueuePointer newPQueue();
    int removePQ( pQueuePointer );
    void insertPQ( pQueuePointer, int );
    bool isEmptyPQ( pQueuePointer );
    void printPQueue( pQueuePointer );

#ifdef	__cplusplus
}
#endif

#endif	/* HEAP_H */

