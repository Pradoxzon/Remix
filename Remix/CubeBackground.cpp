/**
 * \file CubeBackground.cpp
 *
 * \author Shawn Peerenboom
 */

#include "stdafx.h"

#include "CubeBackground.h"


using namespace std;


const wstring White = L"White";
const wstring Red = L"Red";
const wstring Blue = L"Blue";
const wstring Orange = L"Orange";
const wstring Yellow = L"Yellow";
const wstring Green = L"Green";

const wstring FileType = L".png";


/**
 * Constructor
 * \param display The display that this Background is a part of
 */
CCubeBackground::CCubeBackground(CDisplay *display, CubeColor color) : CBaseImage(display)
{
	mCurrentColor = color;
	mTransitionColor = color;
	SetFace();
	SetLocation(0, 0);
}


/**
 * Destructor
 */
CCubeBackground::~CCubeBackground()
{
}


/**
 * Gets the wstring equivalent of a CubeColor
 * \param cColor The color to get the wstring of
 * \returns wstring The equivalent to cColor
 */
wstring CCubeBackground::GetString(CubeColor cColor)
{
	if (cColor == WHITE)
	{
		return White;
	}
	else if (cColor == RED)
	{
		return Red;
	}
	else if (cColor == BLUE)
	{
		return Blue;
	}
	else if (cColor == ORANGE)
	{
		return Orange;
	}
	else if (cColor == YELLOW)
	{
		return Yellow;
	}
	else
	{
		return Green;
	}
}


/**
 * Set the face of the cube to display
 */
void CCubeBackground::SetFace()
{
	SetFace(mTransitionColor);
}

/**
 * Set the face of the cube to display
 * \param transitionColor Used to indicate that a transition is happening 
 *   if this is different than the current color
 */
void CCubeBackground::SetFace(CubeColor transitionColor)
{
	wstring fileName = GetString(mCurrentColor);

	if (transitionColor != mCurrentColor)
	{
		fileName += GetString(transitionColor);
		mTransitionColor = transitionColor;
	}

	SetImage(fileName + FileType);
}


/**
 * Start a transition
 * \param destColor The new color being transitioned to
 */
void CCubeBackground::StartTransition(CubeColor destColor)
{
	SetFace(destColor);
}

/**
 * End / finish the transition
 */
void CCubeBackground::EndTransition()
{
	mCurrentColor = mTransitionColor;
	SetFace();
}
