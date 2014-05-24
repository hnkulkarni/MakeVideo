/*
 * Args.cpp
 *
 *  Created on: Feb 19, 2014
 *      Author: hrushi
 */

#include "Args.h"

/*******************************************************************
 * Function Name: Args
 * Return Type 	: None
 * Created On	: Feb 19, 2014
 * Created By 	: hrushi
 * Comments		: Comment
 * Arguments	:
 *******************************************************************/
Args::Args()
{
	Init();
	AddArgs();

}


/*******************************************************************
 * Function Name: ~Args
 * Return Type 	: None
 * Created On	: Feb 19, 2014
 * Created By 	: hrushi
 * Comments		: Comment
 * Arguments	: None
 *******************************************************************/
Args::~Args()
{


}


/*****************************************************
 * Function	: Args Copy Constructor
 * Date		: Feb 19, 2014
 * Author	: hrushi
 * Comments	:
 * Args		: Const Reference of the second class
 * Return	: Copy Constructors do not return anything
 *****************************************************/
Args::Args(const Args& rhs )
{
	Allocate( rhs );
	Copy( rhs );

}

/*****************************************************
 * Function	: operator =
 * Date		: Feb 19, 2014
 * Author	: hrushi
 * Comments	: Assignment Operator
 * Args		: Const Reference of the second class
 * Return	: Self Pointer
 *****************************************************/
Args& Args:: operator=( const Args& rhs )
{
	Allocate( rhs );
	Copy( rhs );

	return *this;
}

/*****************************************************
 * Function	: Allocate
 * Date		: Feb 19, 2014
 * Author	: hrushi
 * Comments	:
 * Args		: Const Reference of the second class
 * Return	: SUCCESS / FAILURE
 *****************************************************/
int Args::Allocate( const Args& rhs )
{

	return EXIT_SUCCESS;
}

/*****************************************************
 * Function	: Copy
 * Date		: Feb 19, 2014
 * Author	: hrushi
 * Comments	:
 * Args		: Const Reference of the second class
 * Return	: SUCCESS / FAILURE
 *****************************************************/
int Args::Copy( const Args& rhs )
{

	m_ProgramPath 	= rhs.m_ProgramPath;

	return EXIT_SUCCESS;
}



/*******************************************************************
 * Function Name: Init
 * Return Type 	: int
 * Created On	: Feb 19, 2014
 * Created By 	: hrushi
 * Comments		: Initializes all the functions members in the class
 * Arguments	:
 *******************************************************************/
int Args::Init( )
{


	return EXIT_SUCCESS;
}



/*******************************************************************
 * Function Name: AddArgs
 * Return Type 	: int
 * Created On	: Feb 19, 2014
 * Created By 	: hrushi
 * Comments		: Add Arguments
 * Arguments	:
 *******************************************************************/
int Args::AddArgs( )
{

	m_desc.add_options()
				("help,h", 				"produce help message")

			//(" ADD NEW OPTIONS OVER HERE Before the Semi Colon ")
			;

	return EXIT_SUCCESS;
}


/*******************************************************************
 * Function Name: ReadProgramPath
 * Return Type 	: int
 * Created On	: Feb 23, 2013
 * Created By 	: hrushi
 * Comments		: Reads the program path. This is the zero-th argument
 * Arguments	: int argc, char* argv[]
 *******************************************************************/
int Args::ReadProgramPath(  int argc, char* argv[])
{
	string ProgramPath( argv[0]);
	m_ProgramPath = ProgramPath;

	return EXIT_SUCCESS;
}

/*******************************************************************
 * Function Name: BasicParse
 * Return Type 	: int
 * Created On	: Feb 19, 2014
 * Created By 	: hrushi
 * Comments		: Parse the arguments, print the help text if nothing is provided
 * Arguments	: int argc, char* argv[]
 *******************************************************************/
int Args::BasicParse( int argc, char* argv[])
{

	ReadProgramPath(argc, argv);
	ArgCheckNParse(argc, argv);

	return EXIT_SUCCESS;
}

/*******************************************************************
 * Function Name: ArgCheckNParse
 * Return Type 	: int
 * Created On	: Feb 19, 2014
 * Created By 	: hrushi
 * Comments		: Check and Parse the Arguments
 * Arguments	: int argc, char* argv[]
 *******************************************************************/
int Args::ArgCheckNParse( int argc, char* argv[])
{

	try
	{
		po::store(po::parse_command_line(argc, argv, m_desc), m_vm);
		po::notify(m_vm);
	}
	catch(const boost::bad_any_cast& e)
	{
		cerr << "Improper Arguments, please check. The Allowed ";
		help();

		exit(ERR_INVALID_ARGS);
	}

	if( argc < 2)
	{
		help();
		exit(ERR_INVALID_ARGS);

	}

	return EXIT_SUCCESS;
}

/*******************************************************************
 * Function Name: help
 * Return Type 	: int
 * Created On	: Feb 2, 2013
 * Created By 	: hrushi
 * Comments		: Prints the Help Text
 * Arguments	:
 *******************************************************************/
int Args::help( ) const
{

	cout << "See All Arguments Below" << endl;
	cout << m_desc << endl;

	return EXIT_SUCCESS;
}

