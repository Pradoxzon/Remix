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
	/// Default constructor (disabled)
	CScreen() = delete;

	/// Default copy constructor (disabled)
	CScreen(const CScreen &) = delete;

	CScreen(CDisplay *display);

	~CScreen();
};

