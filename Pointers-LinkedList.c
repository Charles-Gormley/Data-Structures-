#include <stdlib.h>
#include <stdio.h>

struct Node {
	int value;
	struct Node* next;
};

struct Node* CREATE(int val) {
	struct Node* newNode = malloc(sizeof(struct Node*));
	newNode->value = val;
	newNode->next = NULL;
	return newNode;
}


struct Node* FIRST(struct Node* head) {
	return head;
}

struct Node* END(struct Node* head) {
	struct Node* position;

	position = head;

	while (position != NULL) {
		position = position->next;
	}

	return position;
}

int RETRIEVE(struct Node* p, struct Node* head) {
	struct Node* position;

	position = head;


	if (position == NULL) {
		return -1;
	}

	while (position != NULL) {
		if (position == p) {
			return position->value;
		}
		position = position->next;
	}

}

struct Node* LOCATE(int x, struct Node* head) {
	struct Node* position;

	position = head;

	while (position->next != NULL && position->value != x) {
		position = position->next;
	}

	return position;
}

struct Node* NEXT(struct Node* p, struct Node* head) {
	struct Node* position;

	position = p;

	return position->next;
}

struct Node* PREVIOUS(struct Node* p, struct Node* head) {
	struct Node* position;

	position = head;

	if (p == NULL) {
		return(END(position));
	}

	while (position != NULL) {
		if (position->next == p) {
			return position;
		}
		position = position->next;
	}

}

struct Node* INSERT(int x, struct Node* p, struct Node* head) {
	// Combining append and Insert Before Function. 

	struct Node* before_p;

	struct Node* new_node = malloc(sizeof(struct Node));
	new_node->value = x;

	if (p == head) {
		new_node->next = head;
		// Returning New Node to be used as new header because if not we would 
		return new_node;
	}

	else {

		before_p = head;

		while (before_p->next != p) {
			before_p = before_p->next;
		}

		before_p->next = new_node;
		new_node->next = p;
	}
}

void DELETE(struct Node* p, struct Node* head) {
	struct Node* trash_node;
	struct Node* before_p;

	// Declaring iterable Node for while loop. 
	before_p = head;

	// Find the position before the designated pointer.
	while (before_p->next != p) {
		before_p = before_p->next;
	}


	// Declaring the node we wish to delete.
	trash_node = before_p->next;

	// have the pointer before the designated pointer equal point to the future next subsequent pointer.
	before_p->next = trash_node->next;

	return(END(head));

	// Freeing the memory of the trash node. 
	free(trash_node);

}

int MAKENULL(struct Node* head) {
	struct Node* position;
	struct Node* next_position;

	position = head;

	while (position != NULL) {
		next_position = position->next;
		free(position);
		position = next_position;
	}

	head = NULL;
}

