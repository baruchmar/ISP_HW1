#include <stdio.h>
#include <malloc.h>
#include <stdlib.h> 
#include <string.h>

#include "mem_handle.h"

// TODO:documentation!!
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
void memory_error() {
	printf("There was a problem allocating the memory for the matrix!!\n");
	exit(1);
}
char** make_matrix(const int dim, FILE* p_input_file, char* son_str) {
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
void free_mat(char** mat,const int dim) {
	int i;
	for (i = 0; i < dim; i++){
		free(mat[i]);
	}
	free(mat);
}