
// TJDiskMark2Dlg.h : 헤더 파일
//

#pragma once
#include "afxwin.h"
#include "ntgraphctrl6.h"


// CTJDiskMark2Dlg 대화 상자
class CTJDiskMark2Dlg : public CDialogEx
{
// 생성입니다.
public:
	CTJDiskMark2Dlg(CWnd* pParent = NULL);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TJDISKMARK2_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CComboBox m_comboTrialNumber;
	afx_msg void OnCbnSelchangeCombo1();
	afx_msg void OnBnClickedButton5();
	DECLARE_EVENTSINK_MAP()
	void CursorPositionNtgraphctrl6(double X, double Y);
	short file_size;
};
