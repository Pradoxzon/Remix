/**
 * \file Arrow.cpp
 *
 * \author Shawn Peerenboom
 */

#include "stdafx.h"
#include "Arrow.h"


using namespace std;
using namespace Gdiplus;


/// Image of the upward facing arrow
const wstring UpArrow = L"upArrow.png";
/// Disabled version
const wstring UpArrowDisabled = L"upArrowDisabled.png";

/// Image of the downward facing arrow
const wstring DownArrow = L"downArrow.png";
/// Disabled version
const wstring DownArrowDisabled = L"downArrowDisabled.png";

/// Image of the right facing arrow
const wstring RightArrow = L"rightArrow.png";
/// Disabled version
const wstring RightArrowDisabled = L"rightArrowDisabled.png";

/// Image of the left facing arrow
const wstring LeftArrow = L"leftArrow.png";
/// Disabled version
const wstring LeftArrowDisabled = L"leftArrowDisabled.png";

/// Screen area width in virtual pixels
const static int Width = 1800;

/// Screen area height in virtual pixels
const static int Height = 1100;

/**
 * Constructor
 * \param display The display that this arrow appears on
 * \param direction The directrion this arrow is pointing
 */
CArrow::CArrow(CDisplay *display, Direction direction) : CBaseImage(display)
{
	if (direction == UP)
	{
		mDirection = direction;
		SetImage(UpArrow);
		SetLocation(0, -(Height / 2) + 50);
	}
	else if (direction == DOWN)
	{
		mDirection = direction;
		SetImage(DownArrow);
		SetLocation(0, (Height / 2) - 50);
	}
	else if (direction == RIGHT)
	{
		mDirection = direction;
		SetImage(RightArrow);
		SetLocation((Width / 2) - 50, 0);
	}
	else
	{
		mDirection = direction;
		SetImage(LeftArrow);
		SetLocation(-(Width / 2) + 50, 0);
	}
}


CArrow::~CArrow()
{
}


void CArrow::Enable()
{
	mEnabled = true;
	if (mDirection == UP)
	{
		SetImage(UpArrow);
	}
	else if (mDirection == DOWN)
	{
		SetImage(DownArrow);
	}
	else if (mDirection == RIGHT)
	{
		SetImage(RightArrow);
	}
	else
	{
		SetImage(LeftArrow);
	}
}

void CArrow::Disable()
{
	mEnabled = false;
	if (mDirection == UP)
	{
		SetImage(UpArrowDisabled);
	}
	else if (mDirection == DOWN)
	{
		SetImage(DownArrowDisabled);
	}
	else if (mDirection == RIGHT)
	{
		SetImage(RightArrowDisabled);
	}
	else
	{
		SetImage(LeftArrowDisabled);
	}
}
