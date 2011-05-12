/*
ShrinkWrap bootstrap template code.
Copyright (c) 2011 Sam Saint-Pettersen.

Cross-platform functionality header.
*/

// Includes and defines depending on platform.
#include <string>
using namespace std;

#ifdef _WIN32
#include <windows.h>
#define BAD_EXIT_CODE 2
#else
#include <unistd.h>
#define ULONG unsigned long
#define BAD_EXIT_CODE -1
#endif

// Prototypes
int InvokeApp(string process, bool isGui);


// Invoke the application
int InvokeApp(string process, bool isGui) {
	int exitCode = 0;

#ifdef _WIN32

	STARTUPINFO info={sizeof(info)};
	PROCESS_INFORMATION processInfo;
	ULONG rc;
	char *p;
	strcpy(p, process.c_str());

	if(isGui) {

	}

	if(!CreateProcessA(NULL, p, NULL, NULL, false, 0,
	NULL, NULL, &info, &processInfo)) {
		exitCode = (int) rc;
	}

#else
	exitCode = system(process.c_str());
#endif
	return exitCode;
}
