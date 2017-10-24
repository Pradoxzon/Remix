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


	bool CheckUp() { return (mScreenCollection[mActive][0] != nullptr); }
	bool CheckDown() { return (mScreenCollection[mActive][1] != nullptr); }
	bool CheckRight() { return (mScreenCollection[mActive][2] != nullptr); }
	bool CheckLeft() { return (mScreenCollection[mActive][3] != nullptr); }

	void MoveUp(bool partial=false);
	void MoveDown(bool partial=false);
	void MoveRight(bool partial=false);
	void MoveLeft(bool partial=false);

private:
	/// The collection of our screens and each screen's connections
	std::map<std::shared_ptr<CScreen>, std::vector<std::shared_ptr<CScreen>>> mScreenCollection;

	/// The active screen
	std::shared_ptr<CScreen> mActive;
};

