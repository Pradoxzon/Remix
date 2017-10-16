/**
 * \file BaseImage.cpp
 *
 * \author Shawn Peerenboom
 */

#include "stdafx.h"
#include "BaseImage.h"


using namespace std;
using namespace Gdiplus;


/// The directory containing the file images
const std::wstring CBaseImage::ImagesDirectory = L"images/";


/**
 * Constructor
 * \param display The display this BaseImage is a part of
 */
CBaseImage::CBaseImage(CDisplay *display)
{
}


/**
 * Destructor
 */
CBaseImage::~CBaseImage()
{
}


/**
*  Set the image file to draw
* \param file The base filename. Blank files are allowed
*/
void CBaseImage::SetImage(const std::wstring &file)
{
	if (!file.empty())
	{
		wstring filename = ImagesDirectory + file;
		mImage = unique_ptr<Bitmap>(Bitmap::FromFile(filename.c_str()));
		if (mImage->GetLastStatus() != Ok)
		{
			wstring msg(L"Failed to open ");
			msg += filename;
			AfxMessageBox(msg.c_str());
			return;
		}
	}
	else
	{
		mImage.release();
	}
}

/**
*  Draw our tile
* \param graphics The graphics context to draw on
*/
void CBaseImage::Draw(Gdiplus::Graphics *graphics)
{
	if (mImage != nullptr)
	{
		int wid = mImage->GetWidth();
		int hit = mImage->GetHeight();

		graphics->DrawImage(mImage.get(),
			mX, mY - hit,
			wid, hit);
	}

}
