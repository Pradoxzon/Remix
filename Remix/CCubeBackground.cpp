/**
 * \file CCubeBackground.cpp
 *
 * \author Shawn Peerenboom
 */

#include "stdafx.h"

#include "CCubeBackground.h"


/**
 * Constructor
 * \param display The display that this Background is a part of
 */
CCubeBackground::CCubeBackground(CDisplay *display) : CBaseImage(display)
{
	mCurrentColor = WHITE;
	SetLocation(0, 0);
}


/**
 * Destructor
 */
CCubeBackground::~CCubeBackground()
{
}


void CCubeBackground::SetFace()
{
	SetFace(mCurrentColor);
}

void CCubeBackground::SetFace(CubeColor transitionColor)
{
	wstring fileName;

	if (mCurrentColor == WHITE)
	{
		fileName = White;
	}
	else if (mCurrentColor == RED)
	{
		fileName = Red;
	}
	else if (mCurrentColor == BLUE)
	{
		fileName = Blue;
	}
	else if (mCurrentColor == ORANGE)
	{
		fileName = Orange;
	}
	else if (mCurrentColor == YELLOW)
	{
		fileName = Yellow;
	}
	else
	{
		fileName = Green;
	}

	if (transitionColor != mCurrentColor)
	{
		fileName += transitionColor;
	}

	SetImage(fileName + FileType);
}
