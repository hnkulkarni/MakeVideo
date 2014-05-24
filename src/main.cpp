/*******************************************************************
 * Function Name: Main
 * Return Type 	: int
 * Created On	: 
 * Created By 	: 
 * Comments		: This is the Main of the Code
 *******************************************************************/
 
#include "Includes.h"
#include "ProjArgs.h"
#include "App.h"

int main( int argc, char* argv[])
{
	ProjArgs args;
	args.Parse(argc, argv);

	App myApp;
	myApp.Run(args);

	return EXIT_SUCCESS;
}

