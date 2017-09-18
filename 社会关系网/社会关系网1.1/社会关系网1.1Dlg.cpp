
// 社会关系网1.1Dlg.cpp : 实现文件
//
#include "stdafx.h"
#include "社会关系网1.1.h"
#include "社会关系网1.1Dlg.h"
#include "afxdialogex.h"
#include <string>
#include <cstring>
#include <iostream>
#include <time.h>
#include <sstream>
using namespace std;
#ifdef _DEBUG
#define new DEBUG_NEW
#endif

int place[20], school[20], unit[20], num_friends[20], temp_num[20];
bool friends[20][20];

// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
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


// C社会关系网11Dlg 对话框



C社会关系网11Dlg::C社会关系网11Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_MY11_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void C社会关系网11Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(C社会关系网11Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &C社会关系网11Dlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &C社会关系网11Dlg::OnBnClickedButton2)
END_MESSAGE_MAP()


// C社会关系网11Dlg 消息处理程序

BOOL C社会关系网11Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
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

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void C社会关系网11Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void C社会关系网11Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR C社会关系网11Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void C社会关系网11Dlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	CString s;
	srand((unsigned)time(NULL));  
	string a;
	a = "姓名\t城市\t学校\t单位\t好友\r\n";
	for (int i = 0; i < NUM; i++)
	{
		for (int j = 0; j < NUM; j++)
			friends[i][j] = 0;
		place[i] = school[i] = unit[i] = num_friends[i] = temp_num[i] =  0;
	}	
	for (int i = 0; i < NUM; i++)
	{

		place[i] = rand() % 2, school[i] = rand() % 4, unit[i] = rand() % 4;
		num_friends[i] = rand() % MAX + 1;
		//if (num_friends[i] < temp_num[i])
		//	num_friends[i] = temp_num[i];
		friends[i][i] = 1;
		for (int j = 0; j < num_friends[i] - temp_num[i]; j++)
		{
			while (1)
			{
				int k = rand() % NUM;
				if (!friends[i][k]&&temp_num[k]<MAX)
				{
					friends[i][k] = friends[k][i] = 1;
					temp_num[i]++;
					temp_num[k]++;
					break;
				}
			}
		}
	}
	for (int i = 0; i < NUM; i++)
	{
		string b, c = "\t", d = "\r\n", e = " ", temp_friends;
		char temp_place = 'a' + place[i] , temp_school = 'a' + school[i], temp_unit = 'a' + unit[i], temp_name = 'A' + i;
		for (int j = 0; j < NUM; j++)
			if (friends[i][j] && j != i)
			{
				char nnum;
				nnum = 'A' + j;
				temp_friends = temp_friends + nnum + e;
			}
		a = a + temp_name + c + temp_place + c + temp_school + c + temp_unit + c + temp_friends + d;
	}
	s = a.c_str();
	SetDlgItemText(IDC_EDIT1, s);
	UpdateData(FALSE);
}


void C社会关系网11Dlg::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	int ipos = ((CComboBox*)GetDlgItem(IDC_COMBO1))->GetCurSel();
	int num_same[NUM] = { 0 };
	for (int i = 0; i < NUM; i++)
	{
		if (!friends[ipos][i])
			for (int j = 0; j < NUM; j++)
			{
				if (friends[ipos][j] && friends[i][j])
					num_same[i]++;
			}
	}
	string a = "姓名\t共同好友数\r\n", b, c = "\t", d = "\r\n", e = " ", f = "无";
	int max = NUM, min = 0, min_num[NUM], temp = 0;
	while (1)
	{
		for (int j = 0; j < NUM; j++)
		{
			if (num_same[j] > min&&num_same[j] < max)
			{
				min = num_same[j];
				for (int i = 0; i < NUM; i++)
					min_num[i] = -1;
				min_num[0] = j;
				temp = 1;
			}
			else if (num_same[j] == min)
			{
				min_num[temp] = j;
				temp++;
			}
		}
		if (min > 0)
		{
			max = min;
			for (int i = 0; min_num[i] != -1; i++)
			{
				char ch = 'A' + min_num[i];
				a += ch + c;
				stringstream num;
				num << min;
				num >> b;
				a += b + d;
			}
			min = 0;
		}
		else
			break;
	}
	CString s;
	s = a.c_str();
	SetDlgItemText(IDC_EDIT2, s);


	string str_ps = "", str_pu = "", str_su = "", str_psu = "";
	for (int i = 0; i < NUM; i++)
	{
		char ch;
		if (place[ipos] == place[i] && school[ipos] == school[i] && ipos != i)
		{
			ch = 'A' + i;
			str_ps += ch + e;
		}
		if (place[ipos] == place[i] && unit[ipos] == unit[i] && ipos != i)
		{
			ch = 'A' + i;
			str_pu += ch + e;
		}
		if (unit[ipos] == unit[i] && school[ipos] == school[i] && ipos != i)
		{
			ch = 'A' + i;
			str_su += ch + e;
		}
		if (place[ipos] == place[i] && school[ipos] == school[i] && unit[ipos] == unit[i] && ipos != i)
		{
			ch = 'A' + i;
			str_psu += ch + e;
		}
	}
	CString ps, pu, su, psu;
	if (str_ps == "")
		str_ps += f;
	if (str_su == "")
		str_su += f;
	if (str_pu == "")
		str_pu += f;
	if (str_psu == "")
		str_psu += f;
	ps = str_ps.c_str();
	SetDlgItemText(IDC_EDIT3, ps);
	pu = str_pu.c_str();
	SetDlgItemText(IDC_EDIT4, pu);
	su = str_su.c_str();
	SetDlgItemText(IDC_EDIT5, su);
	psu = str_psu.c_str();
	SetDlgItemText(IDC_EDIT6, psu);

}
