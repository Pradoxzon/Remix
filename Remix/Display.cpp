/**
 * \file Display.cpp
 *
 * \author Shawn Peerenboom
 */

#include "stdafx.h"
#include "Display.h"


using namespace std;
using namespace Gdiplus;


/**
 * Constructor
 */
CDisplay::CDisplay()
{
}


/**
 * Destructor
 */
CDisplay::~CDisplay()
{
}


void CDisplay::OnDraw(Graphics *graphics)
{
	// Draw the arrows
	for (auto arrow : mArrows)
	{
		arrow->Draw(graphics);
	}
}
