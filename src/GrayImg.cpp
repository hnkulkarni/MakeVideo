/*
 * GrayImg.cpp
 *
 *  Created on: Jan 20, 2013
 *      Author: hrushi
 */

#include "GrayImg.h"

/*******************************************************************
 * Function Name: GrayImg
 * Return Type 	: None
 * Created On	: Oct 10, 2013
 * Created By 	: hrushi
 * Comments		: Comment
 * Arguments	:
 *******************************************************************/
GrayImg::GrayImg()
{
	Initializer();
}


/*******************************************************************
 * Function Name: GrayImg
 * Return Type 	: None
 * Created On	: Oct 10, 2013
 * Created By 	: hrushi
 * Comments		: Constructor with arguments
 * Arguments	:
 *******************************************************************/
GrayImg::GrayImg(UINT numRows, UINT numCols)
{
	SetImageType();

	m_nrows = numRows;
	m_ncols = numCols;

	m_data.create(numRows, numCols, CV_8UC1);

	m_data = COLOR_BLACK;
}

/*******************************************************************
 * Function Name: ~GrayImg
 * Return Type 	: None
 * Created On	: Oct 10, 2013
 * Created By 	: hrushi
 * Comments		: Comment
 * Arguments	: None
 *******************************************************************/
GrayImg::~GrayImg()
{

}

/**********************************************************************
 * Function Name: GrayImg
 * Date 		: Jan 20, 2013
 * Author		: hrushi
 * Comments		: Copy Constructor
 * Args			:
 * ToDo			:
 **********************************************************************/
GrayImg::GrayImg( const GrayImg& rhsGrayImg ) // Initializer copied in the Copy_GrayImg
{
	Initializer();
	Allocate_GrayImg( rhsGrayImg );
	Copy_GrayImg( rhsGrayImg );
}


/*******************************************************************
 * Function Name: GrayImg
 * Return Type 	:
 * Created On	: Jun 17, 2013
 * Created By 	: hrushi
 * Comments		: Enables the image to be set even path is passed
 * Arguments	: const fs::path FilePath
 *******************************************************************/
GrayImg::GrayImg( const fs::path FilePath)
{
	Initializer();
	Load(FilePath);
}



/**********************************************************************
 * Function Name: operator
 * Date 		: Jan 20, 2013
 * Author		: hrushi
 * Comments		: Assignment Operator
 * ToDo			:
 **********************************************************************/
const GrayImg& GrayImg :: operator=( const GrayImg & rhsGrayImg )
{

	Allocate_GrayImg( rhsGrayImg );
	Copy_GrayImg( rhsGrayImg );

	return *this;
}

/*******************************************************************
 * Function Name: operator+
 * Return Type 	: const GrayImg&
 * Created On	: Jul 8, 2013
 * Created By 	: hrushi
 * Comments		: Added two gray images and returns a new gray image
 * Arguments	: const GrayImg& rhsGrayImg
 *******************************************************************/
const GrayImg GrayImg::operator+( const GrayImg& rhsGrayImg) const
{
	GrayImg RetGrayImg = *this; // Initialize the size of this Image

	for( int i = 0; i < m_data.rows; i++)
	{
		for( int j = 0; j < m_data.cols; j++)
		{
			int I1 = m_data.at<uchar>(i,j);
			int I2 = rhsGrayImg.m_data.at<uchar>(i,j);
			int iTemp = I1 + I2 ;

			if( iTemp > MAX_GRAY_VALUE )
			{
				iTemp = MAX_GRAY_VALUE;
			}

			RetGrayImg.m_data.at<uchar>(i,j) = iTemp;
		}
	}

	return RetGrayImg;
}


/**********************************************************************
 * Function Name: Copy_GrayImg
 * Date 		: Jan 20, 2013
 * Author		: hrushi
 * Comments		: Helper Function to Copy all the Data
 * ToDo			:
 **********************************************************************/
int GrayImg:: Copy_GrayImg(  const GrayImg & rhsGrayImg  )
{

	CImage::operator =( rhsGrayImg );

	return EXIT_SUCCESS;
}



/*******************************************************************
 * Function Name: Initalizer
 * Return Type 	: int
 * Created On	: Jun 20, 2013
 * Created By 	: hrushi
 * Comments		: Implements the Initializer for a Class
 * Arguments	:
 *******************************************************************/
int GrayImg::Initializer( )
{

	SetImageType();

	return EXIT_SUCCESS;
}

/**********************************************************************
 * Function Name: Allocate_GrayImg
 * Date 		: Jan 20, 2013
 * Author		: hrushi
 * Comments		: Helper Function to Allocate all the Data
 * ToDo			:
 **********************************************************************/
int GrayImg:: Allocate_GrayImg(  const GrayImg & rhsGrayImg  )
{

	return EXIT_SUCCESS;
}



/*******************************************************************
 * Function Name: at
 * Return Type 	: unsigned int
 * Created On	: Jan 20, 2013
 * Created By 	: hrushi
 * Comments		: Returns the gray value of the image at the given pixel location
 * Arguments	: unsigned int i, unsigned int j
 *******************************************************************/
uchar GrayImg::at( unsigned int i, unsigned int j) const
{
	uchar Val;

	Val = m_data.at< uchar >(i,j);

	return Val;
}



/*******************************************************************
 * Function Name: at
 * Return Type 	: unsigned int
 * Created On	: Jan 20, 2013
 * Created By 	: hrushi
 * Comments		: Returns the Gray Value at the given Point.
 * Arguments	: cv::Point Pt
 *******************************************************************/
uchar GrayImg::at( const ImagePt ImgPt) const
{
	return at(ImgPt.GetY(), ImgPt.GetX()); // Swapping X and Y
}

/*******************************************************************
 * Function Name: Cvt2Color
 * Return Type 	: ColorImg
 * Created On	: Feb 10, 2013
 * Created By 	: hrushi
 * Comments		: Convert gray channel into three repeated channels in color
 * Arguments	:
 *******************************************************************/
ColorImg GrayImg::Cvt2ColorCompatible( ) const
{
	Mat ImTemp(m_data.rows, m_data.cols, CV_8UC3);
	ColorImg ClrImg;

	for( int i = 0; i < m_data.rows; i++)
	{
		for( int j = 0; j < m_data.cols; j++)
		{
			ImTemp.at<Vec3b>(i,j)[0] = m_data.at<uchar>(i,j);
			ImTemp.at<Vec3b>(i,j)[1] = m_data.at<uchar>(i,j);
			ImTemp.at<Vec3b>(i,j)[2] = m_data.at<uchar>(i,j);
		}
	}

	ClrImg.SetImage(ImTemp, m_ImagePath);
	return ClrImg;
}


/*******************************************************************
 * Function Name: Threshold
 * Return Type 	: const GrayImg
 * Created On	: Jun 18, 2013
 * Created By 	: hrushi
 * Comments		: Thresholds the Gray Images
 * Arguments	: const char ThresholdVal
 *******************************************************************/
const GrayImg GrayImg::Threshold( const char ThresholdVal)
{

	return *this;
}


/*******************************************************************
 * Function Name: Fill
 * Return Type 	: GrayImg
 * Created On	: Nov 24, 2013
 * Created By 	: hrushi
 * Comments		: Fills the holes in the foreground region
 * Arguments	:
 *******************************************************************/
const GrayImg GrayImg::Fill( )
{
	vector< vector<cv::Point> > contours;
	vector<cv::Vec4i> hierarchy;
	cv::findContours(m_data, contours, hierarchy, CV_RETR_TREE, CV_CHAIN_APPROX_SIMPLE, cv::Point(0,0));

	/// Draw contours
	Mat drawing = Mat::zeros( m_data.size(), CV_8UC3 );

	ColorImg Temp;

	double ImgArea = GetNumRows() * GetNumCols();
	double MaxCntrArea = 0;

	UINT FillCtrIndx = 0;

	for(UINT i = 0; i < contours.size(); i++ )
	{
		cv::Moments mu = moments(contours[i], false);
		double CtrArea = mu.m00;
		//---------- Select the largest contour, which has area greater than 0, and less than Image Area ---------- //
		if( ( CtrArea > 0) && ( CtrArea > MaxCntrArea ) && (CtrArea < ImgArea))
		{
			FillCtrIndx = i;
			MaxCntrArea = CtrArea;
		}
	}

	drawContours( drawing, contours, FillCtrIndx, COLOR_WHITE, CV_FILLED, 8, hierarchy, 0, cv::Point() );

	Temp.SetImage(drawing);
	*this = Temp.Cvt2Gray();

	return *this;
}


/*******************************************************************
 * Function Name: SumAllPixVals
 * Return Type 	: UINT
 * Created On	: Nov 24, 2013
 * Created By 	: hrushi
 * Comments		: Performs summition of all the pixels
 * Arguments	:
 *******************************************************************/
UINT GrayImg::SumAllPixVals( ) const
{
	UINT Sum = 0;

	for( UINT i = 0; i < GetNumRows(); i++ )
	{
		for(UINT j = 0; j < GetNumCols(); j++ )
		{
			Sum += at(i,j);
		}
	}

	return Sum;
}
