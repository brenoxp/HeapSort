#include <stdlib.h>

struct node {
	struct node *lc;	// Left child
	struct node *rc;	// Right child
};
typedef struct node node;

struct tree {
	node *root;
	node *lastChild;
};
typedef struct tree tree;


tree* createTree(){

	tree *heapTree = malloc(sizeof(tree));

	

	return tree;
}

void deleteTree(tree *heapTree) {

	//passa por todos os filhos depois deleta a raiz

	

}