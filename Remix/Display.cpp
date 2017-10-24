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
	auto left = make_shared<CArrow>(this, CArrow::Direction::LEFT);
	auto right = make_shared<CArrow>(this, CArrow::Direction::RIGHT);

	mArrows.push_back(up);
	mArrows.push_back(down);
	mArrows.push_back(left);
	mArrows.push_back(right);
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

	if (mElapsed >= 3)	// Tansition is finished
	{
		for (auto arrow : mArrows)
		{
			// Re-enable the arrows that need to be re-enabled
			arrow->Enable();
		}
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

	// Update the display
	if (mTransitioning)
	{
		Update(elapsed);
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
