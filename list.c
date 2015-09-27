#include <stdio.h>
#include <stdlib.h>

#include "list.h"

// ----- Node Functions ------

/*
	Method name: createNode
	Description: Create a node with an id number
	Return: Node pointer
*/
Node *createNode(int id) {
	Node *node = malloc(sizeof(Node));
	
	node->id = id;
	node->prev = NULL;
	node->next = NULL;

	return node;
}

void deleteNode(Node *node){
	free(node);
	node = NULL;
}

void printNode(Node *node){
	if(!node) return;
	printf("%d ", node->id);
}


List* goOnList(List *list) {
	list->currentNode = list->currentNode->next;
	return list;
}

List* backOnList(List *list) {
	list->currentNode = list->currentNode->prev;
	return list;
}

void* canGoOnList(List *list){
	return list->currentNode->next;
}

void* canBackOnList(List *list){
	return list->currentNode->prev;
}

// ----- List Functions ------

List* addNodeOnList(List *list, Node *node); // prototype function

/*
	Method name: createList
	Description: Create an empty list
	Return: A pointer to a list
*/
List* createList(){

	List *list = malloc(sizeof(List));
	
	list->start = NULL;
	list->end = NULL;
	list->size = 0;

	return list;
}

/*
	Method name: createListWithArray
	Parameters: Array, an array of numbers. Size, the size of the array of numbers
	Description: Create list from array data
	Return: A pointer to a list
*/
List* createListWithArray(int *array, int size){

	List *list = createList();

	for(int i = 0; i < size; i++) {
		Node *node = createNode(array[i]);
		addNodeOnList(list, node);	
	}

	return list;
}


int emptyList(List *list){
	return !list->size;
}


/*
	Method name: deleteList
	Description: Goes through all the elements deallocating them.
	Return: void
*/
void deleteList(List *list) { 
	Node *currentNode = list->start;
	Node *auxNode;

	while(currentNode) {
		auxNode = currentNode->next; // Save a pointer to the next element of the list
		deleteNode(currentNode);
		list->size--;
		currentNode = auxNode; // Recover the element previously saved
	}
}


/*
	Method name: nodeNOnList
	Description: Get the node on the n position on the list
	Return: Node pointer
*/
Node* nodeNOnList(List *list, int index) { 

	if(index > list->size - 1) return NULL;
	if(index < 0) return NULL;

	list->currentNode = list->start;
	Node *auxNode;

	while(list->currentNode->index != index) {
		goOnList(list);
	}

	return list->currentNode;
}


/*
	Method name: printList
	Description: Goes through all the elements printing them.
	Return: void
*/
int printList(List *list) { 
	if(emptyList(list)){
		printf("\nEmpty List\n");
		return 0;
	}

	list->currentNode = list->start;

	while(list->currentNode) {
		printNode(list->currentNode);
		goOnList(list);
	}

	return 1;
}

/*
	Method name: addNodeOnList
	Description: Add a node on the end of the list
	Return: List pointer
*/
List* addNodeOnList(List *list, Node *node){

	if(emptyList(list)){
		list->start = node;
		list->end = node;
		node->index = 0;

	} else {
		Node *auxNode = list->end;
		list->end = node;
		list->end->prev = auxNode;
		auxNode->next = list->end;

		node->index = node->prev->index + 1;
	}

	list->size++;

	return list;
}

/*
	Method name: moveIndexFromNToM
	Description: Recive a list and two parameter of the function. Afterward exchange them.
	Return: List pointer
*/
List* moveIndexFromNToM(List *list, int n, int m){

	if(n == m) return list;

	Node *auxNode = malloc(sizeof(Node));
	int aux;

	if(n > m) {
		aux = n;
		n = m;
		m = aux;
	}

	Node *n1 = nodeNOnList(list, n);
	Node *n2 = nodeNOnList(list, m);

	if(!n1 || !n2){
		printf("Node out of bounds\n");
		return list;
	}

	if((n + 1) == m || (n - 1) == m) { // Are consequential
		auxNode->prev = n1->prev;

		n1->prev = n2;
		n1->next = n2->next;
		if(n1->next)
			n1->next->prev = n1;

		n2->prev = auxNode->prev;
		if(n2->prev)
			n2->prev->next = n2;
		n2->next = n1;
	} 
	else { // are non sequential

		auxNode->prev = n1->prev;
		auxNode->next = n1->next;

		// Put n1 on n2 place
		n1->prev = n2->prev;
		n1->next = n2->next;
		if(n2->prev)
			n2->prev->next = n1;
		if(n2->next)
			n2->next->prev = n1;

		// Put n1 on n2 place
		n2->prev = auxNode->prev;
		n2->next = auxNode->next;
		if(auxNode->prev)
			auxNode->prev->next = n2;
		if(auxNode->next)
			auxNode->next->prev = n2;
	}

	//Change start of the list
	if(n1->index == 0) {
		list->start = n2;
	}
	if(n2->index == 0) {
		list->start = n1;
	}

	//Change end of the list
	if(n1->index == list->size - 1) {
		list->end = n2;
	}
	if(n2->index == list->size - 1) {
		list->end = n1;
	}
	
	// Update index
	aux = n1->index;
	n1->index = n2->index;
	n2->index = aux;

	free(auxNode);
	auxNode = NULL;

	return list;
}

