/*
 * main.c
 *
 *  Created on: Sep 30, 2024
 *      Author: Mohamed Elsayed
 */

#include "DoubleLinkedList.h"



int main(){
	node_t *head = NULL;  // Initialize the head of the list to NULL

	// Test adding nodes at the beginning
	AddNodeAtBeginning(&head, 10);
	AddNodeAtBeginning(&head, 20);
	AddNodeAtBeginning(&head, 30);
	AddNodeAtBeginning(&head, 15);
	AddNodeAtBeginning(&head, 5);

	// Print the list after additions
	DisplayLinkedListForward(head);

	// Test adding nodes at the end
	AddNodeAtEnd(&head, 40);
	AddNodeAtEnd(&head, 35);
	AddNodeAtEnd(&head, 12);

	// Print the list after additions
	DisplayLinkedListForward(head);

	// Get the length of the linked list
	int length = GetLinkedListLength(head);
	printf("Length of the list: %d\n", length);

	// Insert node after position 2 (i.e., after node with data 20)
	AddNodeAfter(head, 25, 2);

	// Print the list after additions
	DisplayLinkedListForward(head);

	// Insert node after position 9 (i.e., after node with data 44)
	AddNodeAfter(head, 44, 9);

	// Print the list after additions
	DisplayLinkedListForward(head);

	// Add a node before position 4
	AddNodeBefore(&head, 70, 4);
	printf("List after adding 70 before position 4:\n");
	DisplayLinkedListForward(head);

	// Add a node before position 1
	AddNodeBefore(&head, 80, 1);
	printf("List after adding 80 before position 1:\n");
	DisplayLinkedListForward(head);

	// Delete the first node
	DeleteNodeAtBeginning(&head);
	printf("List after deleting the first node:\n");
	DisplayLinkedListForward(head);

	// Delete the first node again
	DeleteNodeAtBeginning(&head);
	printf("List after deleting the first node again:\n");
	DisplayLinkedListForward(head);

	// Delete the first node again
	DeleteNodeAtBeginning(&head);
	printf("List after deleting the last node:\n");
	DisplayLinkedListForward(head);

	// Delete the last node
	DeleteNodeAtEnd(&head);
	printf("List after deleting the last node:\n");
	DisplayLinkedListForward(head);

	// Delete the last node again
	DeleteNodeAtEnd(&head);
	printf("List after deleting the last node again:\n");
	DisplayLinkedListForward(head);

	// Delete the last remaining node
	DeleteNodeAtEnd(&head);
	printf("List after deleting the last node:\n");
	DisplayLinkedListForward(head);

	// Delete node at position 3
	DeleteNodeAtPosition(&head, 3);
	printf("List after deleting node at position 3:\n");
	DisplayLinkedListForward(head);

	// Delete node at position 1 (first node)
	DeleteNodeAtPosition(&head, 1);
	printf("List after deleting node at position 1:\n");
	DisplayLinkedListForward(head);

	// Delete node at position 2 (last node)
	DeleteNodeAtPosition(&head, 2);
	printf("List after deleting node at position 2:\n");
	DisplayLinkedListForward(head);

	// Print the list in reverse
	DisplayLinkedListBackward(head);

	// Free the allocated memory
	DeleteLinkedList(&head);

	// Print the list after additions
	DisplayLinkedListForward(head);


	return 0;
}

