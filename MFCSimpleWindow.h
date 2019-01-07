
// MFCSimpleWindow.h : MFCSimpleWindow アプリケーションのメイン ヘッダー ファイル
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH に対してこのファイルをインクルードする前に 'stdafx.h' をインクルードしてください"
#endif

#include "resource.h"       // メイン シンボル


// CMFCSimpleWindowApp:
// このクラスの実装については、MFCSimpleWindow.cpp を参照してください。
//

class CMFCSimpleWindowApp : public CWinApp
{
public:
	CMFCSimpleWindowApp();


// オーバーライド
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// 実装

public:
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMFCSimpleWindowApp theApp;
