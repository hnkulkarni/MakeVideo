/*
 * Video.h
 *
 *  Created on: Feb 22, 2014
 *      Author: hrushi
 */

#ifndef VIDEO_H_
#define VIDEO_H_

#include "Includes.h"
#include "VectorOp.h"
#include "ColorImg.h"

class Video
{
private:
	// Helper Function
	virtual int Copy( const Video& rhs );
	virtual int Allocate( const Video& rhs );

public:
	Video();
	virtual ~Video();

	// Copy Constructor
	Video( const Video& rhsVideo );

	// Assignment Operator
	Video& operator=( const Video& rhsVideo );

	int BuildVideo(const fs::path FolderPath) const;
	int ReadVideo(const fs::path VideoPath ) const;

};

#endif /* VIDEO_H_ */
