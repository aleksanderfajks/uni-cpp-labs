#include <stdio.h>
#include <stdlib.h>
#include "removeByIndex.h"

void removeByIndex(Node_t **root, unsigned int index) {
    if (*root == NULL){
		printf("Lista jest pusta. \n");
		return;
	}
	
    if (index == 0) {
        Node_t *toDelete = *root;
        *root = (*root)->tail;
        free(toDelete);
        return;
    }
    
    Node_t *prev = *root;
    for (unsigned int i=0; i<index-1; i++) {
        if (prev->tail == NULL) {
			printf("Za duzy indeks. \n");
            return;
        }
        prev = prev->tail;
    }
    
    Node_t *toDelete = prev->tail;
    if (toDelete == NULL) {
		printf("Indeks poza zakresem. \n");
        return;
    }   
    prev->tail = toDelete->tail;
    free(toDelete);
}

Node_t * createNode(int head, Node_t * tail){
	Node_t * node = (Node_t *) malloc(sizeof(*node));
	node->head = head;
	node->tail = tail;
	return node;
}

void pushBack(Node_t ** root, int value){
	if (*root == NULL) {
        *root = createNode(value, NULL);
        return;
    }

    Node_t *currentNode = *root;
    while (currentNode->tail != NULL)
        currentNode = currentNode->tail;
    currentNode->tail = createNode(value, NULL);
}

void printList(Node_t *root){
	Node_t * currentNode=root;
	if(currentNode!=NULL){
		while (currentNode->tail !=NULL){
			printf ("%d ", currentNode->head);
			currentNode=currentNode->tail;
		}
		printf ("%d \n", currentNode->head);
	} else{
		printf("No list to show. \n");
	}
}

void deleteList(Node_t **root){
	Node_t *current = *root;
	while (current !=NULL){
		Node_t *next = current->tail;
		free(current);
		current=next;
	}
	*root=NULL;
}