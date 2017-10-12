/**
 * \file Display.h
 *
 * \author Shawn Peerenboom
 *
 * The class that manages the program
 */

#pragma once

#include <vector>
#include <memory>

#include "Arrow.h"


/// Screen area width in virtual pixels
const static int Width = 1400;

/// Screen area height in virtual pixels
const static int Height = 1100;


class CDisplay
{
public:
	CDisplay();

	virtual ~CDisplay();


	void OnDraw(Gdiplus::Graphics *graphics);

private:
	/**
	 * The arrows used to change the screen.
	 * Order in the vector: 
	 *		0: Up arrow
	 *		1: Down arrow
	 *		2: Right arrow
	 *		3: Left arrow
	 * (Or: North, South, East, West)
	 */
	std::vector<std::shared_ptr<CArrow> > mArrows;
};

