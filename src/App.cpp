/*
 * App.cpp
 *
 *  Created on: Feb 21, 2014
 *      Author: hrushi
 */

#include "App.h"

/*******************************************************************
 * Function Name: App
 * Return Type 	: None
 * Created On	: Feb 21, 2014
 * Created By 	: hrushi
 * Comments		: Comment
 * Arguments	:
 *******************************************************************/
App::App()
{


}

/*******************************************************************
 * Function Name: ~App
 * Return Type 	: None
 * Created On	: Feb 21, 2014
 * Created By 	: hrushi
 * Comments		: Comment
 * Arguments	: None
 *******************************************************************/
App::~App()
{

}


/*******************************************************************
 * Function Name: Run
 * Return Type 	: int
 * Created On	: Feb 21, 2014
 * Created By 	: hrushi
 * Comments		: Runs the program according to the arguments
 * Arguments	: const Args& args
 *******************************************************************/
int App::Run( const ProjArgs& args)
{
	Video oVideo;

	oVideo.BuildVideo(args.GetImgFolderPath());

	return EXIT_SUCCESS;
}


/*****************************************************
 * Function	: App Copy Constructor
 * Date		: Feb 22, 2014
 * Author	: hrushi
 * Comments	:
 * Args		: Const Reference of the second class
 * Return	: Copy Constructors do not return anything
 *****************************************************/
App::App(const App& rhs )
{
	Allocate( rhs );
	Copy( rhs );

}

/*****************************************************
 * Function	: operator =
 * Date		: Feb 22, 2014
 * Author	: hrushi
 * Comments	: Assignment Operator
 * Args		: Const Reference of the second class
 * Return	: Self Pointer
 *****************************************************/
App& App:: operator=( const App& rhs )
{
	Allocate( rhs );
	Copy( rhs );

	return *this;
}

/*****************************************************
 * Function	: Allocate
 * Date		: Feb 22, 2014
 * Author	: hrushi
 * Comments	:
 * Args		: Const Reference of the second class
 * Return	: SUCCESS / FAILURE
 *****************************************************/
int App::Allocate( const App& rhs )
{

	return EXIT_SUCCESS;
}

/*****************************************************
 * Function	: Copy
 * Date		: Feb 22, 2014
 * Author	: hrushi
 * Comments	:
 * Args		: Const Reference of the second class
 * Return	: SUCCESS / FAILURE
 *****************************************************/
int App::Copy( const App& rhs )
{

	return EXIT_SUCCESS;
}



