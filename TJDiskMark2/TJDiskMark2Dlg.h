
// TJDiskMark2Dlg.h : ��� ����
//

#pragma once
#include "afxwin.h"
#include "ntgraphctrl6.h"


// CTJDiskMark2Dlg ��ȭ ����
class CTJDiskMark2Dlg : public CDialogEx
{
// �����Դϴ�.
public:
	CTJDiskMark2Dlg(CWnd* pParent = NULL);	// ǥ�� �������Դϴ�.

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TJDISKMARK2_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV �����Դϴ�.


// �����Դϴ�.
protected:
	HICON m_hIcon;

	// ������ �޽��� �� �Լ�
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
