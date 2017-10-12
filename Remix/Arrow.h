/**
 * \file Arrow.h
 *
 * \author Shawn Peerenboom
 *
 * A class that describes an arrow
 */

#pragma once

#include <string>
#include <memory>

// Forward declaration
class CDisplay;


/**
 * The Arrow class
 */
class CArrow
{
public:
	/// The possible arrow directions
	enum Direction {UP=0,	///< Arrow is pointing up
		DOWN=1,				///< Arrow is pointing down
		RIGHT=2,			///< Arrow is pointing right
		LEFT=3};			///< Arrow is pointing left


	/// Default constructor (disabled)
	CArrow() = delete;

	/// Default copy constructor (disabled)
	CArrow(const CArrow &) = delete;

	CArrow(CDisplay *city, Direction direction);

	~CArrow();


	/// Enable the Arrow
	void Enable() { mEnabled = true; }

	/// Disable the Arrow
	void Disable() { mEnabled = false; }

private:
	/// Determine whether the arrow is clickable or not
	bool mEnabled;

	// The arrow's location
	int mX = 0;		///< X location for the center of the arrow
	int mY = 0;		///< Y location for the center of the arrow

	std::unique_ptr<Gdiplus::Bitmap> mArrowImage;
};

