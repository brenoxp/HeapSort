#include <stdlib.h>

#include "heap_sort.h"

void heapify(List *list, Node *parent);


/*
	Method name: heapSort
	Description: Apply heapify to the list sending as parameter the end of the list 
	and	repeat while the end of the list is different of the start.	
	For each repetition the end of the list goes to pointer to the previous element of the end.
	Return: void
*/
void heapSort(List *list) {
	if(list->size == 0 || list->size == 1) return;

	Node *endList = list->end;
	int listSize = list->size;

	while(list->end != list->start){

		heapify(list, getParent(list, list->end));

		moveIndexFromNToM(list, list->start->index, list->end->index);

		list->end = list->end->prev;
		list->size--;
	}
	
	list->end = endList;
	list->size = listSize;

}



/*
	Method name: heapify
	Description: Goes through all the elements of the list (recursively) and check if theirs
	childs is greather than the element that is being verifyed
	Return: void
*/
void heapify(List *list, Node *nodeParent) { 

	if(haveLeftChild(list, nodeParent)) {
		Node *child = getLeftChild(list, nodeParent);

		if(child->id > nodeParent->id) {
			moveIndexFromNToM(list, nodeParent->index, child->index); // Move element in the list
		}
	}

	if(haveRightChild(list, nodeParent)) {
		Node *child = getRightChild(list, nodeParent);

		if(child->id > nodeParent->id) {
			moveIndexFromNToM(list, nodeParent->index, child->index); // Move element in the list
		}
	}

	
	if(haveLeftBrother(list, nodeParent)){
		heapify(list, getLeftBrother(list, nodeParent)); // Apply heapify to the left brother of the parent node
	}
}
