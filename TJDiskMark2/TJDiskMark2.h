
// TJDiskMark2.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"		// �� ��ȣ�Դϴ�.


// CTJDiskMark2App:
// �� Ŭ������ ������ ���ؼ��� TJDiskMark2.cpp�� �����Ͻʽÿ�.
//

class CTJDiskMark2App : public CWinApp
{
public:
	CTJDiskMark2App();

// �������Դϴ�.
public:
	virtual BOOL InitInstance();

// �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};

extern CTJDiskMark2App theApp;