/*oOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoO*/
/*
Baruch Margolis - 336451182
Omer Badur - 313418659
HW1
Father
*/
/*oOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoO*/

/* Library includes: */
#include <stdio.h> /* for printf */
#include <stdlib.h> /* for exit() */
#include <malloc.h>
#include <string.h>

int main(int argc, char** argv) {

	FILE* p_input_file, * p_output_file;

	errno_t err = fopen_s(&p_input_file, "input.txt", "r");
	if (err)
		printf("Error Opening Input File!!\n");

	char line[100];
	fgets(line, 100, p_input_file);

	return 0;

}