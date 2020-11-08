#ifndef MEM_HANDLE
#define MEM_HANDLE
#include <stdio.h>

/* These functions handle allocation freeing of memory*/ 

/*malloc_matrix:
  This function allocates memory for a square matrix of given dimension.
  Parameters: dim: int 
              this denotes the dimension of the square matrix we want to create.
  Returns:    matrix: char**
              a dimXdim matrix, with uninitialized values.
*/
char** malloc_matrix(int dim);

/*memory_error:
  This function prints out an error if memory allocation was unsuccessful
  exits with 1.
*/
void memory_error();

/*make_matrix:
  This function allocates memory and initializes a matrix and a string based off of the input_file it receives.
  Parameters: dim: int 
              this denotes the dimension of the square matrix we want to create.
              p_input_file: FILE* 
              the input file. weassume a file with the same structure as specified
              son_str:     char* 
              A pointer to a string to be intialized as part of make_matrix.
  Returns:    matrix: char**
              a dimXdim matrix, with initialized values.
*/
char** make_matrix(const int dim, FILE* p_input_file, char* son_str); 

void free_mat(char** mat, const int dim);
#endif // !MEM_HANDLE
