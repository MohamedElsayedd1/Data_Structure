/*
 * LinkeList.c
 *
 *  Created on: Sep 30, 2024
 *      Author: Dubai Store
 */

#include "LinkedList.h"

linkedlist_status_t InsertNodeAtBeginning(node_t **top, void *item){
	node_t *newNode = (node_t *)malloc(sizeof(node_t));
	if(!newNode){
		return LINKED_LIST_NULL;
	}
	else{
		newNode->data = item;
		newNode->next = *top;
		*top = newNode;
		return LINKED_LIST_OK;
	}
}

linkedlist_status_t InsertNodeAtEnd(node_t **top, void *item){
	node_t *newNode = (node_t *)malloc(sizeof(node_t));
	if(!newNode){
		return LINKED_LIST_NULL;
	}
	newNode->data = item;
	newNode->next = NULL;
	// If the list is empty, the new node becomes the head
	if (*top == NULL) {
		*top = newNode;
	} else {
		// Traverse to the end of the list
		node_t *tempNode = *top;
		while (tempNode->next != NULL) {
			tempNode = tempNode->next;
		}
		// Link the new node at the end
		tempNode->next = newNode;
	}

	return LINKED_LIST_OK;
}

linkedlist_status_t InsertNodeAfter(node_t **top, uint32 NodePosition, void *item){
	node_t *newNode = (node_t *)malloc(sizeof(node_t));
	uint32 NodeLength = GetLinkedListLength(*top);
	if(!newNode){
		return LINKED_LIST_NULL;
	}
	newNode->data = item;
	if(NodePosition > NodeLength || NodePosition <= 0){
		printf("Invalid Node Position -> List has ( %i ) Nodes \n", NodeLength);
		free(newNode); // Avoid memory leak if position is invalid
		return LINKED_LIST_NOK;
	}
	else{
		uint32 NodeCounter = 1;
		node_t *temp = *top;
		while(NodeCounter < NodePosition){
			temp = temp->next;
			NodeCounter++;
		}
		newNode->next = temp->next;
		temp->next = newNode;
		return LINKED_LIST_OK;
	}
}

linkedlist_status_t DeleteNodeAtBeginning(node_t **top){
	node_t *tempNode = *top;
	if(*top == NULL){
		printf("List is Empty , nothing to be deleted !! \n");
		return LINKED_LIST_NOK;
	}
	else{
		*top = tempNode->next;
		tempNode->next = NULL;
		free(tempNode);
		return LINKED_LIST_OK;
	}
}

linkedlist_status_t DeleteNode(node_t **top, uint32 NodePosition){
	uint32 NodeLength = GetLinkedListLength(*top);
	node_t *NodeListCounter = *top;
	node_t *NextNode = *top;
	uint32 NodeCounter = 1;
	if(*top == NULL){
		printf("List is Empty , nothing to be deleted !! \n");
		return LINKED_LIST_NOK;
	}
	else if(NodePosition < NodeLength){
		if(NodePosition == 1){
			return DeleteNodeAtBeginning(top);
		}
		else{
			while(NodeCounter < NodePosition - 1){
				NodeListCounter = NodeListCounter->next;
				NodeCounter++;
			}
			NextNode = NodeListCounter->next; // NULL
			NodeListCounter->next = NextNode->next;
			NextNode->next = NULL;
			free(NextNode);
		}
		return LINKED_LIST_OK;
	}
}

uint32 GetLinkedListLength(node_t *top){
	uint32 NodeCounter = 0;   // Initialize the counter to 0
	node_t *tempNode = top;  // Start from the head

	while (tempNode != NULL) {
		NodeCounter++;         // Count each node
		tempNode = tempNode->next;  // Move to the next node
	}
	return NodeCounter;
}

void PrintLinkedList(node_t *top) {
    node_t *temp = top;
    printf("Linked List:\n");
    while (temp != NULL) {
        printf("Node data : %d\n", *(uint32 *)temp->data);
        temp = temp->next;
    }
}

linkedlist_status_t ReverseLinkedList(node_t **top){
	if(*top == NULL){
		printf("List is Empty , nothing to be deleted !! \n");
		return LINKED_LIST_NOK;
	}
	else{
		node_t *curr = *top;
		node_t *prev = NULL;
		node_t *next = NULL;
		while(curr != NULL){
			next = curr->next;
			curr->next = prev;
			prev = curr;
			curr = next;
		}
		*top = prev;
		return LINKED_LIST_OK;
	}
}

linkedlist_status_t Swap2Nodes(node_t **top, uint32 data1, uint32 data2) {
    if (*top == NULL) {
        printf("List is Empty, nothing to be swapped!\n");
        return LINKED_LIST_NOK;
    } else {
        if (data1 == data2) {
            printf("2 Nodes have the same data, no need to swap.\n");
            return LINKED_LIST_OK;
        }

        node_t *prevX = NULL, *currX = *top;
        node_t *prevY = NULL, *currY = *top;

        // Search for 2 nodes
        while (currX && *(uint32*)currX->data != data1) {
            prevX = currX;
            currX = currX->next;
        }
        while (currY && *(uint32*)currY->data != data2) {
            prevY = currY;
            currY = currY->next;
        }

        // If either node is not found
        if (!currX || !currY) {
            printf("Couldn't find one of the nodes or both\n");
            return LINKED_LIST_NOK;
        }

        // Swap the nodes
        if (prevX) {
            prevX->next = currY;
        } else {
            *top = currY;
        }
        if (prevY) {
            prevY->next = currX;
        } else {
            *top = currX;
        }

        node_t *temp = currX->next;
        currX->next = currY->next;
        currY->next = temp;

        return LINKED_LIST_OK;
    }
}

// Sort nodes function (previously provided)
linkedlist_status_t SortNodes(node_t **top) {
    if (*top == NULL || (*top)->next == NULL) {
        printf("List is Empty or it has only one node, can't be sorted!\n");
        return LINKED_LIST_NOK;
    } else {
        node_t *i = *top, *j = *top;
        linkedlist_status_t status = LINKED_LIST_OK;
        for (i = *top; i != NULL; i = i->next) {
            for (j = i->next; j != NULL; j = j->next) {
                if (*(uint32*)j->data < *(uint32*)i->data) {
                    // Swap two nodes
                    status &= Swap2Nodes(top, *(uint32*)i->data, *(uint32*)j->data);
                }
            }
        }
        return status;
    }
}

linkedlist_status_t GetMiddleNode(node_t *top, node_t **middleNode){
	if(top == NULL){
		printf("List is Empty , nothing to be deleted !! \n");
		return LINKED_LIST_NOK;
	}
	else{
		node_t *pFast = top, *pSlow = top;
		while(pFast && pFast->next){
			pSlow = pSlow->next;
			pFast = pFast->next->next;
		}
		*middleNode = pSlow;
		return LINKED_LIST_OK;
	}
}

linkedlist_status_t GetNthNodeFromEnd(node_t *top, uint32 nodePosition, node_t **pos){
	if(top == NULL){
		printf("List is Empty , nothing to be deleted !! \n");
		return LINKED_LIST_NOK;
	}
	else{
		if(nodePosition > GetLinkedListLength(top) || nodePosition <= 0){
			printf("The Node Position Is Out Of Boundries !! \n");
			return LINKED_LIST_NOK;
		}
		else{
			int counter = 1;
			node_t *pFast = top;
			node_t *pSlow = top;

			while(counter <= nodePosition-1){
				pFast = pFast->next;
				counter++;
			}

			while(pFast->next != NULL){
				pSlow = pSlow->next;
				pFast = pFast->next;
			}

			*pos = pSlow;
			return LINKED_LIST_OK;
		}
	}
}

int DetectLoopInNodes(node_t *top){
	if(top == NULL){
		printf("List is Empty !! \n");
		return -1;
	}
	else{
		node_t *fast = top;
		node_t *slow = top;
		while (slow && fast && fast->next) {
			slow = slow->next;         // Move slow pointer by 1
			fast = fast->next->next;   // Move fast pointer by 2

			// If slow and fast meet at the same point, there is a loop
			if (slow == fast) {
				return 1;  // Loop found
			}
		}

		return 0;  // No loop found
	}
}
