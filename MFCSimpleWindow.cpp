
// MFCSimpleWindow.cpp : アプリケーションのクラス動作を定義します。
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


// CMFCSimpleWindowApp コンストラクション

CMFCSimpleWindowApp::CMFCSimpleWindowApp()
{
	// 再起動マネージャーをサポートします
	m_dwRestartManagerSupportFlags = AFX_RESTART_MANAGER_SUPPORT_RESTART;
#ifdef _MANAGED
	// アプリケーションが共通言語ランタイム サポート (/clr) を使用して作成されている場合:
	//     1) この追加設定は、再起動マネージャー サポートが正常に機能するために必要です。
	//     2) 作成するには、プロジェクトに System.Windows.Forms への参照を追加する必要があります。
	System::Windows::Forms::Application::SetUnhandledExceptionMode(System::Windows::Forms::UnhandledExceptionMode::ThrowException);
#endif

	// TODO: 下のアプリケーション ID 文字列を一意の ID 文字列で置換します。推奨される
	// 文字列の形式は CompanyName.ProductName.SubProduct.VersionInformation です
	SetAppID(_T("MFCSimpleWindow.AppID.NoVersion"));

	// TODO: この位置に構築用コードを追加してください。
	// ここに InitInstance 中の重要な初期化処理をすべて記述してください。
}

// 唯一の CMFCSimpleWindowApp オブジェクトです。

CMFCSimpleWindowApp theApp;


// CMFCSimpleWindowApp 初期化

BOOL CMFCSimpleWindowApp::InitInstance()
{
	// アプリケーション マニフェストが visual スタイルを有効にするために、
	// ComCtl32.dll Version 6 以降の使用を指定する場合は、
	// Windows XP に InitCommonControlsEx() が必要です。さもなければ、ウィンドウ作成はすべて失敗します。
	INITCOMMONCONTROLSEX InitCtrls;
	InitCtrls.dwSize = sizeof(InitCtrls);
	// アプリケーションで使用するすべてのコモン コントロール クラスを含めるには、
	// これを設定します。
	InitCtrls.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&InitCtrls);

	CWinApp::InitInstance();


	EnableTaskbarInteraction(FALSE);

	// RichEdit コントロールを使用するには AfxInitRichEdit2() が必要です	
	// AfxInitRichEdit2();

	// 標準初期化
	// これらの機能を使わずに最終的な実行可能ファイルの
	// サイズを縮小したい場合は、以下から不要な初期化
	// ルーチンを削除してください。
	// 設定が格納されているレジストリ キーを変更します。
	// TODO: 会社名または組織名などの適切な文字列に
	// この文字列を変更してください。
	// SetRegistryKey(_T("アプリケーション ウィザードで生成されたローカル アプリケーション"));

	// メイン ウィンドウを作成するとき、このコードは新しいフレーム ウィンドウ オブジェクトを作成し、
	// それをアプリケーションのメイン ウィンドウにセットします
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
		// メイン ウィンドウが初期化されたので、表示と更新を行います。
		pFrame->ShowWindow(SW_SHOW);
		pFrame->UpdateWindow();
		// 接尾辞が存在する場合にのみ DragAcceptFiles を呼び出してください。
		//  SDI アプリケーションでは、ProcessShellCommand の直後にこの呼び出しが発生しなければなりません。
	}

	return bSucceeded;
}

int CMFCSimpleWindowApp::ExitInstance()
{
	//TODO: 追加したリソースがある場合にはそれらも処理してください
	return CWinApp::ExitInstance();
}

// CMFCSimpleWindowApp メッセージ ハンドラー


// アプリケーションのバージョン情報に使われる CAboutDlg ダイアログ

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// ダイアログ データ
	enum { IDD = IDD_ABOUTBOX };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV サポート

// 実装
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

// ダイアログを実行するためのアプリケーション コマンド
void CMFCSimpleWindowApp::OnAppAbout()
{
	CAboutDlg aboutDlg;
	aboutDlg.DoModal();
}

// CMFCSimpleWindowApp メッセージ ハンドラー



