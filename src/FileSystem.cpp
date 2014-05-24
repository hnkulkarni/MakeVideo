/*
 * FileSystem.cpp
 *
 *  Created on: Feb 13, 2013
 *      Author: hrushi
 */

#include "FileSystem.h"

FileSystem::FileSystem()
{
	// TODO Auto-generated constructor stub

}

FileSystem::~FileSystem()
{
	// TODO Auto-generated destructor stub
}


/*******************************************************************
 * Function Name: ListAllImagesToWork
 * Return Type 	: vector<fs::path>
 * Created On	: Jun 15, 2013
 * Created By 	: hrushi
 * Comments		: List all the images in the folder under the TrackFolder Name.
 * Arguments	: 	1. FolderPath to Search,
 * 					2. Name of the Track folder, typically track.
 *******************************************************************/
vector<fs::path> FileSystem::ListAllTrackImages( const fs::path FolderPath, const string TrackFldrName )
{
	vector<fs::path> ImgList;
	string CurrentDir;

	for (fs::recursive_directory_iterator end, dir(FolderPath); dir != end; ++dir)
	{
		fs::path p = *dir;

		CurrentDir = p.parent_path().filename().string();
		size_t foundLoc  = CurrentDir.find(TrackFldrName);
		string ext = p.extension().string();

		// Given file is an image and is in the track folder.
		if( isImageExt(ext) &&  (foundLoc < CurrentDir.length()) )
		{
			ImgList.push_back(p);
		}

	}

	return ImgList;
}

/*******************************************************************
 * Function Name: isImageExt
 * Return Type 	: bool
 * Created On	: Jun 15, 2013
 * Created By 	: hrushi
 * Comments		: Is Image Extension
 * Arguments	: const string sExt
 *******************************************************************/
bool FileSystem::isImageExt( const string TestExt)
{
	vector<string> ValidExts = { ".png", ".jpeg", ".jpg" };

	for(auto Ext : ValidExts)
	{
		if( TestExt.compare( Ext ) == 0)
		{
			return true;
		}
	}

	return false;
}

/*******************************************************************
 * Function Name: GetMaskImgPath
 * Return Type 	: const vector<fs::path>
 * Created On	: Jun 16, 2013
 * Created By 	: hrushi
 * Comments		: Calculates the MaskImage File Name for every track file name in the vector
 * Arguments	: const string MaskFolderName, 	const fs::path& TrackPath, const string TrackFolderName
 *******************************************************************/
const vector<fs::path> FileSystem::GetMaskImgPathVector( const string MaskFolderName, 	const vector<fs::path>& vTrackPath, const string TrackFolderName)
{
	vector<fs::path> vMaskPath;
	fs::path MaskPath;

	for(auto Path : vTrackPath )
	{
		MaskPath = GetMaskImgPath( MaskFolderName, Path, TrackFolderName );
		vMaskPath.push_back( MaskPath );
	}

	return vMaskPath;
}



/*******************************************************************
 * Function Name: GetMaskImgPath
 * Return Type 	: fs::path
 * Created On	: Jun 16, 2013
 * Created By 	: hrushi
 * Comments		: For the given path in the Track folder, it returns the corresponding mask path
 * Arguments	: const string MaskFolderName, 	const fs::path& CurrentPath, const string TrackFolderName
 *******************************************************************/
const fs::path FileSystem::GetMaskImgPath( const string MaskFolderName, const fs::path TrackPath, const string TrackFolderName)
{
	fs::path MaskPath;

	string Path = TrackPath.parent_path().string();

	const size_t FoundLoc = Find(TrackPath, TrackFolderName);

	string sMaskImgPath;

	sMaskImgPath.assign(Path, 0, FoundLoc);
	sMaskImgPath = sMaskImgPath + MaskFolderName + "/mask_" + TrackPath.filename().string();

	MaskPath = sMaskImgPath;

	if( fs::exists( MaskPath ))
	{
		return MaskPath;
	}
	else
	{
		cerr << "Corresponding Mask Image not present at the given location " << endl;
		cerr << "Track Image Path: " << TrackPath << endl;
		cerr << "Mask  Image Path: " << MaskPath <<  endl;
		throw ERR_INVALID_PATH;
	}

	return MaskPath;
}


/*******************************************************************
 * Function Name: ListAllImagesInFolder
 * Return Type 	: int
 * Created On	: Feb 13, 2013
 * Created By 	: hrushi
 * Comments		: Lists all images and folders inside the given folder.
 * Arguments	: const string FolderPath
 *******************************************************************/
vector<fs::path> FileSystem::ListAllImagesInFolder( const fs::path FolderPath)
{
	vector<fs::path> LS;

	for ( fs::directory_iterator end, dir( FolderPath ); dir != end; ++dir )
	{
		fs::path p = *dir;

		if(fs::is_regular_file(p))
		{
			LS.push_back(p);
		}
	}

	//So that all the files are in order
	std::sort(LS.begin(), LS.end() );

	return LS;
}

/*******************************************************************
 * Function Name: NameFilter_hasFolder
 * Return Type 	: size_t
 * Created On	: Feb 16, 2013
 * Created By 	: hrushi
 * Comments		: If the file has any given folder has parent in its path
 * Arguments	: fs::path& ImPath, const string FolderName
 *******************************************************************/
size_t FileSystem::Find( const fs::path& CompletePath, const string FolderName)
{
	size_t foundLoc;

	string FileName = CompletePath.filename().string();
	if( FileName.length() ) // Any valid Length
	{
		StringOp<string> oStr;
		string FILENAME = oStr.GetUpper(FileName);
		string CMPR_FOLDER_NAME = oStr.GetUpper( FolderName );

		string FILEPATH = oStr.GetUpper(CompletePath.string());
		foundLoc = FILEPATH.find(CMPR_FOLDER_NAME );


		if ( FILENAME == CMPR_FOLDER_NAME )
		{
			if( foundLoc < FILEPATH.length() )
			{
				return foundLoc;
			}
		}
		else
		{
			foundLoc = Find(CompletePath.parent_path(), FolderName);
		}

	}
	else
	{
		return 0;
	}

	return foundLoc;

}


/*******************************************************************
 * Function Name: NameFilter_hasFolder
 * Return Type 	: vector<string>
 * Created On	: Feb 16, 2013
 * Created By 	: hrushi
 * Comments		: Filters the list of all the files, returning only those which have the given folder as their directory parent
 * Arguments	: const vector<string>& FileList, const string FolderName
 *******************************************************************/
vector<fs::path> FileSystem::NameFilter_folderPresent( const vector<fs::path>& FileList, const string FolderName, const bool has ) const
{
	vector<fs::path> FilterList;

	for(vector<fs::path>::const_iterator it = FileList.begin(); it != FileList.end(); it++ )
	{
		// Has folder, and the search request is also the same.
		if( Find(*it, FolderName ) && ( has == true ) )
		{
			FilterList.push_back(*it);
		}

		// Does not have the folder and the search request also does not want it
		if( !Find(*it, FolderName ) && ( has == false )  )
		{
			FilterList.push_back(*it);
		}
	}

	return FilterList;
}


/*******************************************************************
 * Function Name: NameFilter_parentName
 * Return Type 	: vector<string>
 * Created On	: Feb 16, 2013
 * Created By 	: hrushi
 * Comments		: Checks if the given file path has the passed parent name
 * Arguments	: const vector<string>& FileList, const string FolderName
 *******************************************************************/
vector<fs::path> FileSystem::NameFilter_parentName( const vector<fs::path>& FileList, const string FolderName,  const bool has) const
{
	vector<fs::path> FilterList;

	for( vector<fs::path>::const_iterator it = FileList.begin(); it != FileList.end(); it++)
	{
		fs::path Path = *it;

		if( !fs::is_directory(Path) ) // If the given path is not a directory
		{
			fs::path ParentPath = Path.parent_path();
			string ParentName = ParentPath.filename().string();
			string PARENTNAME = StringOp<string>::GetUpper( ParentName );
			string FOLDERNAME = StringOp<string>::GetUpper( FolderName );

			if( PARENTNAME == FOLDERNAME )
			{
				if( has == true )
				{
					FilterList.push_back( *it );
				}
			}
			else
			{
				if( has == false )
				{
					FilterList.push_back( *it );
				}
			}
		}
	}

	return FilterList;
}

/*******************************************************************
 * Function Name: MakeRelative
 * Return Type 	: fs::path
 * Created On	: Feb 23, 2013
 * Created By 	: hrushi
 * Comments		: Returns a relative path 'From' 'To'
 * Arguments	: const fs::path& From, const fs::path &To
 * TODO			: Make this function generalized
 *******************************************************************/
fs::path FileSystem::MakeRelative( const fs::path& From, const fs::path &To)
{
	fs::path RelativePath;
	string sFromParentPath 	= From.parent_path().string();
	string sToPath		 	= To.string();

	while(sFromParentPath.length() > 0 )
	{
		size_t findLoc = sToPath.find(sFromParentPath);

		if( findLoc < sToPath.size() )
		{
			string sRelative;
			sRelative.assign(sToPath,findLoc + sFromParentPath.size(), sToPath.size() );
			RelativePath = sRelative;
			break;
		}
		else
		{

			fs::path TempFromPath = sFromParentPath;
			TempFromPath = TempFromPath.parent_path();
			sFromParentPath = TempFromPath.string();

		}
	}

	if( sFromParentPath.length() == 0 )
	{
		cout << "Relative Path not found " << endl;
	}

	return RelativePath;
}


/*******************************************************************
 * Function Name: MakeRelative
 * Return Type 	: fs::path
 * Created On	: Feb 23, 2013
 * Created By 	: hrushi
 * Comments		: Makes the relative path, given two strings.
 * Arguments	: const string From, const string To
 *******************************************************************/
fs::path FileSystem::MakeRelative( const string FromPath, const string ToPath)
{
	fs::path RelativePath;
	fs::path From 	= FromPath;
	fs::path To		= ToPath;

	RelativePath = MakeRelative(From, To);

	return RelativePath;
}

/*******************************************************************
 * Function Name: GetOutputFolderPath
 * Return Type 	: const fs::path
 * Created On	: Jul 8, 2013
 * Created By 	: hrushi
 * Comments		: Get the Output Folder Path from the Image Path
 * Arguments	: const fs::path TrackImgPath
 *******************************************************************/
const fs::path FileSystem::GetOutputFolderPath( const fs::path TrackImgPath )
{
	const fs::path fsOutputFolderPath = TrackImgPath.parent_path();
	return fsOutputFolderPath;
}


/*******************************************************************
 * Function Name: GetOutputImagePath
 * Return Type 	: const fs::path
 * Created On	: Jul 8, 2013
 * Created By 	: hrushi
 * Comments		: Get Output Image path from the Track Image path;
 * 					Creates the folder if not already present.
 * Arguments	: const fs::path TrackImgPath
 *******************************************************************/
const fs::path FileSystem::BuildOutputImgPath( const fs::path TrackImgPath)
{
	string DetFolderName = "/Detection/";
	string ImgName 		 = TrackImgPath.filename().string();
	string FolderPath = GetOutputFolderPath(TrackImgPath).string() + DetFolderName;

	fs::path fsOutputImgPath;
	try
	{
		CreateFolder(fs::path(FolderPath));
		fsOutputImgPath = FolderPath + ImgName;
		return fsOutputImgPath;
	}
	catch(int Err )
	{
		throw Err;
	}

	return fsOutputImgPath;
}


/*******************************************************************
 * Function Name: CreateFolderPath
 * Return Type 	: const fs::path
 * Created On	: Jul 8, 2013
 * Created By 	: hrushi
 * Comments		: Creates the folder at the given path
 * Arguments	: fs::path FolderPath
 *******************************************************************/
int FileSystem::CreateFolder( const fs::path FolderPath)
{

	if( !fs::exists(FolderPath) )
	{
		cout << "Creating the Folder Path " << FolderPath << endl;

		try
		{
			fs::create_directories(FolderPath);
		}
		catch(...)
		{
			cerr << "Cannot Create Directory at Location : " << endl;
			cerr << FolderPath << endl;
			throw ERR_INVALID_PATH;
		}
	}


	return EXIT_SUCCESS;
}
