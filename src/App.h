/*
 * App.h
 *
 *  Created on: Feb 21, 2014
 *      Author: hrushi
 */

#ifndef APP_H_
#define APP_H_

#include "Includes.h"
#include "ProjArgs.h"
#include "Video.h"

class App
{

private:
	// Helper Function
	virtual int Copy( const App& rhs );
	virtual int Allocate( const App& rhs );

public:
	App();
	virtual ~App();


	virtual int Run(const ProjArgs& args );


	// Copy Constructor
	App( const App& rhsApp );

	// Assignment Operator
	App& operator=( const App& rhsApp );


};

#endif /* APP_H_ */
