/**
 * \file ScreenCollection.h
 *
 * \author Shawn Peerenboom
 *
 * Manages a collection of CScreens
 */

#pragma once

#include <map>
#include <vector>
#include <memory>
#include "Screen.h"
//#include "CubeBackground.h"


// Forward declarations
class CDisplay;


/**
 * The Screen managing class
 */
class CScreenCollection
{
public:
	/// Default constructor (disabled)
	CScreenCollection() = delete;

	/// Default copy constructor (disabled)
	CScreenCollection(const CScreenCollection &) = delete;

	CScreenCollection(CDisplay *display);

	virtual ~CScreenCollection();

private:
	/// The collection of our screens and each screen's connections
	std::map<std::shared_ptr<CScreen>, std::vector<std::shared_ptr<CScreen>>> mScreenCollection;

	/// The active screen
	std::shared_ptr<CScreen> mActive;
};

