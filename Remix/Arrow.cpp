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

/// Image of the downward facing arrow
const wstring DownArrow = L"downArrow.png";

/// Image of the right facing arrow
const wstring RightArrow = L"rightArrow.png";

/// Image of the left facing arrow
const wstring LeftArrow = L"leftArrow.png";

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
		SetLocation(0, -200);
	}
	else if (direction == DOWN)
	{
		mDirection = direction;
		SetImage(DownArrow);
		SetLocation(0, 200);
	}
	else if (direction == RIGHT)
	{
		mDirection = direction;
		SetImage(RightArrow);
		SetLocation(200, 0);
	}
	else
	{
		mDirection = direction;
		SetImage(LeftArrow);
		SetLocation(-200, 0);
	}
}


CArrow::~CArrow()
{
}
