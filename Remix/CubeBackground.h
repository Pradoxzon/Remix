/**
 * \file CubeBackground.h
 *
 * \author Shawn Peerenboom
 *
 * Handles the background cube image
 */

#pragma once

#include "BaseImage.h"


/**
 * The background cube image
 */
class CCubeBackground : public CBaseImage
{
public:
	enum CubeColor
	{
		WHITE,
		RED,
		BLUE,
		ORANGE,
		YELLOW,
		GREEN
	};


	/// Default constructor (disabled)
	CCubeBackground() = delete;

	/// Default copy constructor (disabled)
	CCubeBackground(const CCubeBackground &) = delete;

	CCubeBackground(CDisplay *display, CubeColor color);

	virtual ~CCubeBackground();

	void StartTransition(CubeColor destColor);
	void EndTransition();

private:
	/// The background cube's current color
	CubeColor mCurrentColor;

	/// The color being transitioned to
	CubeColor mTransitionColor;


	// Set the face of the cube that shows
	void SetFace();
	void SetFace(CubeColor tansitionColor);

	// Get the wstring equivalent of a CubeColor
	std::wstring GetString(CubeColor cColor);
};

