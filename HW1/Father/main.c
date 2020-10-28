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

int main(int argc, char** argv) {

	

	FILE* fp_in = NULL, * fp_out = NULL;
	if (NULL == (fp_in = fopen(argv[1], "r")))
	{
		printf("Error: opening %s failed\n", argv[1]);
		exit(1);
	}
	char line[100];
	fgets(line, 100, fp_in);
	return 0;

}