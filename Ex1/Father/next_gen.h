/*oOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoO*/
/*
Baruch Margolis - 336451182
Omer Badur - 313418659
HW1
next_gen
*/
/*oOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoO*/

#ifndef NEXT_GEN
#define NEXT_GEN

/*oOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoO*/

/*
* check_four_sides accepts 3 variables of type 'int', 1 variable that is an array of pointers (matrix)
* and a variable of type 'char'. It receives an element of the previous generation of the forest and checks the 
* four sides of it (up, down, left and right). It returns a counter of the amount of nieghbours that fit the requirement for change.
* 
* Parameters:
* -----------
* dim - the dimension of the forest
* mat_gen_zero - the current forest matrix
* i - the row index of the matrix element
* j - the column index of the matrix element
* character_of_interest - the character we compares the neighbour to for counter
*/
int check_four_sides(const int dim, const char** mat_gen_zero, const int i, const int j, const char character_of_interest);

/*
* check_four_corners accepts 3 variables of type 'int', 1 variable that is an array of pointers (matrix)
* and a variable of type 'char'. It receives an element of the previous generation of the forest and checks the
* four corners of it. It returns a counter of the amount of nieghbours that fit the requirement for change.
*
* Parameters:
* -----------
* dim - the dimension of the forest
* mat_gen_zero - the current forest matrix
* i - the row index of the matrix element
* j - the column index of the matrix element
* character_of_interest - the character we compares the neighbour to for counter
*/
int check_four_corners(const int dim, const char** mat_gen_zero, const int i, const int j, const char character_of_interest);

/*
* evaluate_generation accepts 1 variables of type 'int', 1 variable that is an array of pointers (matrix)
* and a variable of type 'string'. It receives the previous generation of the forest and returns the next
* generation. It returns a pointer to the next generation of the matrix, and also updates the string to be sent to
* Son.exe
*
* Parameters:
* -----------
* mat_gen_zero - the current forest matrix
* dim - the dimension of the forest
* son_str - the string of the forest to be sent to Son.exe
*/
char** evaluate_generation(const char** mat_gen_zero,const int dim, char* son_str);
#endif 

