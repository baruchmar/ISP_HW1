/*oOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoO*/
/*
Baruch Margolis - 336451182
Omer Badur - 313418659
Ex1
Son - This process receives 'son_str' from Father.exe and returns the number of trees burnt in the forest.

/*oOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoO*/


/* Library includes: */
#include <stdio.h> /* for printf */
#include <stdlib.h> 

int main(int argc, char** argv) {
	int c = 0, count = 0;

	// Based off of code from https://www.programmingsimplified.com/c-program-find-characters-frequency
	if (argc > 1) {
		while (argv[1][c] != '\0') {
			/** Considering characters 'F' only and ignoring others. */

			if (argv[1][c] == 'F') {
				count++;
			}
			c++;
		}
	}
	//printf("The amount of burnt trees is: %d\n", count);

	return count;
}