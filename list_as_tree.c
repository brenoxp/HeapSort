#include <math.h>
#include "list_as_tree.h"

#define NULL 0

// Functions to see a list as a binary tree structure

Node* getParent(List *list, Node *node) {
	if(node->index == 0) return NULL;

	int parentIndex = floor((node->index - 1) / 2);
	return nodeNOnList(list, parentIndex);
}

Node* getLeftChild(List *list, Node *node) {
	int leftChildIndex = 2 * node->index + 1;
	return nodeNOnList(list, leftChildIndex);
}

Node* getRightChild(List *list, Node *node) {
	int rightChildIndex = 2 * node->index + 2;
	return nodeNOnList(list, rightChildIndex);
}

Node* getLeftBrother(List *list, Node *node) {
	if(node->index == 0) return NULL;

	int leftBrotherIndex = node->index - 1;
	return nodeNOnList(list, leftBrotherIndex);
}

int validIndex(List *list, int index){
	if(index > list->size - 1) return 0;
	if(index < 0) return 0;

	return 1;
}

int haveLeftChild(List *list, Node *node) {
	int leftChildIndex = 2 * node->index + 1;
	return validIndex(list, leftChildIndex);
}

int haveRightChild(List *list, Node *node) {
	int rightChildIndex = 2 * node->index + 2;
	return validIndex(list, rightChildIndex);
}

int haveLeftBrother(List *list, Node *node) {
	int leftBrotherIndex = node->index - 1;
	return validIndex(list, leftBrotherIndex);
}