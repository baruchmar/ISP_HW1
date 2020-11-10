/*oOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoO*/
/*
Baruch Margolis - 336451182
Omer Badur - 313418659
HW1
create_process
*/
/*oOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoO*/

#ifndef CREATE_PROCESS
#define CREATE_PROCESS

/* Library includes: */
#include <stdio.h>

/*
* create_process_simple_main accepts one variable of type 'char*'. 
* It sets up all the parameters for creating a seperate running process 
* and returns the exitcode of Son.exe.It then closes all the handles.
* (Based off of files from Recitation 3)
*
* Parameters:
* -----------
* son_str - the string of the forest to be sent to Son.exe
*/
long create_process_simple_main(char* son_str);

/*
* create_process_simple accepts one variable of type 'LPTSTR', one variable of type 'PROCESS_INFORMATION'
* and one variable of type 'TCHAR'.
* It takes the variables given to it as well as creates STARTUPINFO and runs the function CreateProcess of windows
* and returns a boolean of the created process.
* (Based off of files from Recitation 3)
*
* Parameters:
* -----------
* command_line - the argv[0] argument which is where the process is located
* p_info - it is the process information we created
* son_str - the string of the forest to be sent to Son.exe
*/
BOOL create_process_simple(LPTSTR command_line, PROCESS_INFORMATION* p_info, TCHAR* son_str);
#endif // !CREATE_PROCESS
