/*
 * Constants.h
 *
 *  Created on: Dec 31, 2012
 *      Author: hrushi
 */

#ifndef CONSTANTS_H_
#define CONSTANTS_H_

#include "CPPIncludes.h"

const char STARS[256] 				= "**********************************************";
const char FEW_STARS[256] 			= "*********";

/**************************************************************
 *           MATH Constants
 **************************************************************/
const double PI = 22/7;



/**************************************************************
 *           Time Constants
 **************************************************************/
const unsigned int SEC 				= 1000;
const int SOME_LARGE_VALUE 			= 1e8;
const int SOME_SMALL_VALUE 			= 1e-10;
const double HALF_SECOND			= 0.5;
const int ONE_SECOND				= 1;
const int THOUSAND_MILLI_SEC		= 1e3;
const double DISP_DELAY				= 0.1 *  ONE_SECOND;
const double DISP_FONT_SCALE		= 0.3;  				// Scales the font by the given size
const double DISP_WAIT_FOR_KEY		= 0;

/**************************************************************
 *           Image Constants
 **************************************************************/
const int MAX_GRAY_VALUE 			= 255;
const int MAX_GRAY_VALUE_ROUND_OVER = -1;


#endif /* CONSTANTS_H_ */
