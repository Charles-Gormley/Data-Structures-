#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Setting Node Space and Cell Space Sub Classes
struct Node {
	char label[50];

	struct Cell* cell;
};

struct Cell {
	struct Node* node;

	struct Cell* next;
};

// User Defined Functions
struct Node* Create_Node(char* label) {
	struct Node* new_node = malloc(sizeof(struct Node) + sizeof(struct Cell));

	// Setting New_nodes attributes.
	strcpy(new_node->label, label);

	return new_node;

}

struct Cell* Connect_Child(struct Node* parent, struct Node* child) {
	struct Cell* new_cell = malloc(sizeof(struct Node) + sizeof(struct Cell) * 2);

	// Connecting Node 1 to cellspace.
	parent->cell = new_cell;

	// Connect Node 1's connection to cellspace to Node_2. 
	// This is the left most child node of node_1. 
	new_cell->node = child;

	// Have this cell's Next Cell point to a null cell. 
	new_cell->next = NULL;

	return new_cell;
}

void Connect_Siblings(struct Node* left, struct Node* right) {
	struct Cell* lefts_new_cell = malloc(sizeof(struct Node) + sizeof(struct Cell) * 2);
	struct Cell* rights_new_cell = malloc(sizeof(struct Node) + sizeof(struct Cell) * 2);

	left->cell = lefts_new_cell;
	right->cell = rights_new_cell;

	lefts_new_cell->next = rights_new_cell;
	rights_new_cell->node = right;
}

char* LABEL(struct Node* Node, struct Node* Root) {
	return Node->label;
}

struct Node* ROOT(struct Node* Root) {
	// Linked List Pointer implementation makes this easy. 
	return Root;
}

void MAKENULL(struct Cell** Root) {

	if (Root == NULL) { return; }

	*Root = NULL;

}

struct Node* RIGHT_SIBLING(struct Node* Node, struct Node* Root) {
	return Node->cell->next->node;
}

struct Node* LEFTMOST_CHILD(struct Node* Node, struct Node* Root) {
	return Node->cell->node;
}

struct Node* CREATEi(char* label, int i) {
	struct Node* root;

	root = Create_Node(label);

	if (i >= 1) {
		char empty_string[1] = " ";
		struct Node* child;
		struct Cell* cell;

		child = Create_Node(empty_string);
		cell = Connect_Child(root, child);


		for (int j = 2; j <= i; j++) {
			struct Node* right_child;
			struct Cell* new_cell;

			right_child = Create_Node(empty_string);

			Connect_Siblings(child, right_child);

			child = right_child;
		}

		return root;
	}
}