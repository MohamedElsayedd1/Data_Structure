/*
 * DynamicStack.c
 *
 *  Created on: Sep 27, 2024
 *      Author: Mohamed Elsayed
 */

#include "DynamicStack.h"

static stack_status_t stackIsFull(stack_t *st){
	if(!st){
		return STACK_NULL;
	}
	else{

		return st->count >= st->size ? STACK_FULL : STACK_NOT_FULL;
	}


}

static stack_status_t stackIsEMPTY(stack_t *st){
	if(!st){
		return STACK_NULL;
	}
	else{

		return st->count == 0 ? STACK_EMPTY : STACK_NOT_EMPTY;
	}


}

stack_status_t stackInit(stack_t *st, uint32 maxSize){
	if(!st){
		return STACK_NULL;
	}
	else{
		st->size = maxSize;
		st->count = 0;
		st->top = -1;
		st->stackArray = (void **) calloc(st->size, sizeof(void *));
		if(!st->stackArray){
			return STACK_MEM_ERROR;
		}
		return STACK_OK;
	}
}

stack_status_t stackDestroy(stack_t *st){
	if(!st){
		return STACK_NULL;
	}
	else{
		// reset stack properties
	    st->size = 0;
	    st->count = 0;
	    st->top = -1;
		// Free individual elements in the stack, if applicable
		if(st->stackArray){
			for(int i = 0; i < st->size; i++){
				free(st->stackArray[i]);
			}
			// Free the array itself
			free(st->stackArray);
			st->stackArray = NULL;
		}
		return STACK_OK;
	}
}

stack_status_t stackPush(stack_t *st, void *element){
	if(!st || !element){
		return STACK_NULL;
	}
	else{
		// Can push elements if stack is not full
		if(stackIsFull(st) == STACK_NOT_FULL){
			// increment the stack top first to point to the next element
			st->top++;
			// write the new data in the stack
			st->stackArray[st->top] = (void *)element;
			// increment number of stack elements
			st->count++;
			return STACK_OK;
		}
		else if(stackIsFull(st) == STACK_FULL){
			return STACK_FULL;
		}
	}
}

stack_status_t stackPop(stack_t *st, void **element){
	if(!st){
		return STACK_NULL;
	}
	else{
		// Can push elements if stack is not full
		if(stackIsEMPTY(st) == STACK_NOT_EMPTY){
			// read the last data added to the stack
			*element = (void *)st->stackArray[st->top];
			// decrement the stack top first to point to the next element
			st->top--;
			// decrement number of stack elements
			st->count--;
			return STACK_OK;
		}
		else if(stackIsEMPTY(st) == STACK_EMPTY){
			return STACK_EMPTY;
		}
	}
}

stack_status_t stackTop(stack_t *st, void **element){
	if(!st){
		return STACK_NULL;
	}
	else{
		// Can push elements if stack is not full
		if(stackIsEMPTY(st) == STACK_NOT_EMPTY){
			// read the last data added to the stack
			*element = (void *)st->stackArray[st->top];
			return STACK_OK;
		}
		else if(stackIsEMPTY(st) == STACK_EMPTY){
			return STACK_EMPTY;
		}
	}
}
