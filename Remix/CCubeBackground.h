/**
 * \file CCubeBackground.h
 *
 * \author Shawn Peerenboom
 *
 * Handles the 
 */

#pragma once

#include "BaseImage.h"


/**
 * 
 */
class CCubeBackground : public CBaseImage
{
public:
	enum CubeColor
	{
		WHITE,
		RED,
		BLUE,
		ORANGE,
		YELLOW,
		GREEN
	};

	enum TransitionDirection
	{
		UPDOWN,
		RIGHTLEFT
	};


	/// Default constructor (disabled)
	CCubeBackground() = delete;

	/// Default copy constructor (disabled)
	CCubeBackground(const CCubeBackground &) = delete;

	CCubeBackground(CDisplay *display);

	virtual ~CCubeBackground();
};

