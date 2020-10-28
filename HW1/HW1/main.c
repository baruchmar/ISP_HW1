/*oOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoO*/
/*
Baruch Margolis - 336451182
Omer Badur - 313418659
HW1
Processes
*/
/*oOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoO*/


/* Library includes: */
#include <stdio.h> /* for printf */
#include <stdlib.h> /* for exit() */

#include "HardCodedData.h"
int main(int argc, char** argv) {
	int i, c = 0, count = 0;

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
	printf("The amount of burt trees is: %d\n", count);
	
	return count;
}