/*
 * ProjArgs.cpp
 *
 *  Created on: Feb 21, 2014
 *      Author: hrushi
 */

#include "ProjArgs.h"

/*******************************************************************
 * Function Name: ProjArgs
 * Return Type 	: None
 * Created On	: Feb 21, 2014
 * Created By 	: hrushi
 * Comments		: Comment
 * Arguments	:
 *******************************************************************/
ProjArgs::ProjArgs()
{

	AddProjArgs();

}


/*******************************************************************
 * Function Name: ~ProjArgs
 * Return Type 	: None
 * Created On	: Feb 21, 2014
 * Created By 	: hrushi
 * Comments		: Comment
 * Arguments	: None
 *******************************************************************/
ProjArgs::~ProjArgs() {
	// TODO Auto-generated destructor stub
}

/*****************************************************
 * Function	: ProjArgs Copy Constructor
 * Date		: Feb 21, 2014
 * Author	: hrushi
 * Comments	:
 * Args		: Const Reference of the second class
 * Return	: Copy Constructors do not return anything
 *****************************************************/
ProjArgs::ProjArgs(const ProjArgs& rhs )
{
	Allocate( rhs );
	Copy( rhs );

}

/*****************************************************
 * Function	: operator =
 * Date		: Feb 21, 2014
 * Author	: hrushi
 * Comments	: Assignment Operator
 * Args		: Const Reference of the second class
 * Return	: Self Pointer
 *****************************************************/
ProjArgs& ProjArgs:: operator=( const ProjArgs& rhs )
{
	Allocate( rhs );
	Copy( rhs );

	return *this;
}

/*****************************************************
 * Function	: Allocate
 * Date		: Feb 21, 2014
 * Author	: hrushi
 * Comments	:
 * Args		: Const Reference of the second class
 * Return	: SUCCESS / FAILURE
 *****************************************************/
int ProjArgs::Allocate( const ProjArgs& rhs )
{

	return EXIT_SUCCESS;
}

/*****************************************************
 * Function	: Copy
 * Date		: Feb 21, 2014
 * Author	: hrushi
 * Comments	:
 * Args		: Const Reference of the second class
 * Return	: SUCCESS / FAILURE
 *****************************************************/
int ProjArgs::Copy( const ProjArgs& rhs )
{
	m_ImgFolderPath = rhs.m_ImgFolderPath;

	return EXIT_SUCCESS;
}



/*******************************************************************
 * Function Name: AddProjArgs
 * Return Type 	: int
 * Created On	: Feb 21, 2014
 * Created By 	: hrushi
 * Comments		: Add the Project Arguments over here
 * Arguments	:
 *******************************************************************/
int ProjArgs::AddProjArgs( )
{
	m_desc.add_options()
			("folderpath", po::value<fs::path>(), "Folder Path containing all the images")

			//ADD NEW ARGUMENTS OVER HERE
			;


	return EXIT_SUCCESS;
}


/*******************************************************************
 * Function Name: Parse
 * Return Type 	: int
 * Created On	: Feb 21, 2014
 * Created By 	: hrushi
 * Comments		: Parsing the arguments
 * Arguments	: int argc, char* argv[]
 *******************************************************************/
int ProjArgs::Parse( int argc, char* argv[])
{

	BasicParse(argc, argv);
	ArgUsage();

	return EXIT_SUCCESS;
}


/*******************************************************************
 * Function Name: ArgUsage
 * Return Type 	: int
 * Created On	: Feb 21, 2014
 * Created By 	: hrushi
 * Comments		: All the options used
 * Arguments	:
 *******************************************************************/
int ProjArgs::ArgUsage( )
{

	try
	{
		if(m_vm.count("help"))
		{
			help();
		}
		else if( m_vm.count("folderpath"))
		{
			m_ImgFolderPath = m_vm.at("folderpath").as<fs::path>();
		}

	}
	catch( const boost::bad_any_cast& ex)
	{
		cerr << "Error reading arguments" << endl;
		help();

		cerr << ex.what() << endl;
	}

	return EXIT_SUCCESS;
}
