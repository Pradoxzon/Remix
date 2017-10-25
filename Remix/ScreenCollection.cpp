/**
 * \file ScreenCollection.cpp
 *
 * \author Shawn Peerenboom
 */

#include "stdafx.h"
#include "ScreenCollection.h"


using namespace std;
using namespace Gdiplus;


/**
 * Constructor
 */
CScreenCollection::CScreenCollection(CDisplay *display)
{
	// Create the screens
	auto aboutScreen = make_shared<CScreen>(display, CScreen::ABOUT);
	auto originScreen = make_shared<CScreen>(display, CScreen::ORIGIN);
	auto toyScreen = make_shared<CScreen>(display, CScreen::TOY);
	auto movieScreen = make_shared<CScreen>(display, CScreen::MOVIE);
	auto cubismScreen = make_shared<CScreen>(display, CScreen::CUBISM);
	auto nerdsScreen = make_shared<CScreen>(display, CScreen::NERDS);
	auto speedScreed = make_shared<CScreen>(display, CScreen::SPEED);
	auto celebScreen = make_shared<CScreen>(display, CScreen::CELEB);
	auto solveScreen = make_shared<CScreen>(display, CScreen::SOLVE);

	// Create the vector for each screen
	// Connections: { UP, DOWN, RIGHT, LEFT }
	vector<shared_ptr<CScreen>> aboutVector = { nerdsScreen, toyScreen, originScreen, movieScreen };
	vector<shared_ptr<CScreen>> originVector = { nullptr, nullptr, nullptr, aboutScreen };
	vector<shared_ptr<CScreen>> toyVector = { aboutScreen, speedScreed, cubismScreen, movieScreen };
	vector<shared_ptr<CScreen>> movieVector = { nullptr, toyScreen, aboutScreen, nullptr };
	vector<shared_ptr<CScreen>> cubismVector = { nullptr, nullptr, nullptr, toyScreen };
	vector<shared_ptr<CScreen>> nerdsVector = { solveScreen, aboutScreen, speedScreed, celebScreen };
	vector<shared_ptr<CScreen>> speedVector = { toyScreen, nullptr, nullptr, nerdsScreen };
	vector<shared_ptr<CScreen>> celebVector = { nullptr, nullptr, nerdsScreen, nullptr };
	vector<shared_ptr<CScreen>> solveVector = { nullptr, nerdsScreen, nullptr, nullptr };

	// Add the screens to the map
	mScreenCollection = { {aboutScreen, aboutVector}, 
						  {originScreen, originVector},
						  {toyScreen, toyVector},
						  {movieScreen, movieVector},
						  {cubismScreen, cubismVector},
						  {nerdsScreen, nerdsVector},
						  {speedScreed, speedVector}, 
						  {celebScreen, celebVector},
						  {solveScreen, solveVector} };

	// Set the initial active screen
	mActive = aboutScreen;
}


/**
 * Destructor
 */
CScreenCollection::~CScreenCollection()
{
}


/**
 * Provides a vector of bools to indicate which sides of the active Screen have connections
 *   The returned vector is garanteed to always have 4 stored values
 *   True means the side has a connection
 *   Indexes:
 *     0: UP
 *     1: DOWN
 *     2: RIGHT
 *     3: LEFT
 * \returns vector<bool> A vector containing boolean values
 */
vector<bool> CScreenCollection::ActiveConnections()
{
	vector<bool> activeSides(4);

	activeSides[0] = CheckDirection(UP);
	activeSides[1] = CheckDirection(DOWN);
	activeSides[2] = CheckDirection(RIGHT);
	activeSides[3] = CheckDirection(LEFT);

	return activeSides;
}

bool CScreenCollection::Move(Direction direction)
{
	// Make sure the direction to move is valid
	if (!CheckDirection(direction))
	{
		return false;
	}

	// Change screens
	if (direction == UP)
	{
		mActive = mScreenCollection[mActive][0];
	}
	else if (direction == DOWN)
	{
		mActive = mScreenCollection[mActive][1];
	}
	else if (direction == RIGHT)
	{
		mActive = mScreenCollection[mActive][2];
	}
	else
	{
		mActive = mScreenCollection[mActive][3];
	}

	return true;
}


void CScreenCollection::Draw(Graphics *graphics)
{
	mActive->Draw(graphics);
}


bool CScreenCollection::CheckDirection(Direction direction)
{
	if (direction == UP)
	{
		return (mScreenCollection[mActive][0] != nullptr);
	}
	else if (direction == DOWN)
	{
		return (mScreenCollection[mActive][1] != nullptr);
	}
	else if (direction == RIGHT)
	{
		return (mScreenCollection[mActive][2] != nullptr);
	}
	else
	{
		return (mScreenCollection[mActive][3] != nullptr);
	}
}
