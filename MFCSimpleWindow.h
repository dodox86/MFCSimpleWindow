
// MFCSimpleWindow.h : MFCSimpleWindow �A�v���P�[�V�����̃��C�� �w�b�_�[ �t�@�C��
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH �ɑ΂��Ă��̃t�@�C�����C���N���[�h����O�� 'stdafx.h' ���C���N���[�h���Ă�������"
#endif

#include "resource.h"       // ���C�� �V���{��


// CMFCSimpleWindowApp:
// ���̃N���X�̎����ɂ��ẮAMFCSimpleWindow.cpp ���Q�Ƃ��Ă��������B
//

class CMFCSimpleWindowApp : public CWinApp
{
public:
	CMFCSimpleWindowApp();


// �I�[�o�[���C�h
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ����

public:
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMFCSimpleWindowApp theApp;
