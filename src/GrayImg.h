/*
 * GrayImg.h
 *
 *  Created on: Jan 20, 2013
 *      Author: hrushi
 */

#ifndef GRAYIMG_H_
#define GRAYIMG_H_

#include "Includes.h"

#include "CImage.h"
#include "ImagePt.h"
#include "ColorImg.h"

class ColorImg; //Partial Declaration

class GrayImg: public CImage
{
private:
	virtual int Initializer();

public:

	/**********************************************
	 * 			Code House Keeping
	 **********************************************/
	GrayImg();
	GrayImg(UINT numRows, UINT numCols);
	virtual ~GrayImg();

	// Copy Constructor
	GrayImg( const GrayImg& rhsGrayImg );


	// Copy Constructor for String
	GrayImg( const fs::path FilePath );

	// Assignment Operator
	virtual const GrayImg& operator=( const GrayImg& rhsGrayImg );
	virtual const GrayImg operator+( const GrayImg& rhsGrayImg ) const;


	// Helper Function
	virtual int Copy_GrayImg( const GrayImg& rhsGrayImg );
	virtual int Allocate_GrayImg( const GrayImg& rhsGrayImg );


	/**********************************************
	 * 				Accessors
	 **********************************************/
	virtual uchar at( unsigned int i, unsigned int j ) const;
	virtual uchar at( const ImagePt ImgPt ) const;


	/**************************************************************
	 *           Mutators
	 **************************************************************/
	virtual int SetImageType() { m_ImageType = IMAGE_TYPE_GRAY; return m_ImageType;}
	virtual const GrayImg Threshold( const char ThresholdVal );
	virtual const GrayImg Fill();


	/**********************************************
	 * 			 Generic Functions
	 **********************************************/
	virtual ColorImg Cvt2ColorCompatible() const;
	virtual UINT SumAllPixVals() const;

};

#endif /* GRAYIMG_H_ */
