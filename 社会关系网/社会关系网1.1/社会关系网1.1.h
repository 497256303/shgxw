
// ����ϵ��1.1.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// C����ϵ��11App: 
// �йش����ʵ�֣������ ����ϵ��1.1.cpp
//

class C����ϵ��11App : public CWinApp
{
public:
	C����ϵ��11App();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern C����ϵ��11App theApp;