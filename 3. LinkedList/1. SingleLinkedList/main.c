/*
 * main.c
 *
 *  Created on: Sep 30, 2024
 *      Author: Dubai Store
 */

#include "LinkedList.h"

node_t *head = NULL;

int main(){
	linkedlist_status_t status;
	uint32 data[] = {11, 22, 33, 44, 55};

	// Inserting nodes at the beginning of the linked list
	for (int i = 0; i < 5; i++) {
		status = InsertNodeAtBeginning(&head, &data[i]);

		if (status == LINKED_LIST_OK) {
			printf("Inserted %d successfully.\n", data[i]);
		} else {
			printf("Failed to insert %d.\n", data[i]);
		}
	}

	// Printing the list
	printf("\n");
	PrintLinkedList(head);
	printf("\n");


	// Insert a node after the second position
	uint32 new_data = 99;
	status = InsertNodeAfter(&head, 1, &new_data);
	if (status == LINKED_LIST_OK) {
		printf("Inserted 99 successfully after position 1.\n");
	} else {
		printf("Failed to insert at position 2.\n");
	}

	// Get and print the length of the list
	uint32 length = GetLinkedListLength(head);
	printf("Linked List Length: %d\n", length);


	// Printing the list
	printf("\n");
	PrintLinkedList(head);
	printf("\n");

	// Delete a node at the beginning
	status = DeleteNodeAtBeginning(&head);
	if (status == LINKED_LIST_OK) {
		printf("Successfully deleted the node at the beginning.\n");
	} else {
		printf("Failed to delete the node at the beginning.\n");
	}

	// Printing the list
	printf("\n");
	PrintLinkedList(head);
	printf("\n");

	// Delete the 3rd node
	status = DeleteNode(&head, 3);
	if (status == LINKED_LIST_OK) {
		printf("Node 3 successfully deleted.\n");
	} else {
		printf("Failed to delete node 3.\n");
	}

	// Print the list after deletion
	printf("Linked List after deletion:\n");

	// Printing the list
	printf("\n");
	PrintLinkedList(head);
	printf("\n");

	// Reverse the linked list
	if (ReverseLinkedList(&head) == LINKED_LIST_OK) {
		printf("\nReversed Linked List:\n");
		PrintLinkedList(head);
	} else {
		printf("\nError: Failed to reverse the linked list.\n");
	}

	// Swap nodes with data 11 and 44
	if (Swap2Nodes(&head, 11, 44) == LINKED_LIST_OK) {
		printf("\nLinked List after swapping 11 and 44:\n");
		PrintLinkedList(head);
	} else {
		printf("\nError: Failed to swap nodes.\n");
	}

	// Find the middle node
	node_t *middleNode = NULL;
	status = GetMiddleNode(head, &middleNode);

	// Print the result
	if (status == LINKED_LIST_OK && middleNode != NULL) {
		printf("\nMiddle Node data: %d\n", *(uint32*)middleNode->data);
	} else {
		printf("\nFailed to find the middle node.\n");
	}

	// Find the 2nd node from the end
	node_t *nthNode = NULL;
	uint32 positionFromEnd = 2;
	status = GetNthNodeFromEnd(head, positionFromEnd, &nthNode);

	// Print the result
	if (status == LINKED_LIST_OK && nthNode != NULL) {
		printf("\n%dth Node from the end is: %d\n", positionFromEnd, *(uint32*)nthNode->data);
	} else {
		printf("\nFailed to find the node from the end.\n");
	}

	// Test case 1: List without a loop
	printf("Test Case 1: No loop\n");
	PrintLinkedList(head);
	int hasLoop = DetectLoopInNodes(head);
	if (hasLoop == 1) {
		printf("Loop detected!\n");
	} else if (hasLoop == 0) {
		printf("No loop detected.\n");
	}

	// Test case 2: Create a loop in the list (55 -> 33)
	printf("\nTest Case 2: Creating a loop\n");
	head->next->next->next = head->next->next; // Create a loop (55 -> 33)
	hasLoop = DetectLoopInNodes(head);
	if (hasLoop == 1) {
		printf("Loop detected!\n");
	} else if (hasLoop == 0) {
		printf("No loop detected.\n");
	}


	return 0;
}

