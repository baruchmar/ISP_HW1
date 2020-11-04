#include "next_gen.h"
#include "mem_handle.h"

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

int check_four_corners(int dim, char** mat_gen_zero, char** next_gen_matrix, int i, int j, char character_of_interest) {
	int count = 0;
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
	free_mat(mat_gen_zero, dim);
	return next_gen_matrix;
}