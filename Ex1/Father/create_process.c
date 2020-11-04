#include <stdio.h>
#include <windows.h>
#include <string.h>


#include "create_process.h"

// Based off of recitation 3
long create_process_simple_main(char *son_str) {
	PROCESS_INFORMATION proc_info;
	DWORD				waitcode;
	DWORD				exitcode;
	BOOL				ret_val;
	TCHAR				command[] = ("..\\Debug\\Son.exe");			

	ret_val = create_process_simple(command, &proc_info, son_str);
	if (ret_val == 0) {
		printf("Process creation failed !\n");
		return 1;
	}
	waitcode = WaitForSingleObject(proc_info.hProcess, 5000);
	GetExitCodeProcess(proc_info.hProcess, &exitcode);
	return (long)exitcode;
}
BOOL create_process_simple(LPTSTR command_line, PROCESS_INFORMATION *p_info, TCHAR *son_str) {
	STARTUPINFO start_info = { sizeof(STARTUPINFO), NULL, 0 };
	return CreateProcess(
		command_line, /*  No module name (use command line). */
		son_str,			/*  Command line. */
		NULL,					/*  Process handle not inheritable. */
		NULL,					/*  Thread handle not inheritable. */
		FALSE,					/*  Set handle inheritance to FALSE. */
		NORMAL_PRIORITY_CLASS,	/*  creation/priority flags. */
		NULL,					/*  Use parent's environment block. */
		NULL,					/*  Use parent's starting directory. */
		&start_info,				/*  Pointer to STARTUPINFO structure. */
		p_info			/*  Pointer to PROCESS_INFORMATION structure. */
	);
}