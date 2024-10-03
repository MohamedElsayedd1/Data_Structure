/*
 * Stack.c
 *
 *  Created on: Sep 26, 2024
 *      Author: Mohamed Elsayed
 */

#include "Stack.h"

// Helper Functions

/**
 * @brief Checks if the stack is empty.
 *
 * @param st Pointer to the stack structure.
 *
 * @returnVal STACK_NULL if the stack pointer is NULL.
 * @returnVal STACK_EMPTY if the stack is empty.
 * @returnVal STACK_NOT_EMPTY if the stack contains elements.
 */
static stack_status_t stackIsEmpty(stack_t *st);

/**
 * @brief Checks if the stack is full.
 *
 * @param st Pointer to the stack structure.
 *
 * @returnVal STACK_NULL if the stack pointer is NULL.
 * @returnVal STACK_FULL if the stack is full.
 * @returnVal STACK_NOT_FULL if the stack is not full.
 */
static stack_status_t stackIsFull(stack_t *st);

static stack_status_t stackIsEmpty(stack_t *st){
	if(!st){
		#ifdef STACK_DEBUG
		printf("Stack is pointing to NULL.\n");
		#endif
		return STACK_NULL;
	}
	else{
		return st->stack_pointer == -1 ? STACK_EMPTY : STACK_NOT_EMPTY;
	}
}

static stack_status_t stackIsFull(stack_t *st){
	if(!st){
		#ifdef STACK_DEBUG
		printf("Stack is pointing to NULL.\n");
		#endif
		return STACK_NULL;
	}
	else{
		return st->stack_pointer == STACK_MAX_SIZE - 1 ? STACK_FULL : STACK_NOT_FULL;
	}
}


// Abstracted Functions
return_status_t stackInit(stack_t *st){
	// Check if st is not equal to NULL
	if(!st){
		#ifdef STACK_DEBUG
		printf("Stack is pointing to NULL.\n");
		#endif
		return R_NOK;
	}
	else{
		st->stack_pointer = -1;
		#ifdef STACK_DEBUG
		printf("Stack is Intialized.\n");
		#endif
		return R_OK;
	}
}

return_status_t stackPush(stack_t *st, uint32 value){
	if(!st){
		#ifdef STACK_DEBUG
		printf("Stack is pointing to NULL.\n");
		#endif
		return R_NOK;
	}
	else if(stackIsFull(st) == STACK_FULL){
		#ifdef STACK_DEBUG
		printf("Stack is already FULL, can't push any data.\n");
		#endif
		return R_NOK;
	}
	else{
		st->stack_pointer++;
		st->data[st->stack_pointer] = value;
		#ifdef STACK_DEBUG
		printf("%d is pushed to the stack.\n", value);
		#endif
		return R_OK;
	}
}

return_status_t stackPop(stack_t *st, uint32 *value){
	if(!st){
		#ifdef STACK_DEBUG
		printf("Stack is pointing to NULL.\n");
		#endif
		return R_NOK;
	}
	else if(!value){
		#ifdef STACK_DEBUG
		printf("value is pointing to NULL.\n");
		#endif
		return R_NOK;
	}
	else if(stackIsEmpty(st) == STACK_EMPTY){
		#ifdef STACK_DEBUG
		printf("Stack is already EMPTY, can't pop any data.\n");
		#endif
		return R_NOK;
	}
	else{
		*value = st->data[st->stack_pointer];
		st->stack_pointer--;
		#ifdef STACK_DEBUG
		printf("%d is popped from the stack.\n", *value);
		#endif
		return R_OK;
	}
}

return_status_t stackTop(stack_t *st, uint32 *value){
	if(!st){
		#ifdef STACK_DEBUG
		printf("Stack is pointing to NULL.\n");
		#endif
		return R_NOK;
	}
	else if(!value){
		#ifdef STACK_DEBUG
		printf("value is pointing to NULL.\n");
		#endif
		return R_NOK;
	}
	else if(stackIsEmpty(st) == STACK_EMPTY){
		#ifdef STACK_DEBUG
		printf("Stack is already EMPTY, there's no stack top.\n");
		#endif
		return R_NOK;
	}
	else{
		*value = st->data[st->stack_pointer];
		#ifdef STACK_DEBUG
		printf("%d is the stack top.\n", *value);
		#endif
		return R_OK;
	}
}

return_status_t stackDisplay(stack_t *st){
	if(!st){
		#ifdef STACK_DEBUG
		printf("Stack is pointing to NULL.\n");
		#endif
		return R_NOK;
	}
	else if(stackIsEmpty(st) == STACK_EMPTY){
		#ifdef STACK_DEBUG
		printf("Stack is already EMPTY, there's no stack data.\n");
		#endif
		return R_NOK;
	}
	else{
		printf("=======LIFO print=======\n");
		for(int i = st->stack_pointer ; i >= 0; i--)
		{
			printf("\t%d\n", st->data[i]);
		}
		printf("========================\n");
		return R_OK;
	}
}

return_status_t stackSize(stack_t *st, uint32 *size){
	if(!st){
		#ifdef STACK_DEBUG
		printf("Stack is pointing to NULL.\n");
		#endif
		return R_NOK;
	}
	else{
		*size = st->stack_pointer + 1;
		#ifdef STACK_DEBUG
		printf("Stack size =  %d.\n", *size);
		#endif
		return R_OK;
	}
}
