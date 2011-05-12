/*
TEMPLATE FOR SHRINK WRAPPED APPLICATION

ShrinkWrap bootstrap template code.
Copyright (c) 2011 Sam Saint-Pettersen.
	
Released under the MIT License.

USAGE:
Application values care contained
within "sw_values.h".
------------------------------------------
*/

#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
#include "sw_xplatform.h"
#include "sw_values.h"

#ifdef _WIN32
	#define _WIN32_WINNT 0x0500
	#include <windows.h>
#else
	#define ULONG unsigned long
#endif
using namespace std;

// ShrinkWrap class
class ShrinkWrap {
	private:
		// Instance variables
		bool appDebug, appIsGui;
		string appName, appVersion, appExecutable, appLauncher;
		ULONG badExitCode;
		
	public:
		// Constructor
		ShrinkWrap() {

			// Set application settings using "sw_values.h" include.
			appDebug = APP_DEBUG;
			appIsGui = APP_IS_GUI;
			appName = APP_NAME;
			appVersion = APP_VERSION;
			appExecutable = APP_EXECUTABLE;
			appLauncher = APP_LAUNCHER;

			// Set exit code according to plaform built for,
			// using "sw_xplaform.h" include.
			badExitCode = BAD_EXIT_CODE;
		}

		// Execute method
		void Execute(int argc, char *argv[]) {
		
			int exitCode;
			char *args;
			string std_args;
			string process;

			// TODO: Implement argument passing...
			for(int i = 1; i < argc; i++) {
				args = argv[i];
				strcat(args, " ");
				std_args += args;
				
			}

			process = appLauncher + " " + appExecutable + " " + std_args;
			exitCode = InvokeApp(process, appIsGui);
			if(exitCode == badExitCode) {
				throw badExitCode;
			}
			if(APP_DEBUG) {
				cout << appName << " " << appVersion;
				cout << "\nExecuted: " << process;
				cout << "\nExit code: " << exitCode << "\n";
			}
		}
};

// Main method; program entry point
int main(int argc, char *argv[]) {

	#ifdef _WIN32
	HWND hWnd = GetConsoleWindow();
	#endif
	
	if(APP_IS_GUI) {
	#ifdef _WIN32	
		ShowWindow(hWnd, SW_HIDE);
	#endif
	}

	try {
		ShrinkWrap hostedApp = ShrinkWrap();
		hostedApp.Execute(argc, argv);
	}
	catch(ULONG badExitCode)
	{
		cout << "\nAn error occurred in the application.";
		cout << "\nExit code: " << badExitCode << "\n";
	}

	return 0;
}
