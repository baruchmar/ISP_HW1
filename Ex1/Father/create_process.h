#ifndef CREATE_PROCESS
#define CREATE_PROCESS
#include <stdio.h>
long create_process_simple_main(char* son_str);
BOOL create_process_simple(LPTSTR command_line, PROCESS_INFORMATION* p_info);
#endif // !CREATE_PROCESS
