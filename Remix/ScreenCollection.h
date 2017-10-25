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


// Forward declarations
class CDisplay;


/**
 * The Screen managing class
 */
class CScreenCollection
{
public:
	enum Direction
	{
		UP,
		DOWN,
		RIGHT,
		LEFT
	};


	/// Default constructor (disabled)
	CScreenCollection() = delete;

	/// Default copy constructor (disabled)
	CScreenCollection(const CScreenCollection &) = delete;

	CScreenCollection(CDisplay *display);

	virtual ~CScreenCollection();

	std::vector<bool> ActiveConnections();

	bool Move(Direction direction);

	void Draw(Gdiplus::Graphics *graphics);

	CCubeBackground::CubeColor GetColor() { return mActive->GetColor(); }

private:
	/// The collection of our screens and each screen's connections
	std::map<std::shared_ptr<CScreen>, std::vector<std::shared_ptr<CScreen>>> mScreenCollection;

	/// The active screen
	std::shared_ptr<CScreen> mActive;


	bool CheckDirection(Direction direction);
};

