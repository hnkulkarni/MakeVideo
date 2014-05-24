/*
 * StringOp.h
 *
 *  Created on: Feb 4, 2013
 *      Author: hrushi
 */

#ifndef STRINGOP_H_
#define STRINGOP_H_

#include "CPPIncludes.h"
#include "Boost.h"
#include "OpenCV.h"
#include "Errors.h"
#include "Defines.h"
#include "Constants.h"
#include "Typedefs.h"

template<typename T>

class StringOp
{
public:
	static T GetUpper( const T& element );
	static T GetNonWhiteSpace( const unsigned int index, const T& line );
	static const string GetString( const T& element );
};




/*******************************************************************
 * Function Name: FirstNonWhiteSpace
 * Return Type 	: T
 * Created On	: Feb 24, 2013
 * Created By 	: hrushi
 * Comments		: Returns the <n>th non white space character
 * Arguments	: T
 *******************************************************************/
template<typename T>
T StringOp<T>::GetNonWhiteSpace(  const unsigned int index, const T& line )
{
	T NonWhiteSpace;

	std::istringstream iss;
	iss.str(line);

	for( unsigned int iCounter = 0; iCounter <= index; iCounter++ )
	{
		iss >> NonWhiteSpace;

		if( iCounter == index )
		{
			break;
		}

	}

	return NonWhiteSpace;
}


/*******************************************************************
 * Function Name: GetString
 * Return Type 	: string
 * Created On	: Feb 4, 2013
 * Created By 	: hrushi
 * Comments		: returns the string for the given recursive iterator
 * Arguments	: const T& type
 *******************************************************************/
template< typename T>
const string StringOp<T>::GetString( const T& element )
{

	std::stringstream ss;
	ss << element;

	string Temp = ss.str();

	return Temp;
}


/*******************************************************************
 * Function Name: GetUpper
 * Return Type 	: string
 * Created On	: Feb 10, 2013
 * Created By 	: hrushi
 * Comments		: Converts the given string to upper case
 * Arguments	: const T& element
 *******************************************************************/
template< typename T >
T StringOp<T>::GetUpper( const T& element)
{
	T Upper;

	Upper.resize( element.size() );
	std::transform(element.begin(), element.end(), Upper.begin(), ::toupper );

	return Upper;
}



/*******************************************************************
 * Function Name: GetValueInType
 * Return Type 	: RetType
 * Created On	: Feb 24, 2013
 * Created By 	: hrushi
 * Comments		: Extracts the type from the given string
 * Arguments	: const string& str, RetType& elem
 *******************************************************************/
 template<typename RetType>
 RetType GetValueInType(  const string& str)
 {
	 RetType elem;

	 std::istringstream iss;
	 iss.exceptions( std::ios::failbit | std::ios::badbit );

	 try
	 {
		 iss.str(str);
		 iss >> elem;
	 }
	 catch( const std::ios::failure &e )
	 {
		 cerr << "Cannot convert the string into the required datatype " << endl;
		 throw ERR_TYPE_MISMATCH;
	 }

	 return elem;
 }


 /*******************************************************************
  * Function Name: GetValueInType
  * Return Type 	: RetType
  * Created On	: Feb 24, 2013
  * Created By 	: hrushi
  * Comments		: Extracts the type from the given string
  * Arguments	: const string& str, RetType& elem
  *******************************************************************/
  template<typename RetType>
  RetType GetValueInType( unsigned int index,  const string& str)
  {
 	 const string Temp = StringOp<string>::GetNonWhiteSpace(index, str);
 	 RetType elem = GetValueInType<RetType>(Temp);

 	 return elem;
  }

#endif /* STRINGOP_H_ */
