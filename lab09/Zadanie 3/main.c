//Zadanie 3

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node{
    int head;
    struct Node *tail;
}Node_t;

Node_t * createNode(int head, Node_t * tail){
	Node_t * node = (Node_t *) malloc(sizeof(*node));
	node->head = head;
	node->tail = tail;
	return node;
}

void push(Node_t **root, int value) {
	if (*root == NULL) {
        *root = createNode(value, NULL);
        return;
    }

    Node_t *currentNode = *root;
    while (currentNode->tail != NULL)
        currentNode = currentNode->tail;
    currentNode->tail = createNode(value, NULL);
}

bool pop(Node_t **root, int *buffer) {
    if (*root == NULL){
        return false;
	}
	
    Node_t *delete = *root;
    *buffer = delete->head;
    *root = delete->tail;
    free(delete);
    return true;
}

bool isEmpty(Node_t *root) {
    return root == NULL;
}

void printQueue(Node_t *root){
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

void deleteQueue(Node_t **root){
	Node_t *current = *root;
	while (current !=NULL){
		Node_t *next = current->tail;
		free(current);
		current=next;
	}
	*root=NULL;
}

int main() {
    Node_t *queue = NULL;
    int value;
	
	if(isEmpty(queue)){
		printf("Lista jest pusta. \n");
	} else {
		printf("Lista nie jest pusta. \n");
	}
	
	printQueue(queue);

    push(&queue, 1);
	push(&queue, 2);
	push(&queue, 3);
	push(&queue, 4);
	push(&queue, 5);

	if(isEmpty(queue)){
		printf("Lista po przesunieciu jest pusta. \n");
	} else {
		printf("Lista po przesunieciu nie jest pusta. \n");
	}
	
	printQueue(queue);

	bool result;
	result = pop (&queue, &value);
	if(result){
		printf("Popped value: %d\n", value) ;
	}
	
	printQueue(queue);
	
	if(isEmpty(queue)){
		printf("Lista jest pusta. \n");
	} else {
		printf("Lista nie jest pusta. \n");
	}

    deleteQueue(&queue);
    return 0;
}