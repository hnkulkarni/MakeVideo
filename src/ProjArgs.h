/*
 * ProjArgs.h
 *
 *  Created on: Feb 21, 2014
 *      Author: hrushi
 */

#ifndef PROJARGS_H_
#define PROJARGS_H_

#include "Args.h"

class ProjArgs: public Args
{

/**************************************************************
*           Private
**************************************************************/
private:
	// Helper Function
	virtual int Copy( const ProjArgs& rhs );
	virtual int Allocate( const ProjArgs& rhs );


/**************************************************************
 *           Protected
 **************************************************************/
protected:

	virtual int AddProjArgs();
	virtual int ArgUsage();


	fs::path m_ImgFolderPath; //Contains the path of the folder which has all the image.

/**************************************************************
 *           Public
 **************************************************************/
public:
	ProjArgs();
	virtual ~ProjArgs();

	// Copy Constructor
	ProjArgs( const ProjArgs& rhsProjArgs );

	// Assignment Operator
	ProjArgs& operator=( const ProjArgs& rhsProjArgs );

	virtual int Parse(int argc, char* argv[]);



	/**************************************************************
	 *           All Get Functions
	 **************************************************************/
	virtual const fs::path GetImgFolderPath() const { return m_ImgFolderPath; }




};

#endif /* PROJARGS_H_ */
