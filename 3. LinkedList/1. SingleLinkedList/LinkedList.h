/*
 * LinkedList.h
 *
 *  Created on: Sep 30, 2024
 *      Author: Dubai Store
 */

#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

#include <stdio.h>
#include <stdlib.h>
#include "Platform_Types.h"

typedef struct node{
	void *data;
	struct node *next;
}node_t;

typedef enum{
	LINKED_LIST_OK,
	LINKED_LIST_NOK,
	LINKED_LIST_NULL
}linkedlist_status_t;

linkedlist_status_t InsertNodeAtBeginning(node_t **top, void *item);
linkedlist_status_t InsertNodeAtEnd(node_t **top, void *item);
linkedlist_status_t InsertNodeAfter(node_t **top, uint32 NodePosition, void *item);
linkedlist_status_t DeleteNodeAtBeginning(node_t **top);
linkedlist_status_t DeleteNode(node_t **top, uint32 NodePosition);
uint32 GetLinkedListLength(node_t *top);
void PrintLinkedList(node_t *top);
linkedlist_status_t ReverseLinkedList(node_t **top);
linkedlist_status_t Swap2Nodes(node_t **top, uint32 data1, uint32 data2);
linkedlist_status_t SortNodes(node_t **top);
linkedlist_status_t GetMiddleNode(node_t *top, node_t **middleNode);
linkedlist_status_t GetNthNodeFromEnd(node_t *top, uint32 nodePosition, node_t **pos);
int DetectLoopInNodes(node_t *top);

#endif /* LINKEDLIST_H_ */
