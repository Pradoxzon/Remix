
// Remix.h : main header file for the Remix application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CRemixApp:
// See Remix.cpp for the implementation of this class
//

class CRemixApp : public CWinApp
{
public:
	CRemixApp();


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation

public:
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CRemixApp theApp;
