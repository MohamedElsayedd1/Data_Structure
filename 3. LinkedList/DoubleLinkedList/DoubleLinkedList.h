/*
 * DoubleLinkedList.h
 *
 *  Created on: Oct 2, 2024
 *      Author: Mohamed Elsayed
 */

#ifndef DOUBLELINKEDLIST_H_
#define DOUBLELINKEDLIST_H_

#include <stdio.h>
#include <stdlib.h>
#include "Platform_Types.h"


typedef struct node{
	uint32 data;
	struct node *prev;
	struct node *next;
}node_t;

void AddNodeAtBeginning(node_t **head, uint32 data);
void AddNodeAtEnd(node_t **head, uint32 data);
void AddNodeAfter(node_t *head, uint32 data, uint32 NodePosition);
void AddNodeBefore(node_t **head, uint32 data, uint32 NodePosition);
void DeleteNodeAtBeginning(node_t **head);
void DeleteNodeAtEnd(node_t **head);
void DeleteNodeAtPosition(node_t **head, int NodePosition);
void DisplayLinkedListForward(node_t *head);
void DisplayLinkedListBackward(node_t *head);
void DeleteLinkedList(node_t **head);
int GetLinkedListLength(node_t *head);

#endif /* DOUBLELINKEDLIST_H_ */
