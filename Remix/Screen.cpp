/**
 * \file Screen.cpp
 *
 * \author Shawn Peerenboom
 */

#include "stdafx.h"
#include "Screen.h"


using namespace std;


const wstring AboutImage = L"ScreenAbout.png";
const wstring OriginImage = L"ScreenOrigin.png";
const wstring ToyImage = L"ScreenToy.png";
const wstring MovieImage = L"ScreenMovie.png";
const wstring CubismImage = L"ScreenCubism.png";
const wstring NerdsImage = L"ScreenNerds.png";
const wstring SpeedImage = L"ScreenSpeed.png";
const wstring CelebImage = L"ScreenCeleb.png";
const wstring SolveImage = L"ScreenSolve.png";


/**
 * Constructor
 * \param display The display this screen is a part of
 */
CScreen::CScreen(CDisplay *display, Type type) : CBaseImage(display)
{
	SetType(display, type);
	SetLocation(0, 0);
}


/**
 * Destructor
 */
CScreen::~CScreen()
{
}


void CScreen::SetType(CDisplay *display, Type type)
{
	if (type == ABOUT)
	{
		mBackColor = CCubeBackground::WHITE;
		SetImage(AboutImage);
	}
	else if (type == ORIGIN)
	{
		mBackColor = CCubeBackground::BLUE;
		SetImage(OriginImage);
	}
	else if (type == TOY)
	{
		mBackColor = CCubeBackground::RED;
		SetImage(ToyImage);
	}
	else if (type == MOVIE)
	{
		mBackColor = CCubeBackground::GREEN;
		SetImage(MovieImage);
	}
	else if (type == CUBISM)
	{
		mBackColor = CCubeBackground::YELLOW;
		SetImage(CubismImage);
	}
	else if (type == NERDS)
	{
		mBackColor = CCubeBackground::ORANGE;
		SetImage(NerdsImage);
	}
	else if (type == SPEED)
	{
		mBackColor = CCubeBackground::BLUE;
		SetImage(SpeedImage);
	}
	else if (type == CELEB)
	{
		mBackColor = CCubeBackground::GREEN;
		SetImage(CelebImage);
	}
	else
	{
		mBackColor = CCubeBackground::YELLOW;
		SetImage(SolveImage);
	}
}
