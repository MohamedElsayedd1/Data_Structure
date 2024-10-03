/*
 * DoubleLinkedList.c
 *
 *  Created on: Oct 2, 2024
 *      Author: Mohamed Elsayed
 */

#include "DoubleLinkedList.h"

int GetLinkedListLength(node_t *head){
	// Check if the list is empty
	if (head == NULL) {
		printf("The list is empty, cannot get length %u.\n");
		return 0;
	}
	else{
		int counter = 0;
		node_t *temp = head;
		while(temp){
			temp = temp->next;
			counter++;
		}
		return counter;
	}
}

void AddNodeAtBeginning(node_t **head, uint32 data){
	node_t *newNode = (node_t *)malloc(sizeof(node_t));
	if(!newNode){
		printf("Memory Allocation Failed!!\n");
		return;
	}
	else{
		newNode->data = data;
		if(*head == NULL){
			newNode->next = *head;
			newNode->prev = *head;
			*head = newNode;
		}
		else{
			// Make newNode point to the current head
			newNode->next = *head;
			newNode->prev = NULL;
			// Update the current head's prev pointer to newNode
			(*head)->prev = newNode;
			// Make newNode the new head
			*head = newNode;
		}
	}
}

void AddNodeAtEnd(node_t **head, uint32 data){
	node_t *newNode = (node_t *)malloc(sizeof(node_t));
	if(!newNode){
		printf("Memory Allocation Failed!!\n");
		return;
	}
	else{
		newNode->data = data;
		if(head == NULL){
			newNode->next = *head;
			newNode->prev = *head;
			*head = newNode;
		}
		else{
			node_t *temp = *head;
			while(temp->next != NULL){
				temp = temp->next;
			}
			temp->next = newNode;
			newNode->prev = temp;
			newNode->next = NULL;
		}
	}
}

void AddNodeAfter(node_t *head, uint32 data, uint32 NodePosition){
	node_t *newNode = (node_t *)malloc(sizeof(node_t));
	// Check if the list is empty
	if (head == NULL) {
		printf("The list is empty, cannot insert after position %u.\n", NodePosition);
		return;
	}
	if(!newNode){
		printf("Memory Allocation Failed!!\n");
		return;
	}
	else{
		// Check if NodePosition is valid
		if (NodePosition > GetLinkedListLength(head) || NodePosition <= 0) {
			printf("NodePosition %u is out of bounds.\n", NodePosition);
			free(newNode); // Free the memory if insertion is not possible
			return;
		}
		newNode->data = data;
		int NodeCounter = 1;
		node_t *temp = head;
		while(NodeCounter < NodePosition){
			temp = temp->next;
			NodeCounter++;
		}
		newNode->next = temp->next;
		newNode->prev = temp;
		if (temp->next != NULL) {
			temp->next->prev = newNode;
		}
		temp->next = newNode;
	}
}

void AddNodeBefore(node_t **head, uint32 data, uint32 NodePosition){
	node_t *newNode = (node_t *)malloc(sizeof(node_t));
	// Check if the list is empty
	if (*head == NULL) {
		printf("The list is empty, cannot insert after position %u.\n", NodePosition);
		return;
	}
	if(!newNode){
		printf("Memory Allocation Failed!!\n");
		return;
	}
	else{
		// Check if NodePosition is valid
		if (NodePosition > GetLinkedListLength(*head) || NodePosition <= 0) {
			printf("NodePosition %u is out of bounds.\n", NodePosition);
			free(newNode); // Free the memory if insertion is not possible
			return;
		}
		else if(NodePosition == 1){
			free(newNode);
			AddNodeAtBeginning(head, data);
			return;
		}
		else{
			newNode->data = data;
			int NodeCounter = 1;
			node_t *temp = *head;
			while(NodeCounter < NodePosition - 1){
				temp = temp->next;
				NodeCounter++;
			}
			newNode->next = temp->next;
			newNode->prev = temp;
			if (temp->next != NULL) {
				temp->next->prev = newNode;
			}
			temp->next = newNode;
		}
	}
}

void DeleteNodeAtBeginning(node_t **head){
	node_t *temp = *head;
	if(!temp){
		printf("Double Linked List Is Empty, Can't Delete Any Elements !!\n");
		return;
	}
	else{
		*head = (*head)->next;
		free(temp);
		temp = NULL;
		if(*head != NULL)
			(*head)->prev = NULL;
	}
}

void DeleteNodeAtEnd(node_t **head){{
	node_t *temp = *head;
	if(!temp){
		printf("Double Linked List Is Empty, Can't Delete Any Elements !!\n");
		return;
	}
	else{
		// If the list has only one node
		if (temp->next == NULL) {
			free(temp);
			*head = NULL; // The list is now empty
		}
		else {
			// Traverse to the last node
			while (temp->next != NULL) {
				temp = temp->next;
			}

			// Unlink the last node
			temp->prev->next = NULL;
			free(temp);
			temp = NULL;
		}}
	}
}

void DeleteNodeAtPosition(node_t **head, int NodePosition){
	node_t *temp = *head;
	if(!temp){
		printf("Double Linked List Is Empty, Can't Delete Any Elements !!\n");
		return;
	}
	else{
		int NodeLength = GetLinkedListLength(*head);
		// Check if NodePosition is valid
		if (NodePosition > NodeLength || NodePosition <= 0) {
			printf("NodePosition %u is out of bounds.\n", NodePosition);
			return;
		}
		else if(NodePosition == 1){
			DeleteNodeAtBeginning(head);
			return;
		}
		else if(NodePosition == NodeLength){
			DeleteNodeAtEnd(head);
			return;
		}
		// Traverse to the node at NodePosition
		int NodeCounter = 1;
		while (NodeCounter < NodePosition) {
			temp = temp->next;
			NodeCounter++;
		}

		// Unlink and delete the node
		temp->prev->next = temp->next;
		temp->next->prev = temp->prev;

		free(temp);
		temp = NULL;
	}
}

void DisplayLinkedListForward(node_t *head){
	node_t *temp = head;
	if(!temp){
		printf("Double Linked List Is Empty, Can't Display Any Elements !!\n");
		return;
	}
	else{
		printf("List (head to tail): ");
		while(temp){
			printf("%u -> ", temp->data);
			temp = temp->next;
		}
		printf("NULL\n");
	}
}

void DisplayLinkedListBackward(node_t *head) {
    if (head == NULL) {
        printf("The list is empty!\n");
        return;
    }

    // Move to the last node
    node_t *temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    // Traverse backward and print nodes
    printf("List (tail to head): ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->prev;
    }
    printf("\n");
}


void DeleteLinkedList(node_t **head){
	if(!head){
		printf("Double Linked List Is Empty, Can't Delete Any Elements !!\n");
		return;
	}
	else{
		node_t *curr = *head;
		node_t *next;
		while(curr){
			next = curr->next;
			free(curr);
			curr = next;
		}
		*head = NULL;
	}
}
