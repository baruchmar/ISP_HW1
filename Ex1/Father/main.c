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

char** malloc_matrix(int dim);
void memory_error();
char** make_matrix(long dim, FILE* p_input_file, char* son_str);
int check_four_sides(int dim, char** mat_gen_zero, char** next_gen_matrix, int i, int j, char character_of_interest);
int check_four_corners(int dim, char** mat_gen_zero, char** next_gen_matrix, int i, int j, char character_of_interest);

char** evaluate_generation(char** mat_gen_zero, int dim, char* son_str) {
	int i, j, m = 0;
	char** next_gen_matrix;
	
	next_gen_matrix = malloc_matrix(dim);
	for (i = 0; i < dim; i++) {
		for (j = 0; j < dim; j++) {
			
			//Tree burnt to ground
			if (mat_gen_zero[i][j] == 'F')
				next_gen_matrix[i][j] = 'G';
			//Check if tree is burnt
			else if (mat_gen_zero[i][j] == 'T') {
				if (check_four_sides(dim, mat_gen_zero, next_gen_matrix, i, j, 'F') >= 1)
					next_gen_matrix[i][j] = 'F';
				else
					next_gen_matrix[i][j] = 'T';
			}
			else if (mat_gen_zero[i][j] == 'G') {
				if ((check_four_sides(dim, mat_gen_zero, next_gen_matrix, i, j, 'T') +
					check_four_corners(dim, mat_gen_zero, next_gen_matrix, i, j, 'T')) >= 2)
					next_gen_matrix[i][j] = 'T';
				else
					next_gen_matrix[i][j] = 'G';
			}
			son_str[m] = next_gen_matrix[i][j];
			m++;
		}
	}
	return next_gen_matrix;
}

int check_four_corners(int dim, char** mat_gen_zero, char** next_gen_matrix, int i, int j, char character_of_interest) {
	int count = 0;
	if (i > 0 && j>0 &&  mat_gen_zero[i - 1][j-1] == character_of_interest)
		count++;
	if (i < dim - 1 && j > 0 && mat_gen_zero[i + 1][j - 1] == character_of_interest)
		count++;
	if (i < dim - 1 && j < dim - 1 && mat_gen_zero[i + 1][j + 1] == character_of_interest)
		count++;
	if (i > 0 && j < dim - 1 && mat_gen_zero[i - 1][j + 1] == character_of_interest)
		count++;
	return count;
}

int check_four_sides(int dim, char** mat_gen_zero, char** next_gen_matrix, int i, int j, char character_of_interest) {
	int count = 0;
	if (i > 0 && mat_gen_zero[i - 1][j] == character_of_interest)
		count++;
	if (j > 0 && mat_gen_zero[i][j - 1] == character_of_interest)
		count++;
	if (i < dim - 1 && mat_gen_zero[i + 1][j] == character_of_interest)
		count++;
	if (j < dim - 1 && mat_gen_zero[i][j + 1] == character_of_interest)
		count++;
	return count;
}

void memory_error() {
	printf("There was a problem allocating the memory for the matrix!!\n");
	exit(1);
}

char** malloc_matrix(int dim) {
	int i;
	char** matrix = (char*)malloc(dim * sizeof(char*));//TODO Free memory
	if (NULL == matrix)
		memory_error();

	for (i = 0; i < dim; i++) {
		matrix[i] = malloc(dim * sizeof(char));
		if (NULL == matrix[i])
			memory_error();
	}
	return matrix;
}

//TODO Move to Header file!!
char** make_matrix(long dim, FILE* p_input_file, char* son_str) {
	int i, j, m = 0;
	char** matrix;
	matrix = malloc_matrix(dim);

	for (i = 0; i < dim; i++) {
		for (j = 0; j < dim; j++) {
			int ch = fgetc(p_input_file);
			matrix[i][j] = (char)ch;
			fgetc(p_input_file);//Get Commas
			son_str[m] = (char)ch;
			m++;
		}
	}
	son_str[m] = '\0';
	
	return matrix;
}
int main(int argc, char** argv) {

	FILE* p_input_file, * p_output_file;
	long dim = 0, gen = 0;
	int i, burnt_trees =0;

	errno_t err = fopen_s(&p_input_file, "myinput.txt", "r");//TODO Change to ARGV!!!
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
	son_str = (char*)malloc((dim * dim) * sizeof(char));

	char** mat_gen_zero;
	mat_gen_zero = make_matrix(dim, p_input_file, son_str);
	fclose(p_input_file);
	//TODO Send son_str to Son to get # of burnt trees
	
	errno_t err1 = fopen_s(&p_output_file, "output.txt", "w");
	if (err1) {
		printf("Error Opening Output File!!\n");
		exit(1);
	}
	fprintf(p_output_file, "%s - %d\n", son_str, burnt_trees);

	//for(i<gen)
	//son_str[0] ='\0';
	char** next_gen_matrix;

	for (i = 0; i < gen - 1; i++) {
		next_gen_matrix = evaluate_generation(mat_gen_zero, dim, son_str);
		mat_gen_zero = next_gen_matrix;
		fprintf(p_output_file, "%s - %d\n", son_str, burnt_trees);
	}
	return 0;

}