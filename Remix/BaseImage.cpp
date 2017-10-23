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
			float(GetX() - wid / 2), float(GetY() - hit / 2),
			(float)mImage->GetWidth(), (float)mImage->GetHeight());
	}

}


/**
* Test to see if we hit this object with a mouse.
* \param x X position to test
* \param y Y position to test
* \return true if hit.
*/
bool CBaseImage::HitTest(double x, double y)
{
	double wid = mImage->GetWidth();
	double hit = mImage->GetHeight();

	// Make x and y relative to the top-left corner of the bitmap image
	// Subtracting the center makes x, y relative to the image center
	// Adding half the size makes x, y relative to theimage top corner
	double testX = x - GetX() + wid / 2;
	double testY = y - GetY() + hit / 2;

	// Test to see if x, y are in the image
	if (testX < 0 || testY < 0 || testX >= wid || testY >= hit)
	{
		// We are outside the image
		return false;
	}

	return true;
}
