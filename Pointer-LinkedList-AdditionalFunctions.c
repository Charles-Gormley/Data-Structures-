#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

struct Node {
	int value;
	struct Node* next;
};

struct Node* CREATE(int val) {
	struct Node* newNode = malloc(sizeof(struct Node*));
	struct Node* endNode = malloc(sizeof(struct Node*));
	newNode->value = val;
	endNode->value = NULL;
	newNode->next = endNode;

	return newNode;
}


struct Node* FIRST(struct Node* head) {
	return head;
}

struct Node* END(struct Node* head) {
	struct Node* position;

	position = head;

	while (position->value != NULL) {
		position = position->next;
	}


	return position;
}

int RETRIEVE(struct Node* p, struct Node* head) {
	struct Node* position;

	position = head;



	while (position->value != NULL) {
		if (position == p) {
			return position->value;
		}

		position = position->next;
	}

	return -1;
}

struct Node* LOCATE(int x, struct Node* head) {
	struct Node* position;

	position = head;

	while (position->next->value != NULL && position->value != x) {
		position = position->next;
	}

	return position;
}

struct Node* NEXT(struct Node* p, struct Node* head) {
	struct Node* position;
	struct Node* undefined = malloc(sizeof(struct Node*));
	undefined->value = -1;

	position = head;

	while (position->value != NULL) {
		if (position == p) {
			return position->next;
		}
		position = position->next;

	}

	return undefined;

}

struct Node* PREVIOUS(struct Node* p, struct Node* head) {
	struct Node* position;
	struct Node* undefined = malloc(sizeof(struct Node*));
	undefined->value = -1;

	position = head;

	while (position->value != 0) {
		if (position->next == p) {
			return position;
		}
		else {
			position = position->next;
		}
	}

	return undefined;


}

struct Node* INSERT(int x, struct Node* p, struct Node* head) {
	// Combining append and Insert Before Function. 

	struct Node* before_p;
	int temp_value;

	struct Node* new_node = malloc(sizeof(struct Node));
	new_node->value = x;

	if (p == head) {
		temp_value = head->value;
		head->next = new_node;
		head->value = new_node->value;
		new_node->value = temp_value;

		// Just for this situation you need to reinsate the Null value for the End Node.
		struct Node* end_node = malloc(sizeof(struct Node));
		end_node->value = NULL;
		head->next->next = end_node;
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

	if (p == head) {
		free(head);
	}
	else {

		if (p == END(head)) {

		}
		else {

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


			// Freeing the memory of the trash node. 
			free(trash_node);
		}
	}

}

struct Node* MAKENULL(struct Node* head) {
	struct Node* position;
	struct Node* next_position;

	position = head;

	while (position != NULL) {
		next_position = position->next;
		free(position);
		position = next_position;
	}

	head = NULL;

	return(head);
}

struct Node* insertion_front(int arr[], size_t size) {
	struct Node* head;
	struct Node* position;

	int index;
	index = 1;


	head = CREATE(arr[0]);
	position = head;


	while (index < size) {
		INSERT(arr[index], position->next, head);
		position = position->next;
		index = index + 1;
		position->next->value = 0;
	}
	return head;
}

struct Node* insertion_back(int arr[], size_t size) {
	struct Node* head;
	struct Node* position;

	int index;
	index = (size - 1);

	head = CREATE(arr[index]);
	position = head;

	index = index - 1;

	while (index >= 0) {
		INSERT(arr[index], position->next, head);
		position = position->next;
		index = index - 1;
		position->next->value = 0;
	}

	return head;
}

void traverse(struct Node* head) {
	struct Node* position;

	position = head;



	while (position != END(head)) {
		// printf("%d", position->value);
		position = position->next;
	}
}

void delete_back(struct Node* head) {

	while (PREVIOUS(END(head), head) != head) {
		DELETE(PREVIOUS(END(head), head), head);
	}

	DELETE(head, head);

}

void delete_front(struct Node* head) {
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
