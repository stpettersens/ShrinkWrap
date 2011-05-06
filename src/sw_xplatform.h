/*
ShrinkWrap bootstrap template code.
Copyright (c) 2011 Sam Saint-Pettersen.
http://stpettersens.github.com/ShrinkWrap

Cross-platform functionality header.
*/

// Includes and defines depending on platform.
#include <string>
using namespace std;

#ifdef _WIN32
#include <windows.h>
#define BAD_EXIT_CODE 1
#else
#include <unistd.h>
#define BAD_EXIT_CODE -1
#endif

// Prototypes
int InvokeApp(string process, bool isGUI);


// Invoke the application
int InvokeApp(string process, bool isGUI) {
	int exitCode = 0;

//#ifdef _WIN32

	//wchar_t *wprocess;
	//memcpy(wprocess, process.c_str(), strlen(process.c_str()));
	//LPWSTR wp = lstrcpyW(wp, process);
	//CreateProcess(NULL, wp, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);
//#else
	exitCode = system(process.c_str());
//#endif
	return exitCode;
}
