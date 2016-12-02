
// TmpDiskMarkDlg.cpp : implementation file
//

#include "stdafx.h"
#include "TmpDiskMark.h"
#include "afxdialogex.h"
#include "TmpDiskMarkDlg.h"
#include "BenchMark.h" 
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About


class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CTmpDiskMarkDlg dialog



CTmpDiskMarkDlg::CTmpDiskMarkDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_TMPDISKMARK_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CTmpDiskMarkDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CTmpDiskMarkDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CTmpDiskMarkDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CTmpDiskMarkDlg::OnBnClickedButton2)
	ON_NOTIFY(TCN_SELCHANGE, IDC_TAB1, &CTmpDiskMarkDlg::OnTcnSelchangeTab1)
	ON_BN_CLICKED(IDC_BUTTON4, &CTmpDiskMarkDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON3, &CTmpDiskMarkDlg::OnBnClickedButton3)
END_MESSAGE_MAP()


// CTmpDiskMarkDlg message handlers

BOOL CTmpDiskMarkDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CTmpDiskMarkDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CTmpDiskMarkDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CTmpDiskMarkDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CTmpDiskMarkDlg::OnBnClickedButton1()
{
	// TODO: Add your control notification handler code here
	UpdateData();
	long long value = main_thr(1);

	CString v1_sMessageToDisplay;
	v1_sMessageToDisplay.Format(_T("time is %d "), value); 
	MessageBox(v1_sMessageToDisplay, 0, MB_ICONINFORMATION);

}


void CTmpDiskMarkDlg::OnBnClickedButton2()
{
	// TODO: Add your control notification handler code here
	UpdateData();

	long long value = main_thr(2);
	CString v1_sMessageToDisplay;
	v1_sMessageToDisplay.Format(_T("time is %d "), value);
	MessageBox(v1_sMessageToDisplay, 0, MB_ICONINFORMATION);

}


void CTmpDiskMarkDlg::OnTcnSelchangeTab1(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: Add your control notification handler code here
	*pResult = 0;
}


void CTmpDiskMarkDlg::OnBnClickedButton4()
{
	// TODO: Add your control notification handler code here
	UpdateData();
	long long value = main_thr(4);

	CString v1_sMessageToDisplay;
	v1_sMessageToDisplay.Format(_T("time is %d "), value);
	MessageBox(v1_sMessageToDisplay, 0, MB_ICONINFORMATION);
}


void CTmpDiskMarkDlg::OnBnClickedButton3()
{
	// TODO: Add your control notification handler code here
	UpdateData();
	long long value = main_thr(3);

	CString v1_sMessageToDisplay;
	v1_sMessageToDisplay.Format(_T("time is %d "), value);
	MessageBox(v1_sMessageToDisplay, 0, MB_ICONINFORMATION);
}
