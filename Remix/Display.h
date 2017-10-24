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
#include "CubeBackground.h"


/// Screen area width in virtual pixels
const static int Width = 2000;

/// Screen area height in virtual pixels
const static int Height = 1100;


class CDisplay
{
public:
	CDisplay();

	virtual ~CDisplay();


	void UpdateClicked(std::shared_ptr<CArrow> arrow);

	void Update(double elapsed);

	void OnDraw(Gdiplus::Graphics *graphics, int width, int height, double elapsed);

	std::shared_ptr<CArrow> HitTest(int x, int y);


	/**
	 * Change x-coordinate to virtual coordinates
	 * \param x The coordinate to be transformed
	 * \return double The transformed coordinate
	 */
	double xAxisTransform(double x) { return static_cast<int>((x - mXOffset) / mScale); }

	/**
	 * Change y-coordinate to virtual coordinates
	 * \param y The coordinate to be transformed
	 * \return double The transformed coordinate
	 */
	double yAxisTransform(double y) { return static_cast<int>((y - mYOffset) / mScale); }

private:
	float mScale;		///< Value to help scale screen
	float mXOffset;		///< Value to set center x value to be middle of screen
	float mYOffset;		///< Value to set center y value to be middle of screen

	double mElapsed;				///< The time since an arrow was clicked
	bool mTransitioning = false;	///< Indicate whether a transition is happening

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

	/// The background cube image
	std::shared_ptr<CCubeBackground> mBackground;
};

