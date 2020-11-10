/*oOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoO*/
/*
Baruch Margolis - 336451182
Omer Badur - 313418659
Ex1
Father - Initializes gen_zero of forest, passes 'son_str'(a string that contians all the current gen information in a char* form)
		to Son.exe in order to get the number of trees burt. This process goes on as long as specified in the input_file.
		the output file is also maintained by Father.exe.
*/
/*oOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoO*/

/* Library includes: */
#include <stdio.h> 
#include <stdlib.h> 
#include <malloc.h>
#include <string.h>
#include <windows.h>

/* Project includes: */
#include "create_process.h"
#include "next_gen.h"
#include "mem_handle.h"

#define MAX_NUMBER_OF_DIGITS 10

int main(int argc, char** argv) {

	FILE* p_input_file, * p_output_file;
	int dim = 0, gen = 0;
	int i, burnt_trees = 0;
	char line[MAX_NUMBER_OF_DIGITS + 1]; // adding one for \0.

	// Checking that we are given an input file in the command line
	if (argc <= 1) {
		printf("No File loaded in Command Line\n");
		exit(1);
	}
	errno_t err = fopen_s(&p_input_file, argv[1], "r");
	if (err) {
		printf("Error Opening Input File!!\n");
		exit(1);
	}
	
	// Getting the dimension of the forest from file
	fgets(line, 15, p_input_file);
	dim = (int)strtol(line, NULL, 10);

	// Getting the amount of geneartion to run from file
	fgets(line, 15, p_input_file);
	gen = (int)strtol(line, NULL, 10);

	// Allocating memory for string to be sent to Son.exe
	char* son_str;
	son_str = (char*)malloc((dim * dim + 2) * sizeof(char));

	// Allocating memory for the matrix we will fill from file
	char** mat_gen_zero = NULL;
	mat_gen_zero = make_matrix(dim, p_input_file, son_str);
	
	//closing input file since we are done with it
	fclose(p_input_file);
	
	//Running Son.exe on the original matrix to get # of burnt trees
	burnt_trees = create_process_simple_main(son_str);

	errno_t err1 = fopen_s(&p_output_file, "output.txt", "w");
	if (err1) {
		printf("Error Opening Output File!!\n");
		exit(1);
	}
	
	// Writing the original generation to output.txt
	fprintf(p_output_file, "%s - %d\n", son_str + 1, burnt_trees);

	// Running all the remaining generations in a loop based on original file
	char** next_gen_matrix = NULL;
	for (i = 0; i < gen - 1; i++) {
		// Calculating next generation matrix and writing to file
		next_gen_matrix = evaluate_generation(mat_gen_zero, dim, son_str);
		mat_gen_zero = next_gen_matrix;
		burnt_trees = create_process_simple_main(son_str);
		fprintf(p_output_file, "%s - %d\n", son_str + 1, burnt_trees);
	}
	
	// Freeing up all the last allocated memory that we haven't freed yet
	free_mat(mat_gen_zero, dim);
	free(son_str);
	
	//Closing output file
	fclose(p_output_file);
	
	return 0;
}

