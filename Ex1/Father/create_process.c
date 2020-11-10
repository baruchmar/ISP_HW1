/*oOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoO*/
/*
Baruch Margolis - 336451182
Omer Badur - 313418659
HW1
create_process
*/
/*oOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoO*/

/* Library includes: */
#include <stdio.h>
#include <windows.h>
#include <string.h>

/* Project includes: */
#include "create_process.h"

// Based off of recitation 3
long create_process_simple_main(char *son_str) {
	PROCESS_INFORMATION proc_info;
	DWORD				waitcode;
	DWORD				exitcode;
	BOOL				ret_val;
	TCHAR				command[] = ("..\\Debug\\Son.exe");			

	ret_val = create_process_simple(command, &proc_info, son_str);
	
	//Checks if the create process succeeded
	if (ret_val == 0) {
		printf("Process creation failed !\n");
		return 1;
	}
	
	//Getting exit code from Son.exe
	waitcode = WaitForSingleObject(proc_info.hProcess, 5000);
	GetExitCodeProcess(proc_info.hProcess, &exitcode);
	CloseHandle(proc_info.hProcess); /* Closing the handle to the process */
	CloseHandle(proc_info.hThread); /* Closing the handle to the main thread of the process */
	return (int)exitcode;
}

BOOL create_process_simple(LPTSTR command_line, PROCESS_INFORMATION *p_info, TCHAR *son_str) {
	STARTUPINFO start_info = { sizeof(STARTUPINFO), NULL, 0 };
	// Sending module name and command line in seperate variables to Son.exe process
	return CreateProcess(
		command_line,			/*  Module name */
		son_str,				/*  Command line. */
		NULL,					/*  Process handle not inheritable. */
		NULL,					/*  Thread handle not inheritable. */
		FALSE,					/*  Set handle inheritance to FALSE. */
		NORMAL_PRIORITY_CLASS,	/*  creation/priority flags. */
		NULL,					/*  Use parent's environment block. */
		NULL,					/*  Use parent's starting directory. */
		&start_info,			/*  Pointer to STARTUPINFO structure. */
		p_info					/*  Pointer to PROCESS_INFORMATION structure. */
	);
}