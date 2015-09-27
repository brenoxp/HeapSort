#include "list.h"

Node* getParent(List *list, Node *node);
Node* getLeftChild(List *list, Node *node);
Node* getRightChild(List *list, Node *node);
Node* getLeftBrother(List *list, Node *node);

int haveLeftChild(List *list, Node *node);
int haveRightChild(List *list, Node *node);
int haveLeftBrother(List *list, Node *node);