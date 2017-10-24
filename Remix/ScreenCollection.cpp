/**
 * \file ScreenCollection.cpp
 *
 * \author Shawn Peerenboom
 */

#include "stdafx.h"
#include "ScreenCollection.h"


using namespace std;


/**
 * Constructor
 */
CScreenCollection::CScreenCollection(CDisplay *display)
{
	// Create the screens
	auto aboutScreen = make_shared<CScreen>(display);
	auto originScreen = make_shared<CScreen>(display);
	auto toyScreen = make_shared<CScreen>(display);
	auto movieScreen = make_shared<CScreen>(display);
	auto cubismScreen = make_shared<CScreen>(display);
	auto nerdsScreen = make_shared<CScreen>(display);
	auto speedScreed = make_shared<CScreen>(display);
	auto celebScreen = make_shared<CScreen>(display);
	auto solveScreen = make_shared<CScreen>(display);

	// Create the vector for each screen
	// Connections: { UP, DOWN, RIGHT, LEFT }
	vector<shared_ptr<CScreen>> aboutVector = { nerdsScreen, toyScreen, originScreen, movieScreen };
	vector<shared_ptr<CScreen>> originVector = { nullptr, nullptr, nullptr, aboutScreen };
	vector<shared_ptr<CScreen>> toyVector = { aboutScreen, speedScreed, cubismScreen, movieScreen };
	vector<shared_ptr<CScreen>> movieVector = { nullptr, toyScreen, aboutScreen, nullptr };
	vector<shared_ptr<CScreen>> cubismVector = { nullptr, nullptr, nullptr, toyScreen };

	// Add the screens to the map

}


/**
 * Destructor
 */
CScreenCollection::~CScreenCollection()
{
}
