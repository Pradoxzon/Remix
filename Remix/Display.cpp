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


void CDisplay::Update(shared_ptr<CArrow> arrow)
{
	if (arrow->IsEnabled())
	{
		CArrow::Direction direc = arrow->GetDirect();
		if (direc == CArrow::Direction::UP)
		{
			arrow->SetLocation(arrow->GetX(), arrow->GetY() + 50);
		}
		else if (direc == CArrow::Direction::DOWN)
		{
			arrow->SetLocation(arrow->GetX(), arrow->GetY() - 50);
		}
		else if (direc == CArrow::Direction::LEFT)
		{
			arrow->SetLocation(arrow->GetX() + 50, arrow->GetY());
		}
		else
		{
			arrow->SetLocation(arrow->GetX() - 50, arrow->GetY());
		}
		arrow->Disable();
	}
}


void CDisplay::OnDraw(Graphics *graphics, int width, int height)
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
