/*
 * ColorImg.h
 *
 *  Created on: Jan 20, 2013
 *      Author: hrushi
 */

#ifndef COLORIMG_H_
#define COLORIMG_H_

#include "Includes.h"

#include "CImage.h"
#include "GrayImg.h"
class GrayImg; // Partial Declaration

class ColorImg: public CImage {

private:
	virtual int Initializer();

	virtual int BuildImage(UINT nrows, UINT ncols, cv::Scalar InitColor);

public:

	/***********************************************************
	 * 					House Keeping Functions
	 ***********************************************************/
	ColorImg();
	ColorImg(const cv::Mat& rhsMat );
	ColorImg(UINT nrows, UINT ncols);
	ColorImg(UINT nrows, UINT ncols, cv::Scalar InitColor);
	virtual ~ColorImg();

	// Copy Constructor
	ColorImg( const ColorImg& rhsColorImg );

	//
	ColorImg( const fs::path FilePath );

	// Assignment Operator
	ColorImg& operator=( const ColorImg& rhsColorImg );

	// Helper Function
	int Copy_ColorImg( const ColorImg& rhsColorImg );
	int Allocate_ColorImg( const ColorImg& rhsColorImg );


	/***********************************************************
	 * 				   Modifiers
	 ***********************************************************/
	//Loads a Image in Color
	virtual int SetImageType() { m_ImageType = IMAGE_TYPE_COLOR; return m_ImageType;}
	virtual int Mask( const GrayImg& Msk );

	/**************************************************************
	 *           Accessors
	 **************************************************************/
	// Convert the data to Gray
	virtual GrayImg Cvt2Gray() const;
	virtual cv::Vec3b at(const unsigned int i, const unsigned int j) const;
	virtual int at(unsigned int i, unsigned int j, char B, char G, char R);
	virtual int at(unsigned int i, unsigned int j, const cv::Vec3b& BGR ); // Sets the Value at the given pixel

};

#endif /* COLORIMG_H_ */
