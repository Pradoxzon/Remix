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
		SetImage(UpArrow);
	}
	else if (direction == DOWN)
	{
		SetImage(DownArrow);
	}
	else if (direction == RIGHT)
	{
		SetImage(RightArrow);
	}
	else
	{
		SetImage(LeftArrow);
	}
}


CArrow::~CArrow()
{
}
