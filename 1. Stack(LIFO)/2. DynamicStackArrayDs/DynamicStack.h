/*
 * DynamicStack.h
 *
 *  Created on: Sep 27, 2024
 *      Author: Mohamed Elsayed
 */

#ifndef DYNAMICSTACK_H_
#define DYNAMICSTACK_H_

#include <stdio.h>
#include <stdlib.h>
#include "Platform_Types.h"

typedef struct{
	void **stackArray; // Dynamic array of void pointers (void *)
	uint32 count;
	uint32 size;
	uint32 top;
}stack_t;

typedef enum{
	STACK_OK,
	STACK_EMPTY,
	STACK_NOT_EMPTY,
	STACK_FULL,
	STACK_NOT_FULL,
	STACK_NULL,
	STACK_MEM_ERROR
}stack_status_t;

stack_status_t stackInit(stack_t *st, uint32 maxSize);
stack_status_t stackDestroy(stack_t *st);
stack_status_t stackPush(stack_t *st, void *element);
stack_status_t stackPop(stack_t *st, void **element);
stack_status_t stackTop(stack_t *st, void **element);

#endif /* DYNAMICSTACK_H_ */
