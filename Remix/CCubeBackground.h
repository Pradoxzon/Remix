/**
 * \file CCubeBackground.h
 *
 * \author Shawn Peerenboom
 *
 * Handles the background cube image
 */

#pragma once

#include "BaseImage.h"


using namespace std;


const wstring White = L"White";
const wstring Red = L"Red";
const wstring Blue = L"Blue";
const wstring Orange = L"Orange";
const wstring Yellow = L"Yellow";
const wstring Green = L"Green";

const wstring FileType = L".png";


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

	CCubeBackground(CDisplay *display);

	virtual ~CCubeBackground();


	void SetFace();
	void SetFace(CubeColor tansitionColor);

	void Transition(CubeColor destColor);

private:
	/// The background cube's current color
	CubeColor mCurrentColor;

	/// The color being transitioned to
	CubeColor mTransitionColor;
};

