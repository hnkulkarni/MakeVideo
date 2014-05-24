/*
 * ImagePt.h
 *
 *  Created on: Jan 4, 2013
 *      Author: hrushi
 *
 *      This contains all the functions related to a point on the image
 *      	Example
 *      		1. Distance
 *
 */

#ifndef IMAGEPT_H_
#define IMAGEPT_H_


#include "Includes.h"
#include "VectorOp.h"

class ImagePt {

protected:

	cv::Point2d Pt;

public:
	ImagePt();
	ImagePt(double x, double y);
	virtual ~ImagePt();

	// Copy Constructor
	ImagePt( const ImagePt& rhsImagePt );

	// Assignment Operator
	ImagePt& operator=( const ImagePt& rhsImagePt );
	ImagePt& operator=( const int RHS);

	// Helper Function
	int Copy_ImagePt( const ImagePt& rhsImagePt );
	int Allocate_ImagePt( const ImagePt& rhsImagePt );
	int Init();

	// Operator Overloads
	ImagePt operator+( const ImagePt& rhsImagePt ) const;
	ImagePt operator+( const double d ) const;
	ImagePt operator-( const ImagePt& rhsImagePt ) const;
	ImagePt operator-( const double d ) const;
	ImagePt operator/( const double d) const;
	ImagePt operator*( const double d) const;
	bool operator == ( const ImagePt& rhsImagePt ) const;

	/*
	 * Public Functions
	 */
	double Distance( const ImagePt& Pt2) const;
	double Dot( const ImagePt& Pt2 ) const;
	double Slope( const ImagePt& Pt2 ) const;
	double SlopeAngle( const ImagePt& Pt2 ) const;

	/*
	 * Accessors
	 */
	cv::Point GetPoint() const {cv::Point Temp = Pt; return Temp;}
	int GetX() const { return Pt.x; }
	int GetY() const { return Pt.y; }
	const ImagePt GetUnit( const ImagePt& Pt ) const;

	/*
	 * Mutators
	 */
	int Set_X(int x){ Pt.x = x; return EXIT_SUCCESS; }
	int Set_Y(int y){ Pt.y = y; return EXIT_SUCCESS; }
	int SetPoint( int x, int y) { Pt.x = x; Pt.y = y; return EXIT_SUCCESS;}
	int SwapXY();
	/*
	 *  Public Members
	 */

};

std::istream& operator>>( std::istream& in, ImagePt& RHS);
std::ostream& operator<<(std::ostream& out, const ImagePt& RHS );

#endif /* IMAGEPT_H_ */
