/*
 * Video.cpp
 *
 *  Created on: Feb 22, 2014
 *      Author: hrushi
 */

#include "Video.h"

Video::Video() {
	// TODO Auto-generated constructor stub

}

Video::~Video() {
	// TODO Auto-generated destructor stub
}

/*****************************************************
 * Function	: Video Copy Constructor
 * Date		: Feb 22, 2014
 * Author	: hrushi
 * Comments	:
 * Args		: Const Reference of the second class
 * Return	: Copy Constructors do not return anything
 *****************************************************/
Video::Video(const Video& rhs )
{
	Allocate( rhs );
	Copy( rhs );

}

/*****************************************************
 * Function	: operator =
 * Date		: Feb 22, 2014
 * Author	: hrushi
 * Comments	: Assignment Operator
 * Args		: Const Reference of the second class
 * Return	: Self Pointer
 *****************************************************/
Video& Video:: operator=( const Video& rhs )
{
	Allocate( rhs );
	Copy( rhs );

	return *this;
}

/*****************************************************
 * Function	: Allocate
 * Date		: Feb 22, 2014
 * Author	: hrushi
 * Comments	:
 * Args		: Const Reference of the second class
 * Return	: SUCCESS / FAILURE
 *****************************************************/
int Video::Allocate( const Video& rhs )
{

	return EXIT_SUCCESS;
}

/*****************************************************
 * Function	: Copy
 * Date		: Feb 22, 2014
 * Author	: hrushi
 * Comments	:
 * Args		: Const Reference of the second class
 * Return	: SUCCESS / FAILURE
 *****************************************************/
int Video::Copy( const Video& rhs )
{

	return EXIT_SUCCESS;
}


/*******************************************************************
 * Function Name: BuildVideo
 * Return Type 	: int
 * Created On	: Feb 22, 2014
 * Created By 	: hrushi
 * Comments		: Build video from all the frames given in the folder
 * Arguments	: const fs::path FolderPath
 *******************************************************************/
int  Video::BuildVideo( const fs::path FolderPath) const
{

	vector<fs::path> vImgList;

	if(fs::exists(FolderPath))
	{
		cout << "Building Video using frames in: " << FolderPath << endl;
		cout << "Files in this folder are " << endl;

		FileSystem::CreateFolder(fs::path( FolderPath.string() + "/LLVS" ));
		FileSystem::CreateFolder(fs::path( FolderPath.string() + "/LLVS/data" ));

		string VideoPath = FolderPath.string() + "/LLVS/" + FolderPath.filename().string() + ".avi";
		cout << VideoPath << endl;

		if(fs::exists(fs::path(VideoPath)))
		{
			cout << "Removing " << VideoPath << endl;
			fs::remove(fs::path(VideoPath));
		}

		vImgList = FileSystem::ListAllImagesInFolder(FolderPath);
		ColorImg SampleFrame(vImgList.at(0));
		cv::VideoWriter VW;
		VW.open(VideoPath, CV_FOURCC('F','L','V','1'), 25, SampleFrame.GetSize(), true );

		if(!VW.isOpened())
		{
			cerr << "Cannot open video file " <<  VideoPath << endl;
			exit(ERR_INVALID_PATH);
		}

		UINT FrameCount = 0;

		for(auto Img : vImgList)
		{
			ColorImg Frame(Img);
			VW << Frame.GetDataRef().clone();

			FrameCount++;

			UINT OnePercent = (double)vImgList.size()/100;

			if(!(FrameCount % OnePercent ))
			{
				cout << ".";
				cout.flush();
			}
		}

		cout << endl;
		cout << "Finished Writing " << FrameCount << " Frames to "<< VideoPath << endl;

		VW.release();
	}
	else
	{
		cerr << "Path: " << FolderPath << " does not exist" << endl;
		exit(ERR_INVALID_PATH);
	}

	return EXIT_SUCCESS;
}


/*******************************************************************
 * Function Name: ReadVideo
 * Return Type 	: int
 * Created On	: Feb 23, 2014
 * Created By 	: hrushi
 * Comments		: Read the video from the given path
 * Arguments	: const fs::path VideoPath
 *******************************************************************/
int Video::ReadVideo( const fs::path VideoPath) const
{

	cv::VideoCapture inputVideo(VideoPath.string());        // Open input
	if ( !inputVideo.isOpened())
	{
		cout  << "Could not open the input video." << VideoPath << endl;
		return -1;
	}

	while(true)
	{
		cv::Mat src;
		inputVideo >> src;

		ColorImg NewFrame(src);
		NewFrame.Display(DISP_DELAY);
	}


	inputVideo.release();

	return EXIT_SUCCESS;
}
