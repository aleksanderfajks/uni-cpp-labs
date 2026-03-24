#pragma once

typedef struct Node {
	int head ;
	struct Node * tail ;
} Node_t ;

void removeByIndex(Node_t **root, unsigned int index);
Node_t * createNode(int head, Node_t * tail);
void pushBack(Node_t ** root, int value);
void printList(Node_t *root);
void deleteList(Node_t **root);