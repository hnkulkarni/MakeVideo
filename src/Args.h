/*
 * Args.h
 *
 *  Created on: Feb 19, 2014
 *      Author: hrushi
 */

#ifndef ARGS_H_
#define ARGS_H_

#include "Includes.h"

class Args
{

private:
	/**************************************************************
	 *           Private Functions
	 **************************************************************/
	virtual int ReadProgramPath(  int argc, char* argv[]);
	virtual int Init();
	virtual int AddArgs();
	virtual int ArgCheckNParse( int argc, char* argv[]);



	/**************************************************************
	 *           Private Program Argument Variables
	 **************************************************************/


protected:
	fs::path m_ProgramPath;
	po::options_description m_desc;
	po::variables_map m_vm;

	/**************************************************************
	 *           Add Protected Args
	 **************************************************************/
	virtual int AddProjArgs() = 0; // Every project arguments should its own arguments.

public:
	Args();
	virtual ~Args();

	// Copy Constructor
	Args( const Args& rhsArgs );

	// Assignment Operator
	Args& operator=( const Args& rhsArgs );

	// Helper Function
	virtual int Copy( const Args& rhs );
	virtual int Allocate( const Args& rhs );


	/**************************************************************
	 *           Aux. Member Functions
	 **************************************************************/
	virtual int help() const;
	virtual int BasicParse( int argc, char* argv[] );

	/**************************************************************
	 *           Get Functions
	 **************************************************************/
	virtual string GetProgramPath() const { return m_ProgramPath.string(); }


};

#endif /* ARGS_H_ */
