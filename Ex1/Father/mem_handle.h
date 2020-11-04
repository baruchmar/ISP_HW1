#ifndef MEM_HANDLE
#define MEM_HANDLE
#include <stdio.h>
char** malloc_matrix(int dim);
void memory_error();
char** make_matrix(const int dim, FILE* p_input_file, char* son_str); 
void free_mat(char** mat, const int dim);
#endif // !MEM_HANDLE
