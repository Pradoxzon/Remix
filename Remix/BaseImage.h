/**
 * \file BaseImage.h
 *
 * \author Shawn Peerenboom
 *
 * The base class for any image that will be displayed
 */

#pragma once

#include <string>
#include <memory>


// Forward Declaration
class CDisplay;


/**
 * A base image class
 */
class CBaseImage
{
public:
	/** The directory were the images are stored */
	static const std::wstring ImagesDirectory;


	/// Default constructor (disabled)
	CBaseImage() = delete;

	/// Default copy constructor (disabled)
	CBaseImage(const CBaseImage &) = delete;

	virtual ~CBaseImage();


	int GetX() { return mX; }

	int GetY() { return mY; }


	void SetImage(const std::wstring &file);

	/**  Draw this item
	* \param graphics The graphics context to draw on */
	virtual void Draw(Gdiplus::Graphics *graphics);

	/**
	 * Set the image's location
	 * \param newX The new x-coordinate of the image's center
	 * \param newY The new y-coordinate of the image's center
	 */
	void SetLocation(int newX, int newY) { mX = newX; mY = newY; }

	bool HitTest(double x, double y);

protected:
	CBaseImage(CDisplay *display);

private:
	// The image's location
	int mX = 0;		///< X location for the center of the image
	int mY = 0;		///< Y location for the center of the image

	/// The actual image used by this object
	std::unique_ptr<Gdiplus::Bitmap> mImage;
};

