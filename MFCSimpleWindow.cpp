
// MFCSimpleWindow.cpp : �A�v���P�[�V�����̃N���X������`���܂��B
//

#include "stdafx.h"
#include "afxwinappex.h"
#include "afxdialogex.h"
#include "MFCSimpleWindow.h"
#include "MainFrame.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCSimpleWindowApp

BEGIN_MESSAGE_MAP(CMFCSimpleWindowApp, CWinApp)
	ON_COMMAND(ID_APP_ABOUT, &CMFCSimpleWindowApp::OnAppAbout)
END_MESSAGE_MAP()


// CMFCSimpleWindowApp �R���X�g���N�V����

CMFCSimpleWindowApp::CMFCSimpleWindowApp()
{
	// �ċN���}�l�[�W���[���T�|�[�g���܂�
	m_dwRestartManagerSupportFlags = AFX_RESTART_MANAGER_SUPPORT_RESTART;
#ifdef _MANAGED
	// �A�v���P�[�V���������ʌ��ꃉ���^�C�� �T�|�[�g (/clr) ���g�p���č쐬����Ă���ꍇ:
	//     1) ���̒ǉ��ݒ�́A�ċN���}�l�[�W���[ �T�|�[�g������ɋ@�\���邽�߂ɕK�v�ł��B
	//     2) �쐬����ɂ́A�v���W�F�N�g�� System.Windows.Forms �ւ̎Q�Ƃ�ǉ�����K�v������܂��B
	System::Windows::Forms::Application::SetUnhandledExceptionMode(System::Windows::Forms::UnhandledExceptionMode::ThrowException);
#endif

	// TODO: ���̃A�v���P�[�V���� ID ���������ӂ� ID ������Œu�����܂��B���������
	// ������̌`���� CompanyName.ProductName.SubProduct.VersionInformation �ł�
	SetAppID(_T("MFCSimpleWindow.AppID.NoVersion"));

	// TODO: ���̈ʒu�ɍ\�z�p�R�[�h��ǉ����Ă��������B
	// ������ InitInstance ���̏d�v�ȏ��������������ׂċL�q���Ă��������B
}

// �B��� CMFCSimpleWindowApp �I�u�W�F�N�g�ł��B

CMFCSimpleWindowApp theApp;


// CMFCSimpleWindowApp ������

BOOL CMFCSimpleWindowApp::InitInstance()
{
	// �A�v���P�[�V���� �}�j�t�F�X�g�� visual �X�^�C����L���ɂ��邽�߂ɁA
	// ComCtl32.dll Version 6 �ȍ~�̎g�p���w�肷��ꍇ�́A
	// Windows XP �� InitCommonControlsEx() ���K�v�ł��B�����Ȃ���΁A�E�B���h�E�쐬�͂��ׂĎ��s���܂��B
	INITCOMMONCONTROLSEX InitCtrls;
	InitCtrls.dwSize = sizeof(InitCtrls);
	// �A�v���P�[�V�����Ŏg�p���邷�ׂẴR���� �R���g���[�� �N���X���܂߂�ɂ́A
	// �����ݒ肵�܂��B
	InitCtrls.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&InitCtrls);

	CWinApp::InitInstance();


	EnableTaskbarInteraction(FALSE);

	// RichEdit �R���g���[�����g�p����ɂ� AfxInitRichEdit2() ���K�v�ł�	
	// AfxInitRichEdit2();

	// �W��������
	// �����̋@�\���g�킸�ɍŏI�I�Ȏ��s�\�t�@�C����
	// �T�C�Y���k���������ꍇ�́A�ȉ�����s�v�ȏ�����
	// ���[�`�����폜���Ă��������B
	// �ݒ肪�i�[����Ă��郌�W�X�g�� �L�[��ύX���܂��B
	// TODO: ��Ж��܂��͑g�D���Ȃǂ̓K�؂ȕ������
	// ���̕������ύX���Ă��������B
	// SetRegistryKey(_T("�A�v���P�[�V���� �E�B�U�[�h�Ő������ꂽ���[�J�� �A�v���P�[�V����"));

	// ���C�� �E�B���h�E���쐬����Ƃ��A���̃R�[�h�͐V�����t���[�� �E�B���h�E �I�u�W�F�N�g���쐬���A
	// ������A�v���P�[�V�����̃��C�� �E�B���h�E�ɃZ�b�g���܂�
	CMainFrame* pFrame = new CMainFrame;
	if (!pFrame)
		return FALSE;

	m_pMainWnd = pFrame;

	BOOL bSucceeded;
	WNDCLASSEX wcex;

	memset(&wcex, 0, sizeof(wcex));
	wcex.cbSize = sizeof(wcex);

	wcex.style			= CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc	= AfxWndProc;
	wcex.cbClsExtra		= 0;
	wcex.cbWndExtra		= 0;
	wcex.hInstance		= AfxGetInstanceHandle();
	wcex.hIcon			= NULL;
	wcex.hCursor		= ::LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground	= (HBRUSH)(COLOR_WINDOW+1);
	wcex.lpszMenuName	= MAKEINTRESOURCE(IDR_MAINFRAME);
	//wcex.lpszMenuName	= NULL;
	wcex.lpszClassName	= _T("MainFrameWindowClass");
	//wcex.hIconSm		= ::LoadIcon(Instance, MAKEINTRESOURCE(IDI_SMALL));

	bSucceeded = RegisterClassEx(&wcex);
	//wcex.lpszClassName = AfxRegisterWndClass(wcex.style, wcex.hCursor, wcex.hbrBackground, wcex.hIcon);

	DWORD dwExStyle = 0;
	DWORD dwStyle = WS_OVERLAPPEDWINDOW | WS_VISIBLE;
	//bSucceeded = pFrame->CreateEx(dwExStyle, wcex.lpszClassName, _T("MAIN"), dwStyle, 0, 0, 640, 480, NULL, NULL);
	bSucceeded = pFrame->CreateEx(dwExStyle, wcex.lpszClassName, _T("MAIN"), dwStyle,
		CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL);

	if (bSucceeded) {
		// ���C�� �E�B���h�E�����������ꂽ�̂ŁA�\���ƍX�V���s���܂��B
		pFrame->ShowWindow(SW_SHOW);
		pFrame->UpdateWindow();
		// �ڔ��������݂���ꍇ�ɂ̂� DragAcceptFiles ���Ăяo���Ă��������B
		//  SDI �A�v���P�[�V�����ł́AProcessShellCommand �̒���ɂ��̌Ăяo�����������Ȃ���΂Ȃ�܂���B
	}

	return bSucceeded;
}

int CMFCSimpleWindowApp::ExitInstance()
{
	//TODO: �ǉ��������\�[�X������ꍇ�ɂ͂������������Ă�������
	return CWinApp::ExitInstance();
}

// CMFCSimpleWindowApp ���b�Z�[�W �n���h���[


// �A�v���P�[�V�����̃o�[�W�������Ɏg���� CAboutDlg �_�C�A���O

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �_�C�A���O �f�[�^
	enum { IDD = IDD_ABOUTBOX };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �T�|�[�g

// ����
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()

// �_�C�A���O�����s���邽�߂̃A�v���P�[�V���� �R�}���h
void CMFCSimpleWindowApp::OnAppAbout()
{
	CAboutDlg aboutDlg;
	aboutDlg.DoModal();
}

// CMFCSimpleWindowApp ���b�Z�[�W �n���h���[



