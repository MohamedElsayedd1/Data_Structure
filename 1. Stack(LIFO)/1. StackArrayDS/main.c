/*
 * main.c
 *
 *  Created on: Sep 24, 2024
 *      Author: Mohamed Elsayed
 */

#include "Stack.h"

/**
 * @brief Main function to test stack operations such as initialization, push, pop, top, display, and size.
 *
 * @return 0 on successful execution.
 */
int main(){

	// Define a stack object
	stack_t UART_LIFO;
	return_status_t returnVal;

	/**
	 * @brief Initialize the stack.
	 * @param &UART_LIFO Pointer to the stack structure.
	 * @returnVal R_OK if the stack is successfully initialized.
	 */
	returnVal = stackInit(&UART_LIFO);

	// Push 6 values onto the stack
	for(int i = 0; i < 6; i++){
		/**
		 * @brief Push a value onto the stack.
		 * @param &UART_LIFO Pointer to the stack structure.
		 * @param i Value to be pushed onto the stack.
		 * @returnVal R_OK if the value is successfully pushed.
		 */
		returnVal = stackPush(&UART_LIFO, i);
	}

	uint32 topValue;
	/**
	 * @brief Get the top value of the stack.
	 * @param &UART_LIFO Pointer to the stack structure.
	 * @param &topValue Pointer to store the top value.
	 * @returnVal R_OK if the top value is successfully retrieved.
	 */
	returnVal = stackTop(&UART_LIFO, &topValue);

	/**
	 * @brief Display the current stack contents.
	 * @param &UART_LIFO Pointer to the stack structure.
	 * @returnVal R_OK if the stack contents are displayed.
	 */
	returnVal = stackDisplay(&UART_LIFO);

	uint32 stack_size;
	/**
	 * @brief Get the current size of the stack.
	 * @param &UART_LIFO Pointer to the stack structure.
	 * @param &stack_size Pointer to store the size of the stack.
	 * @returnVal R_OK if the stack size is successfully retrieved.
	 */
	returnVal = stackSize(&UART_LIFO, &stack_size);

	uint32 popValue;
	// Pop 6 values from the stack
	for(int i = 0; i < 6; i++){
		/**
		 * @brief Pop a value from the stack.
		 * @param &UART_LIFO Pointer to the stack structure.
		 * @param &popValue Pointer to store the popped value.
		 * @returnVal R_OK if the value is successfully popped.
		 */
		returnVal = stackPop(&UART_LIFO, &popValue);
	}

	return 0;
}
