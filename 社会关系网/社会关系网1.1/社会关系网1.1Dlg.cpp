
// ����ϵ��1.1Dlg.cpp : ʵ���ļ�
//
#include "stdafx.h"
#include "����ϵ��1.1.h"
#include "����ϵ��1.1Dlg.h"
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

// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
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


// C����ϵ��11Dlg �Ի���



C����ϵ��11Dlg::C����ϵ��11Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_MY11_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void C����ϵ��11Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(C����ϵ��11Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &C����ϵ��11Dlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &C����ϵ��11Dlg::OnBnClickedButton2)
END_MESSAGE_MAP()


// C����ϵ��11Dlg ��Ϣ�������

BOOL C����ϵ��11Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
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

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void C����ϵ��11Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void C����ϵ��11Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR C����ϵ��11Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void C����ϵ��11Dlg::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	CString s;
	srand((unsigned)time(NULL));  
	string a;
	a = "����\t����\tѧУ\t��λ\t����\r\n";
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


void C����ϵ��11Dlg::OnBnClickedButton2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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
	string a = "����\t��ͬ������\r\n", b, c = "\t", d = "\r\n", e = " ", f = "��";
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
