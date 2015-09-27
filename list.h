struct node {
	int id; // Number for sorting
	int index;

	struct node *prev;	// Left child
	struct node *next;	// Right child
};
typedef struct node Node;

struct list {
	Node *start;
	Node *end;

	Node *currentNode;
	int size;
};
typedef struct list List;

List* createListWithArray(int *array, int size);
List* moveIndexFromNToM(List *list, int n, int m);

int printList(List *list);
Node* nodeNOnList(List *list, int index);
void deleteList(List *list);