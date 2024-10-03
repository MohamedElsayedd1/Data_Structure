/*
 * main.c
 *
 *  Created on: Sep 27, 2024
 *      Author: Mohamed Elsayed
 */


#include "DynamicStack.h"

#define STACK_MAX_SIZE  5
#define STACK_MAX_SIZE2 20
 
int main(){
	printf("=================Program 1===================\n\n");


	stack_t myStack;
	stack_status_t ret;
	uint32 PushData1[5] = {0x10, 0x20 , 0x30, 0x40, 0x50};
	void *PopData1 = NULL;
	void *TopData1 = NULL;

	// Initializing the stack
	ret = stackInit(&myStack, STACK_MAX_SIZE);
	if(ret == STACK_OK){
		printf("Stack has been initialized successfully.\n");
	}
	else{
		printf("Stack is not initialized successfully.\n");
	}

	// Pushing void pointers to the stack
	for(int i = 0; i < 6; i++){
		ret = stackPush(&myStack, &PushData1[i]);
		if(ret == STACK_OK){
			printf("Address 0X%x is pushed into the stack which its value = 0X%x.\n", (void *)&PushData1[i],PushData1[i]);
		}
		else{
			printf("Failed to push data into stack, stack is full.\n");
		}
	}

	// Display the stack top data
	ret = stackTop(&myStack, &TopData1);
	if(ret == STACK_OK){
		printf("Address 0X%x is the top of the stack which its value = 0X%x.\n", (void *)&TopData1, *(uint32 *)TopData1);
	}
	else{
		printf("Failed to get the top data from stack, stack is empty.\n");
	}


	// Poping void pointer from the stack
	for(int i = 0; i < 6; i++){
		ret = stackPop(&myStack, &PopData1);
		if(ret == STACK_OK){
			printf("Address 0X%x is popped from the stack which its value = 0X%x.\n", (void *)PopData1, *(uint32 *)PopData1);
		}
		else{
			printf("Failed to pop data from stack, stack is empty.\n");
		}
	}

	// Destroy the stack
	ret = stackDestroy(&myStack);
	if(ret == STACK_OK){
		printf("Stack is destroyed successfully.\n");
	}
	else{
		printf("Stack is not destroyed successfully.\n");
	}

	printf("\n============================================\n\n");

	printf("=================Program 2===================\n\n");


	stack_t myStack2;
	char PushData2[5] = {'A', 'B', 'C', 'D', 'E'};
	void *PopData2 = NULL;
	void *TopData2 = NULL;

	// Initializing the stack
	ret = stackInit(&myStack2, STACK_MAX_SIZE);
	if (ret == STACK_OK) {
		printf("Stack has been initialized successfully.\n");
	} else {
		printf("Stack is not initialized successfully.\n");
	}

	// Pushing void pointers to the stack
	for (int i = 0; i < 6; i++) {
		ret = stackPush(&myStack2, &PushData2[i]);
		if (ret == STACK_OK) {
			printf("Character '%c' is pushed into the stack at address 0X%x.\n", PushData2[i], (void *)&PushData2[i]);
		} else {
			printf("Failed to push data into the stack, stack is full.\n");
		}
	}

	// Popping void pointers from the stack
	for (int i = 0; i < 6; i++) {
		ret = stackPop(&myStack2, &PopData2);
		if (ret == STACK_OK) {
			printf("Character '%c' is popped from the stack from address 0X%x.\n", *(char *)PopData2, (void *)PopData2);
		} else {
			printf("Failed to pop data from stack, stack is empty.\n");
		}
	}

	// Display the stack top data
	ret = stackTop(&myStack, &TopData2);
	if(ret == STACK_OK){
		printf("Address 0X%x is the top of the stack which its value = 0X%x.\n", (void *)&TopData2, *(uint32 *)TopData2);
	}
	else{
		printf("Failed to get the top data from stack, stack is empty.\n");
	}

	// Destroy the stack
	ret = stackDestroy(&myStack2);
	if (ret == STACK_OK) {
		printf("Stack is destroyed successfully.\n");
	} else {
		printf("Stack is not destroyed successfully.\n");
	}

	printf("\n============================================\n\n");

	printf("=================Program 3===================\n\n");

	stack_t myStack3;

	// Data of different types
	uint32 intData[5] = {0x10, 0x20, 0x30, 0x40, 0x50};  // Integers
	char charData[5] = {'A', 'B', 'C', 'D', 'E'};        // Characters
	float floatData[5] = {1.1, 2.2, 3.3, 4.4, 5.5};      // Floats
	double doubleData[5] = {10.1, 20.2, 30.3, 40.4, 50.5};  // Doubles

	void *PopData = NULL;
	void *TopData = NULL;

	// Initializing the stack
	ret = stackInit(&myStack3, STACK_MAX_SIZE2);
	if (ret == STACK_OK) {
		printf("Stack has been initialized successfully.\n");
	} else {
		printf("Stack is not initialized successfully.\n");
	}

	// Pushing integers to the stack
	for (int i = 0; i < 5; i++) {
		ret = stackPush(&myStack3, &intData[i]);
		if (ret == STACK_OK) {
			printf("Integer 0X%x is pushed into the stack at address 0X%x.\n", intData[i], (void *)&intData[i]);
		} else {
			printf("Failed to push integer into stack, stack is full.\n");
		}
	}

	// Pushing characters to the stack
	for (int i = 0; i < 5; i++) {
		ret = stackPush(&myStack3, &charData[i]);
		if (ret == STACK_OK) {
			printf("Character '%c' is pushed into the stack at address 0X%x.\n", charData[i], (void *)&charData[i]);
		} else {
			printf("Failed to push character into stack, stack is full.\n");
		}
	}

	// Pushing floats to the stack
	for (int i = 0; i < 5; i++) {
		ret = stackPush(&myStack3, &floatData[i]);
		if (ret == STACK_OK) {
			printf("Float %.2f is pushed into the stack at address 0X%x.\n", floatData[i], (void *)&floatData[i]);
		} else {
			printf("Failed to push float into stack, stack is full.\n");
		}
	}

	// Pushing doubles to the stack
	for (int i = 0; i < 5; i++) {
		ret = stackPush(&myStack3, &doubleData[i]);
		if (ret == STACK_OK) {
			printf("Double %.2f is pushed into the stack at address 0X%x.\n", doubleData[i], (void *)&doubleData[i]);
		} else {
			printf("Failed to push double into stack, stack is full.\n");
		}
	}

	// Peeking the top element (last double pushed)
	ret = stackTop(&myStack3, &TopData);
	if (ret == STACK_OK) {
		printf("Address 0X%x is the top of the stack which its value = %.2f (double).\n", (void *)&TopData, *(double *)TopData);
	} else {
		printf("Failed to get the top data from stack, stack is empty.\n");
	}

	// Popping all data types from the stack
	for (int i = 0; i < 5; i++) {
		ret = stackPop(&myStack3, &PopData);
		if (ret == STACK_OK) {
			printf("Double %.2f is popped from the stack at address 0X%x.\n", *(double *)PopData, (void *)PopData);
		} else {
			printf("Failed to pop double from stack, stack is empty.\n");
		}
	}

	for (int i = 0; i < 5; i++) {
		ret = stackPop(&myStack3, &PopData);
		if (ret == STACK_OK) {
			printf("Float %.2f is popped from the stack at address 0X%x.\n", *(float *)PopData, (void *)PopData);
		} else {
			printf("Failed to pop float from stack, stack is empty.\n");
		}
	}

	for (int i = 0; i < 5; i++) {
		ret = stackPop(&myStack3, &PopData);
		if (ret == STACK_OK) {
			printf("Character '%c' is popped from the stack at address 0X%x.\n", *(char *)PopData, (void *)PopData);
		} else {
			printf("Failed to pop character from stack, stack is empty.\n");
		}
	}

	for (int i = 0; i < 5; i++) {
		ret = stackPop(&myStack3, &PopData);
		if (ret == STACK_OK) {
			printf("Integer 0X%x is popped from the stack at address 0X%x.\n", *(uint32 *)PopData, (void *)PopData);
		} else {
			printf("Failed to pop integer from stack, stack is empty.\n");
		}
	}

	// Destroy the stack
	ret = stackDestroy(&myStack3);
	if (ret == STACK_OK) {
		printf("Stack is destroyed successfully.\n");
	} else {
		printf("Stack is not destroyed successfully.\n");
	}

	printf("\n============================================\n\n");



	return 0;
}

