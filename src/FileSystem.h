/*
 * FileSystem.h
 *
 *  Created on: Feb 13, 2013
 *      Author: hrushi
 */

#ifndef FILESYSTEM_H_
#define FILESYSTEM_H_


#include "Includes.h"
#include "StringOp.h"

class FileSystem
{
private:

public:
	FileSystem();
	virtual ~FileSystem();

	static vector<fs::path> ListAllImagesInFolder(const fs::path FolderPath );
	static vector<fs::path> ListAllTrackImages( const fs::path FolderPath, const string TrackFldrName );

	static size_t Find( const fs::path& ImPath, const string FolderName ) ;
	vector<fs::path> NameFilter_folderPresent( const vector<fs::path>& FileList, const string FolderName, const bool has ) const;
	vector<fs::path> NameFilter_parentName( const vector<fs::path>& FileList, const string FolderName, const bool has ) const;
	static fs::path MakeRelative(const fs::path& From, const fs::path& To);
	static fs::path MakeRelative(const string FromPath, const string ToPath );

	static const fs::path GetMaskImgPath(const string MaskFolderName, 	const fs::path TrackPath, const string TrackFolderName);
	static const vector<fs::path> GetMaskImgPathVector( const string MaskFolderName, 	const vector<fs::path>& TrackPath, const string TrackFolderName );
	static bool isImageExt(const string sEXT );
	static const fs::path GetOutputFolderPath( const fs::path TrackImgPath );
	static const fs::path BuildOutputImgPath( const fs::path TrackImgPath );
	static int CreateFolder( const fs::path FolderPath );
};


#endif /* FILESYSTEM_H_ */
