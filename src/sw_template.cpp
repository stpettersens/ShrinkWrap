/*
TEMPLATE FOR SHRINK WRAPPED APPLICATION

Your application
Copyright (c) 2011 Your name.
	
Licensed under your license.
	
-------------------------------------------
PLEASE DO NOT ALTER THIS NOTICE:
ShrinkWrap bootstrap template code.
Copyright (c) 2011 Sam Saint-Pettersen.
	
Released under the MIT License.
------------------------------------------
*/

#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
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
			appName = "Hello World Swing application";
			appVersion = "1.0";
			appExecutable = "HelloWorldSwing.jar";
			appLauncher = "ivkvm -jar";
		}

		// Execute method
		void Execute(int argc, char* argv[]) {
		
			string process = appLauncher + " " + appExecutable;
			system(process.c_str());
		}
};

// Main method; program entry point
int main(int argc, char* argv[]) {

	ShrinkWrap hostedApp = ShrinkWrap();
	hostedApp.Execute(argc, argv);

	return 0;
}
