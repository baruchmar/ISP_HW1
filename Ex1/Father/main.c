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
#include <stdlib.h> 
#include <malloc.h>
#include <string.h>
#include <windows.h>

#include "create_process.h"
#include "next_gen.h"
#include "mem_handle.h"


int main(int argc, char** argv) {

	FILE* p_input_file, * p_output_file;
	long dim = 0, gen = 0;
	int i, burnt_trees =0;
	if (argc <= 1) {
		printf("No File loaded in Command Line\n");
		exit(1);
	}
	errno_t err = fopen_s(&p_input_file, argv[1], "r");
	if (err) {
		printf("Error Opening Input File!!\n");
		exit(1);
	}
	char line[15];// TODO HARDCODED DATA 15
	fgets(line, 15, p_input_file);
	dim = strtol(line, NULL, 10);

	fgets(line, 15, p_input_file);
	gen = strtol(line, NULL, 10);

	char* son_str;
	son_str = (char*)malloc((dim * dim + 1) * sizeof(char));

	char** mat_gen_zero;
	mat_gen_zero = make_matrix(dim, p_input_file, son_str);
	fclose(p_input_file);
	//TODO Send son_str to Son to get # of burnt trees
	burnt_trees = create_process_simple_main(son_str);

	errno_t err1 = fopen_s(&p_output_file, "output.txt", "w");
	if (err1) {
		printf("Error Opening Output File!!\n");
		exit(1);
	}
	fprintf(p_output_file, "%s - %d\n", son_str, burnt_trees);

	char** next_gen_matrix = NULL;

	for (i = 0; i < gen - 1; i++) {
		next_gen_matrix = evaluate_generation(mat_gen_zero, dim, son_str);
		mat_gen_zero = next_gen_matrix;
		fprintf(p_output_file, "%s - %d\n", son_str, burnt_trees);
	}
	// Free 
	free_mat(mat_gen_zero, dim);
	free(son_str);
	fclose(p_output_file);
	return 0;

}