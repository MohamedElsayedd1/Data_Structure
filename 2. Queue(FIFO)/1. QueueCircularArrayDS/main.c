/*
 * main.c
 *
 *  Created on: Sep 28, 2024
 *      Author: Dubai Store
 */

#include "Queue.h"

int main(){
	queue_t *myQueue;
	queue_status_t status;
	uint32 data[] = {10, 20, 30, 40, 50, 60}; // Array of values
	uint32 *rearValue;
	uint32 *dequeuedValue;

	// Initialize the dynamic queue
	myQueue = QueueInit(QUEUE_MAX_SIZE, &status);
	if (status == QUEUE_OK) {
		printf("Queue initialized successfully with size %d.\n", myQueue->maxSize);
		printf("Address of the queue : 0x%x\n", myQueue);
	} else {
		printf("Queue initialization failed.\n");
		return -1;
	}


	// Enqueue values into the queue using a for loop
	printf("Enqueueing values...\n");
	for(int i = 0; i < QUEUE_MAX_SIZE+1; i++) {
		status = QueueEnqueue(myQueue, (void *)&data[i]);
		printf("Enqueue %d: %s\n", data[i], status == QUEUE_OK ? "Success" : "Failed");
	}

	rearValue = QueueRear(myQueue, &status);
	if (status == QUEUE_OK) {
	    printf("Rear value: %d\n", *rearValue);
	} else {
	    printf("Queue is empty or an error occurred.\n");
	}

	dequeuedValue = (uint32 *)QueueDequeue(myQueue, &status);
	if (status == QUEUE_OK) {
	    printf("Dequeued value: %d\n", *dequeuedValue);
	} else {
	    printf("Queue is empty or an error occurred.\n");
	}
	dequeuedValue = (uint32 *)QueueDequeue(myQueue, &status);
	if (status == QUEUE_OK) {
		printf("Dequeued value: %d\n", *dequeuedValue);
	} else {
		printf("Queue is empty or an error occurred.\n");
	}

	printf("Enqueueing values...\n");
	for(int i = 0; i < QUEUE_MAX_SIZE+1; i++) {
		status = QueueEnqueue(myQueue, (void *)&data[i]);
		printf("Enqueue %d: %s\n", data[i], status == QUEUE_OK ? "Success" : "Failed");
	}

	rearValue = QueueRear(myQueue, &status);
	if (status == QUEUE_OK) {
		printf("Rear value: %d\n", *rearValue);
	} else {
		printf("Queue is empty or an error occurred.\n");
	}

	// Destroy the queue
	status = QueueDestroy(myQueue);
	if (status == QUEUE_OK) {
		printf("Queue destroyed and memory freed successfully.\n");
	} else {
		printf("Queue destruction failed.\n");

	}

	return 0;
}

