/*
 * Stack.h
 *
 *  Created on: Sep 26, 2024
 *      Author: Dubai Store
 */

#ifndef STACK_H_
#define STACK_H_

#include <stdio.h>
#include "Platform_Types.h"

#define STACK_MAX_SIZE 5
#define STACK_DEBUG

typedef struct{
	uint32 data[5];
	uint32 stack_pointer;
}stack_t;

typedef enum{
	R_NOK,
	R_OK
}return_status_t;

typedef enum{
	STACK_NULL,
	STACK_EMPTY,
	STACK_NOT_EMPTY,
	STACK_FULL,
	STACK_NOT_FULL
}stack_status_t;

/**
 * @brief Initializes the stack.
 *
 * @param st Pointer to the stack structure.
 *
 * @returnVal R_NOK if the stack pointer is NULL.
 * @returnVal R_OK if the stack is successfully initialized.
 */
return_status_t stackInit(stack_t *st);

/**
 * @brief Pushes a value onto the stack.
 *
 * @param st Pointer to the stack structure.
 * @param value The value to be pushed onto the stack.
 *
 * @returnVal R_NOK if the stack pointer is NULL, the stack is full, or another error occurs.
 * @returnVal R_OK if the value is successfully pushed.
 */
return_status_t stackPush(stack_t *st, uint32 value);

/**
 * @brief Pops a value from the stack.
 *
 * @param st Pointer to the stack structure.
 * @param value Pointer to store the popped value.
 *
 * @returnVal R_NOK if the stack pointer is NULL, the stack is empty, or the value pointer is NULL.
 * @returnVal R_OK if the value is successfully popped.
 */
return_status_t stackPop(stack_t *st, uint32 *value);

/**
 * @brief Retrieves the top value of the stack without popping it.
 *
 * @param st Pointer to the stack structure.
 * @param value Pointer to store the top value.
 *
 * @returnVal R_NOK if the stack pointer is NULL, the stack is empty, or the value pointer is NULL.
 * @returnVal R_OK if the top value is successfully retrieved.
 */
return_status_t stackTop(stack_t *st, uint32 *value);

/**
 * @brief Displays the current contents of the stack from top to bottom.
 *
 * @param st Pointer to the stack structure.
 *
 * @returnVal R_NOK if the stack pointer is NULL or the stack is empty.
 * @returnVal R_OK if the stack contents are successfully displayed.
 */
return_status_t stackDisplay(stack_t *st);

/**
 * @brief Gets the current size of the stack.
 *
 * @param st Pointer to the stack structure.
 * @param size Pointer to store the size of the stack.
 *
 * @returnVal R_NOK if the stack pointer is NULL.
 * @returnVal R_OK if the size is successfully retrieved.
 */
return_status_t stackSize(stack_t *st, uint32 *size);




#endif /* STACK_C_ */

