
// sinDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "sin.h"
#include "sinDlg.h"
#include "afxdialogex.h"
#include <cmath>
#ifdef _DEBUG
#define new DEBUG_NEW
#endif
#define LEN 500
int combo;

// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
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


// CsinDlg �Ի���




CsinDlg::CsinDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CsinDlg::IDD, pParent)
	, slider_int(0)
	, edit_str(_T(""))
	, combo_int(_T(""))
	, edit_str2(_T(""))
	, sin_edit_double(0)
	, sin_edit_int(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CsinDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_MFCCOLORBUTTON1, ClrBtn);
	DDX_Slider(pDX, IDC_SLIDER2, slider_int);
	DDX_Text(pDX, IDC_EDIT1, edit_str);

	DDX_Text(pDX, IDC_EDIT4, sin_edit_double);
	DDX_CBIndex(pDX, IDC_COMBO4, sin_edit_int);
}

BEGIN_MESSAGE_MAP(CsinDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON2, &CsinDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_MFCCOLORBUTTON1, &CsinDlg::OnBnClickedMfccolorbutton1)
	ON_BN_CLICKED(IDC_BUTTON1, &CsinDlg::OnBnClickedButton1)
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_SLIDER2, &CsinDlg::OnNMCustomdrawSlider2)

	ON_EN_CHANGE(IDC_EDIT4, &CsinDlg::OnEnChangeEdit4)
	ON_CBN_SELCHANGE(IDC_COMBO5, &CsinDlg::OnCbnSelchangeCombo5)
	ON_CBN_SELCHANGE(IDC_COMBO4, &CsinDlg::OnCbnSelchangeCombo4)
	ON_STN_CLICKED(IDC_CANVAS, &CsinDlg::OnStnClickedCanvas)
END_MESSAGE_MAP()


// CsinDlg ��Ϣ�������

BOOL CsinDlg::OnInitDialog()
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

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CsinDlg::OnSysCommand(UINT nID, LPARAM lParam)
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
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CsinDlg::OnPaint()
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
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������
		CPen pen(PS_SOLID,1,RGB(200,500,1000));//�����ߵ���ɫ
		dc.SelectObject(&pen);
        dc.Rectangle(40,400,700,50); // ���ƾ��ο�
		dc.MoveTo(40,85);//���������
		dc.LineTo(700,85);
		dc.MoveTo(40,155);
		dc.LineTo(700,155);
		dc.MoveTo(40,225);
		dc.LineTo(700,225);
		dc.MoveTo(40,295);
		dc.LineTo(700,295);
		dc.MoveTo(40,365);
		dc.LineTo(700,365);//����

		dc.MoveTo(200,50);
		dc.LineTo(200,400);
		dc.MoveTo(400,50);
		dc.LineTo(400,400);
		dc.MoveTo(600,50);
		dc.LineTo(600,400);//����
        CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CsinDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CsinDlg::OnBnClickedButton2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData();
	AfxGetMainWnd()->SendMessage(WM_CLOSE);
}


void CsinDlg::OnBnClickedMfccolorbutton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData();
	SinCurve=ClrBtn.GetColor();

}


void CsinDlg::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData();
	
	 CBrush brush(RGB(255,255,255));
     CClientDC dc(this);
     dc.FillRect(CRect(40,400,700,50),&brush);//��ˢ
     CsinDlg::OnPaint();
	 CPen pen(PS_SOLID,1,RGB(200,500,1000));//�����ߵ���ɫ
		dc.SelectObject(&pen);
	 dc.MoveTo(40,85);//���������
		dc.LineTo(700,85);
		dc.MoveTo(40,155);
		dc.LineTo(700,155);
		dc.MoveTo(40,225);
		dc.LineTo(700,225);
		dc.MoveTo(40,295);
		dc.LineTo(700,295);
		dc.MoveTo(40,365);
		dc.LineTo(700,365);//����

		dc.MoveTo(200,50);
		dc.LineTo(200,400);
		dc.MoveTo(400,50);
		dc.LineTo(400,400);
		dc.MoveTo(600,50);
		dc.LineTo(600,400);//����
        CDialogEx::OnPaint();
    Draw();//����sin����

    int i=1;
    double X,S=0;
    X=combo;
    for (i=1;i<1000/combo;i++)
{
	S=slider_int*sin(i*combo*PIE/1000)*X+S;
}
sin_edit_double=2*S;//�������(������)
UpdateData(FALSE);

}

int CsinDlg::Draw()
{
// TODO: �ڴ���ӿؼ�֪ͨ���������� 
UpdateData();
	// ��û�ͼ�ؼ����������
	CWnd *pCanvasWnd=GetDlgItem(IDC_CANVAS);
	CDC *pCanvasDC=pCanvasWnd->GetDC();
	CRect rect;
	pCanvasWnd->GetClientRect(&rect);

	//��������
	CPen SinPen;
	CPen *OldPen;
	SinPen.CreatePen(PS_SOLID,2,SinCurve);
	OldPen=pCanvasDC->SelectObject(&SinPen);
	//����Sin����
	DrawSinFun(pCanvasDC,rect);
	//�ָ�����
	pCanvasDC->SelectObject(OldPen);


	//�ͷ���Դ
	pCanvasDC->Detach();
	pCanvasWnd->Detach();
	return 0;
}

void CsinDlg::DrawSinFun(CDC* pCanvasDC, const CRect &rect)
{
	UpdateData();
	//���ݻ����涨��ʼ��ͷŴ���
	int BaseY=rect.TopLeft().y+rect.Height()/2;
	int BaseX=rect.TopLeft().x;
	int yScale=slider_int*1.4;
	int xScale=rect.Width()/6.2;
	//����sin(x),��������ɢ��ֱ��
	double x[LEN];
	for (int i=0; i<LEN-1; i++)
	{
		//����sin(x)
		x[i]=2*PIE/LEN*i;
		x[i+1]=2*PIE/LEN*(i+1);
		CPoint p1,p2;
		p1.x=(int)(BaseX+x[i]*xScale);
		p1.y=(int)(BaseY-sin(x[i])*yScale);
		p2.x=(int)(BaseX+x[i+1]*xScale);
		p2.y=(int)(BaseY-sin(x[i+1])*yScale);
		//��ֱ��
		pCanvasDC->MoveTo(p1);
		pCanvasDC->LineTo(p2);
	}
	UpdateData(FALSE);
}


void CsinDlg::OnNMCustomdrawSlider2(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	*pResult = 0;
	UpdateData();
	CString str;
	str.Format(_T("%d"),slider_int);
	edit_str=str;
	UpdateData(FALSE);
}


void CsinDlg::OnCbnSelchangeCombo1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void CsinDlg::OnEnChangeEdit4()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}


void CsinDlg::OnCbnSelchangeCombo5()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void CsinDlg::OnCbnSelchangeCombo4()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
		UpdateData();
	
	switch(sin_edit_int)
	{

         case 1: combo=1;     break;
		 case 2: combo=2;     break;
		 case 3: combo=5;     break;
		 case 4: combo=10;     break;
		 case 5: combo=20;     break;
		 case 6: combo=50;     break;
		 case 7: combo=100;    break;
		 case 8: combo=200;    break;
		 case 9: combo=500;    break;
		 default: break;//ȡcombo box�е�data����
	}

	UpdateData(FALSE);
	
}


void CsinDlg::OnStnClickedCanvas()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}
