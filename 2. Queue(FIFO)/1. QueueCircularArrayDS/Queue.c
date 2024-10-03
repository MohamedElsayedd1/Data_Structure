/*
 * Queue.c
 *
 *  Created on: Sep 28, 2024
 *      Author: Dubai Store
 */

#include "Queue.h"

queue_t *QueueInit(uint32 size, queue_status_t *ret){
	if(!ret){
		*ret = QUEUE_NULL;
		return NULL;
	}
	else{
		queue_t *q = (queue_t *)malloc(sizeof(queue_t));
		if(!q){
			*ret = QUEUE_NULL;
			return NULL;
		}
		else{
			q->maxSize = size;
			q->count = 0;
			q->front = 0;
			q->rear = 0;
			q->queueArray = (void **)calloc(q->maxSize, sizeof(void *));
			if(!q->queueArray){
				*ret = QUEUE_NULL;
				return NULL;
			}
			else{
				*ret = QUEUE_OK;
				return (queue_t *)q;
			}
		}

	}
}

queue_status_t QueueDestroy(queue_t *q){
	if(!q){
		return QUEUE_NULL;
	}
	else{
		free(q->queueArray);
		free(q);
		return QUEUE_OK;
	}
}

queue_status_t QueueEnqueue(queue_t *q, void *data){
	if(!data || !q){
		return QUEUE_NULL;
	}
	else{
		if(queueIsFull(q) == QUEUE_FULL){
			return QUEUE_FULL;
		}
		else{
			q->queueArray[q->rear] = (void *)data;
			q->rear++;
			if(q->rear >= q->maxSize){
				q->rear = 0;
			}
			q->count++;
			return QUEUE_OK;
		}
	}
}

void *QueueDequeue(queue_t *q, queue_status_t *ret){
	if(!ret || !q){
		*ret = QUEUE_NULL;
		return NULL;
	}
	else{
		if(queueIsEmpty(q) == QUEUE_EMPTY){
			return NULL;
		}
		else{
			void *front = q->queueArray[q->front];
			// Move the front pointer and wrap it around if needed
			q->front++;
			if(q->front >= q->maxSize){
				q->front = 0;
			}
			q->count--;
			*ret = QUEUE_OK;
			return front;
		}
	}

}

void *QueueFront(queue_t *q, queue_status_t *ret){
	if(!ret || !q){
		*ret = QUEUE_NULL;
		return NULL;
	}
	else{

	}
}

void *QueueRear(queue_t *q, queue_status_t *ret){
	if(!ret || !q){
		*ret = QUEUE_NULL;
		return NULL;
	}
	else{
		if(queueIsEmpty(q) == QUEUE_EMPTY){
			return NULL;
		}
		else{
			uint32 temp = q->rear;
			if(temp == 0){
				temp = q->maxSize - 1; // Wrap around to the last position if rear is at 0
			} else {
				temp--;
			}
			*ret = QUEUE_OK;
			return (void*)q->queueArray[temp];
		}
	}
}

queue_status_t queueIsFull(queue_t *q){
	if(!q){
		return QUEUE_NULL;
	}
	else{
		return (q->count == q->maxSize) ? QUEUE_FULL : QUEUE_NOT_FULL;
	}
}

queue_status_t queueIsEmpty(queue_t *q){
	if(!q){
		return QUEUE_NULL;
	}
	else{
		return (q->count == 0) ? QUEUE_EMPTY : QUEUE_NOT_EMPTY;
	}
}

queue_status_t QueueDisplay(queue_t *q) {
    if (!q) {
        return QUEUE_NULL;
    }

    if (queueIsEmpty(q) == QUEUE_EMPTY) {
        printf("Queue is empty, can't display any data.\n");
        return QUEUE_EMPTY;
    } else {
        printf("=================Queue(FIFO)===============\n");

        int currentIndex = q->front;
        for (int i = 0; i < q->count; i++) {
            printf("\t %d \n", *(uint32 *)q->queueArray[currentIndex]);
            currentIndex++;
            if (currentIndex >= q->maxSize) {
                currentIndex = 0;  // Wrap around to the start if index goes out of bounds
            }
        }

        printf("============================================\n");
    }

    return QUEUE_OK;
}
