/*
TEMPLATE FOR SHRINK WRAPPED APPLICATION

Your application
Copyright (c) 2011 Your name.
	
Licensed under your license.
	
-------------------------------------------
PLEASE DO NOT ALTER THIS NOTICE:
ShrinkWrapper bootstrap code.
Copyright (c) 2011 Sam Saint-Pettersen.
	
Released under the MIT License.
------------------------------------------
*/

#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

// ShrinkWrap class
class ShrinkWrap {
	private:
		// Instance variables
		string appName;
		string appVersion;
		string appDependency;
				
	public:
		// Constructor
		ShrinkWrap() {

			// Set application information
			appName = "Dummy application";
			appVersion = "1.0";
			appDependency = "ikvm";
		}

		// Properties
		string Name() {
			return appName;
		}

		string Version() {
			return appVersion;
		}

		string Dependency() {
			return appDependency;
		}

		void Execute(int argc, char* argv[]) {
			system("notepad");
		}
};

// Main method; program entry point
int main(int argc, char* argv[]) {


	ShrinkWrap hostedApp = ShrinkWrap();
	hostedApp.Execute(argc, argv);

	return 0;
}
