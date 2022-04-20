#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Cell
{
	// rs = Right Sibling
	struct Cell* rs;

	// lmc = Left most children
	struct Cell* lmc;

	char label[50];
};

struct Cell* New_Cell(char* label) {
	struct Cell* new_cell = malloc(sizeof(struct Cell*) * 4);

	strcpy(new_cell->label, label);

	return new_cell;
}



// Returns the leftmost child of the current cell.
struct Cell* LEFTMOST_CHILD(struct Cell* Cell, struct Cell* Root) {
	return Cell->lmc;
}


// Returns the right sibling of the current cell. 
struct Cell* RIGHT_SIBLING(struct Cell* Cell, struct Cell* Root) {
	return Cell->rs;
}

// Checked
char* LABEL(struct Cell* Cell, struct Cell* Root) {
	return Cell->label;
}

struct Cell* CREATEi(char* label, int i) {
	struct Cell* r = malloc(sizeof(struct Cell*) * 4);


	strcpy(r->label, label);



	if (i >= 1) {
		struct Cell* child = malloc(sizeof(struct Cell*) * 4);
		char empty_string[5] = "";

		r->lmc = child;


		for (int j = 2; j <= i; j++) {
			struct Cell* right_child;

			right_child = New_Cell(empty_string);
			child->rs = right_child;
			strcpy(child->label, empty_string);
			child = right_child;
		}
	}

	return r;


}

struct Cell* ROOT(struct Cell* root_cell) {
	return root_cell;
}

void MAKENULL(struct Cell** Root) {

	if (Root == NULL) { return; }

	*Root = NULL;

}