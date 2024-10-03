/*
 * Queue.h
 *
 *  Created on: Sep 28, 2024
 *      Author: Dubai Store
 */

#ifndef QUEUE_H_
#define QUEUE_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Platform_Types.h"

#define QUEUE_MAX_SIZE 5

typedef struct{
	void **queueArray; // Array of void pointers
	uint32 maxSize;
	uint32 count;
	uint32 front;
	uint32 rear;
}queue_t;

typedef enum{
	QUEUE_OK,
	QUEUE_NULL,
	QUEUE_EMPTY,
	QUEUE_NOT_EMPTY,
	QUEUE_FULL,
	QUEUE_NOT_FULL
}queue_status_t;


queue_t *QueueInit(uint32 size, queue_status_t *ret);
queue_status_t QueueDestroy(queue_t *q);
queue_status_t QueueEnqueue(queue_t *q, void *data);
void *QueueDequeue(queue_t *q, queue_status_t *ret);
void *QueueFront(queue_t *q, queue_status_t *ret);
void *QueueRear(queue_t *q, queue_status_t *ret);
queue_status_t queueIsFull(queue_t *q);
queue_status_t queueIsEmpty(queue_t *q);
queue_status_t QueueDisplay(queue_t *q);

#endif /* QUEUE_H_ */
