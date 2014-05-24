/*
 * Typedefs.h
 *
 *  Created on: Jan 13, 2013
 *      Author: hrushi
 */

#ifndef TYPEDEFS_H_
#define TYPEDEFS_H_

#include "CPPIncludes.h"

typedef unsigned int UINT;
typedef unsigned long * ULONG_PTR;
typedef unsigned char WCHAR;
typedef const unsigned int CUINT;
typedef vector<double> VDOUBLE;
typedef vector< vector<double> > VVDOUBLE;
typedef std::pair<int, double> pr_score;

typedef std::map<string, vector<string> > mp_Str_vStr;
typedef std::map<UINT, string> mp_UINT_Str;

#endif /* TYPEDEFS_H_ */
