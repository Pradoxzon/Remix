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

#include "BaseImage.h"

// Forward declaration
class CDisplay;


/**
 * The Arrow class
 */
class CArrow : public CBaseImage
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

	CArrow(CDisplay *display, Direction direction);

	~CArrow();


	/// Enable the Arrow
	void Enable() { mEnabled = true; }

	/// Disable the Arrow
	void Disable() { mEnabled = false; }

private:
	/// Determine whether the arrow is clickable or not
	bool mEnabled;

	std::unique_ptr<Gdiplus::Bitmap> mArrowImage;
};

