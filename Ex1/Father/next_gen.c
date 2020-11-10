/*oOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoO*/
/*
Baruch Margolis - 336451182
Omer Badur - 313418659
HW1
next_gen
*/
/*oOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoO*/

/* Project includes: */
#include "next_gen.h"
#include "mem_handle.h"

/*oOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoO*/
int check_four_sides(const int dim, const char** mat_gen_zero,const int i,const int j, const char character_of_interest) {
	
	int count = 0;
	
	/* Checking up, down, left and right of the element but using dim 
	* to make sure we don't exit the boundaries of the matrix*/
	
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

/*oOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoO*/
int check_four_corners(const int dim, const char** mat_gen_zero, const int i, const int j, const char character_of_interest) {
	
	int count = 0;
	
	/* Checking 4 corners of the element but using dim
	* to make sure we don't exit the boundaries of the matrix*/
	
	if (i > 0 && j > 0 && mat_gen_zero[i - 1][j - 1] == character_of_interest)
		count++;
	
	if (i < dim - 1 && j > 0 && mat_gen_zero[i + 1][j - 1] == character_of_interest)
		count++;
	
	if (i < dim - 1 && j < dim - 1 && mat_gen_zero[i + 1][j + 1] == character_of_interest)
		count++;
	
	if (i > 0 && j < dim - 1 && mat_gen_zero[i - 1][j + 1] == character_of_interest)
		count++;
	
	return count;
}
/*oOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoO*/
char** evaluate_generation(const char** mat_gen_zero, const int dim, char* son_str) {
	
	int i, j, m = 0;
	char** next_gen_matrix;
	
	//Adding a space to beginning of the string we send to Son.exe in order for it take it as argv[1]
	son_str[m] = ' ';
	m++;
	
	//Allocating memory for the next generation matrix
	next_gen_matrix = malloc_matrix(dim);
	
	//Running through every element of the previous generation matrix
	for (i = 0; i < dim; i++) {
		for (j = 0; j < dim; j++) {

			//There is a fire so tree burnt to ground
			if (mat_gen_zero[i][j] == 'F')
				next_gen_matrix[i][j] = 'G';
			
			//Check if non burning tree will catch on fire
			else if (mat_gen_zero[i][j] == 'T') {
				if (check_four_sides(dim, mat_gen_zero, i, j, 'F') >= 1)
					next_gen_matrix[i][j] = 'F';
				else
					next_gen_matrix[i][j] = 'T';
			}
			
			//check if tree will grow on ground
			else if (mat_gen_zero[i][j] == 'G') {
				if ((check_four_sides(dim, mat_gen_zero, i, j, 'T') +
					check_four_corners(dim, mat_gen_zero, i, j, 'T')) >= 2)
					next_gen_matrix[i][j] = 'T';
				else
					next_gen_matrix[i][j] = 'G';
			}
			// Appending the new character to the string for Son.exe
			son_str[m] = next_gen_matrix[i][j];
			m++;
		}
	}
	//Freeing memory of previous generation matrix since we are done with it
	free_mat(mat_gen_zero, dim);
	
	return next_gen_matrix;
}