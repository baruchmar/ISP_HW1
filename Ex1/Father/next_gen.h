// TODO:documentation!!
#ifndef NEXT_GEN
#define NEXT_GEN
int check_four_sides(int dim, char** mat_gen_zero, char** next_gen_matrix, int i, int j, char character_of_interest);
int check_four_corners(int dim, char** mat_gen_zero, char** next_gen_matrix, int i, int j, char character_of_interest);
char** evaluate_generation(char** mat_gen_zero, int dim, char* son_str);
#endif 

