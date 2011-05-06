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
using namespace std;

// ShrinkWrap class
class ShrinkWrap {
	private:
		// Instance variables
		string appName;
		string appVersion;
		string appExecutable;
		string appLauncher;
		
	public:
		// Constructor
		ShrinkWrap() {

			// Set application information
			appName = APP_NAME;
			appVersion = APP_VERSION;
			appExecutable = APP_EXECUTABLE;
			appLauncher = APP_LAUNCHER;
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
			exitCode = InvokeApp(process, APP_ISGUI);
			if(exitCode == BAD_EXIT_CODE) {
				throw BAD_EXIT_CODE;
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

	try {
		ShrinkWrap hostedApp = ShrinkWrap();
		hostedApp.Execute(argc, argv);
	}
	catch(int badExitCode)
	{
		cout << "\nAn error occurred in the application.\n";
	}

	return 0;
}
