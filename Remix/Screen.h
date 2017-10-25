/**
 * \file Screen.h
 *
 * \author Shawn Peerenboom
 *
 * Creates a screen object
 */

#pragma once

#include "BaseImage.h"
#include "CubeBackground.h"


/**
 * A screen object
 */
class CScreen : public CBaseImage
{
public:
	/// The possible types of Screens
	enum Type
	{
		ABOUT,
		ORIGIN,
		TOY,
		MOVIE,
		CUBISM,
		NERDS,
		SPEED,
		CELEB,
		SOLVE
	};

	/// Default constructor (disabled)
	CScreen() = delete;

	/// Default copy constructor (disabled)
	CScreen(const CScreen &) = delete;

	CScreen(CDisplay *display, Type type);

	virtual ~CScreen();


	CCubeBackground::CubeColor GetColor() { return mBackColor; }

private:
	/// Background color for this screen
	CCubeBackground::CubeColor mBackColor;


	void SetType(CDisplay *display, Type type);
};

