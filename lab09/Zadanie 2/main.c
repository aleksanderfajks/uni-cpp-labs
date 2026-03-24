//Zadanie 2

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int head ;
	struct Node * tail ;
} Node_t ;

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

void removeByIndex(Node_t **root, unsigned int index) {
    if (*root == NULL){
		printf("Lista jest pusta. \n");
		return;
	}
	
    if (index == 0) {
        Node_t *delete = *root;
        *root = (*root)->tail;
        free(delete);
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
    
    Node_t *delete = prev->tail;
    if (delete == NULL) {
		printf("Indeks poza zakresem. \n");
        return;
    }
    prev->tail = delete->tail;
    free(delete);
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

int main(){
	Node_t *root = NULL;
    printf("Test 1: pusta lista, usuwanie index 0:\n");
    removeByIndex(&root, 0);
    printList(root);

    printf("Test 2: pusta lista, usuwanie index 5:\n");
    removeByIndex(&root, 5);
    printList(root);

    printf("Test 3: jednoelementowa lista, usuwanie index 0:\n");
    pushBack(&root, 42);
    printList(root);
    removeByIndex(&root, 0);
    printList(root);

    printf("Test 4: jednoelementowa lista, usuwanie index 1:\n");
    pushBack(&root, 444);
    printList(root);
    removeByIndex(&root, 1);
    printList(root);

    int values[] = {1,2,3,4,5};
    unsigned int n = 5;
    for (unsigned int i = 0; i < n; ++i) {
		pushBack(&root, values[i]);
	}
	printf("Lista n-elementowa: "); 
	printList(root);

    printf("Usuwanie index 0:\n");
    removeByIndex(&root, 0);
    printList(root);

    printf("Usuwanie index 1:\n");
    removeByIndex(&root, 1);
    printList(root);

    printf("Usuwanie index n+1 (6):\n");
    removeByIndex(&root, n+1);
    printList(root);

    deleteList(&root);
    return 0;
}