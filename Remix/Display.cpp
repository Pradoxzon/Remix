/**
 * \file Display.cpp
 *
 * \author Shawn Peerenboom
 */

#include "stdafx.h"
#include "Display.h"


using namespace std;
using namespace Gdiplus;


/**
 * Constructor
 */
CDisplay::CDisplay()
{
	// Create the arrows
	auto up = make_shared<CArrow>(this, CArrow::Direction::UP);
	auto down = make_shared<CArrow>(this, CArrow::Direction::DOWN);
	auto right = make_shared<CArrow>(this, CArrow::Direction::RIGHT);
	auto left = make_shared<CArrow>(this, CArrow::Direction::LEFT);

	mArrows.push_back(up);
	mArrows.push_back(down);
	mArrows.push_back(right);
	mArrows.push_back(left);

	mScreens = make_shared<CScreenCollection>(this);

	mBackground = make_shared<CCubeBackground>(this, CCubeBackground::CubeColor::WHITE);
}


/**
 * Destructor
 */
CDisplay::~CDisplay()
{
}


void CDisplay::UpdateClicked(shared_ptr<CArrow> arrow)
{
	if (arrow->IsEnabled())
	{
		// Try to change screens
		if (arrow->GetDirect() == CArrow::UP && !mScreens->Move(CScreenCollection::UP))
		{
			arrow->Disable();
			return;
		}
		else if (arrow->GetDirect() == CArrow::DOWN && !mScreens->Move(CScreenCollection::DOWN))
		{
			arrow->Disable();
			return;
		}
		else if (arrow->GetDirect() == CArrow::RIGHT && !mScreens->Move(CScreenCollection::RIGHT))
		{
			arrow->Disable();
			return;
		}
		else if (arrow->GetDirect() == CArrow::LEFT && !mScreens->Move(CScreenCollection::LEFT))
		{
			arrow->Disable();
			return;
		}

		// Reset the time elapsed
		mElapsed = 0;

		// Disabled all the arrows while animation happens
		for (auto eachArrow : mArrows)
		{
			eachArrow->Disable();
		}

		mTransitioning = true;
	}
}


void CDisplay::Update(double elapsed)
{
	mElapsed += elapsed;

	if (mElapsed >= 0.5 && mElapsed <= 1)	// Rotate the cube halfway
	{
		mBackground->StartTransition(mScreens->GetColor());
	}
	else if (mElapsed > 1)				// Finish rotating the cube
	{
		mBackground->EndTransition();
	}
	if (mElapsed >= 1.5)	// Tansition is finished
	{
		// Decide which arrows are active
		vector<bool> active = mScreens->ActiveConnections();
		mArrows[0]->State(active[0]);
		mArrows[1]->State(active[1]);
		mArrows[2]->State(active[2]);
		mArrows[3]->State(active[3]);

		mTransitioning = false;
	}
}


void CDisplay::OnDraw(Graphics *graphics, int width, int height, double elapsed)
{
	// Fill background with white
	SolidBrush brush(Color::White);
	graphics->FillRectangle(&brush, 0, 0, width, height);

	// Automatic Scaling
	float scaleX = float(width) / float(Width);
	float scaleY = float(height) / float(Height);
	mScale = min(scaleX, scaleY);

	mXOffset = width / 2.0f;
	mYOffset = height / 2.0f;

	graphics->TranslateTransform(mXOffset, mYOffset);
	graphics->ScaleTransform(mScale, mScale);

	// Decide which arrows are active
	//vector<bool> active = mScreens->ActiveConnections();
	//mArrows[0]->State(active[0]);
	//mArrows[1]->State(active[1]);
	//mArrows[2]->State(active[2]);
	//mArrows[3]->State(active[3]);

	// Update the display
	if (mTransitioning)
	{
		Update(elapsed);
	}
	

	// Draw the background cube
	mBackground->Draw(graphics);

	// Draw the screen
	if (!mTransitioning)
	{
		mScreens->Draw(graphics);
	}

	// Draw the arrows
	for (auto arrow : mArrows)
	{
		arrow->Draw(graphics);
	}
}


/**
 * Chack if we clicked an arrow
 * \param x X location
 * \param y Y location
 * \returns Pointer to the arrow we clicked on or nullptr if none.
 */
shared_ptr<CArrow> CDisplay::HitTest(int x, int y)
{
	// Convert x and y to virtual pixels before testing
	double newX = xAxisTransform(x);
	double newY = yAxisTransform(y);

	for (auto arrow : mArrows)
	{
		if (arrow->HitTest(newX, newY))
		{
			return arrow;
		}
	}

	return nullptr;
}
