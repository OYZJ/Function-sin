
// sinDlg.cpp : 实现文件
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

// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
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


// CsinDlg 对话框




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


// CsinDlg 消息处理程序

BOOL CsinDlg::OnInitDialog()
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

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
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

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CsinDlg::OnPaint()
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
		CPaintDC dc(this); // 用于绘制的设备上下文
		CPen pen(PS_SOLID,1,RGB(200,500,1000));//调节线的颜色
		dc.SelectObject(&pen);
        dc.Rectangle(40,400,700,50); // 绘制矩形框
		dc.MoveTo(40,85);//制作表格线
		dc.LineTo(700,85);
		dc.MoveTo(40,155);
		dc.LineTo(700,155);
		dc.MoveTo(40,225);
		dc.LineTo(700,225);
		dc.MoveTo(40,295);
		dc.LineTo(700,295);
		dc.MoveTo(40,365);
		dc.LineTo(700,365);//横线

		dc.MoveTo(200,50);
		dc.LineTo(200,400);
		dc.MoveTo(400,50);
		dc.LineTo(400,400);
		dc.MoveTo(600,50);
		dc.LineTo(600,400);//竖线
        CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CsinDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CsinDlg::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData();
	AfxGetMainWnd()->SendMessage(WM_CLOSE);
}


void CsinDlg::OnBnClickedMfccolorbutton1()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData();
	SinCurve=ClrBtn.GetColor();

}


void CsinDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData();
	
	 CBrush brush(RGB(255,255,255));
     CClientDC dc(this);
     dc.FillRect(CRect(40,400,700,50),&brush);//笔刷
     CsinDlg::OnPaint();
	 CPen pen(PS_SOLID,1,RGB(200,500,1000));//调节线的颜色
		dc.SelectObject(&pen);
	 dc.MoveTo(40,85);//制作表格线
		dc.LineTo(700,85);
		dc.MoveTo(40,155);
		dc.LineTo(700,155);
		dc.MoveTo(40,225);
		dc.LineTo(700,225);
		dc.MoveTo(40,295);
		dc.LineTo(700,295);
		dc.MoveTo(40,365);
		dc.LineTo(700,365);//横线

		dc.MoveTo(200,50);
		dc.LineTo(200,400);
		dc.MoveTo(400,50);
		dc.LineTo(400,400);
		dc.MoveTo(600,50);
		dc.LineTo(600,400);//竖线
        CDialogEx::OnPaint();
    Draw();//画出sin函数

    int i=1;
    double X,S=0;
    X=combo;
    for (i=1;i<1000/combo;i++)
{
	S=slider_int*sin(i*combo*PIE/1000)*X+S;
}
sin_edit_double=2*S;//计算面积(定积分)
UpdateData(FALSE);

}

int CsinDlg::Draw()
{
// TODO: 在此添加控件通知处理程序代码 
UpdateData();
	// 获得绘图控件句柄和区域
	CWnd *pCanvasWnd=GetDlgItem(IDC_CANVAS);
	CDC *pCanvasDC=pCanvasWnd->GetDC();
	CRect rect;
	pCanvasWnd->GetClientRect(&rect);

	//创建画笔
	CPen SinPen;
	CPen *OldPen;
	SinPen.CreatePen(PS_SOLID,2,SinCurve);
	OldPen=pCanvasDC->SelectObject(&SinPen);
	//画出Sin函数
	DrawSinFun(pCanvasDC,rect);
	//恢复画笔
	pCanvasDC->SelectObject(OldPen);


	//释放资源
	pCanvasDC->Detach();
	pCanvasWnd->Detach();
	return 0;
}

void CsinDlg::DrawSinFun(CDC* pCanvasDC, const CRect &rect)
{
	UpdateData();
	//根据画布规定起始点和放大倍数
	int BaseY=rect.TopLeft().y+rect.Height()/2;
	int BaseX=rect.TopLeft().x;
	int yScale=slider_int*1.4;
	int xScale=rect.Width()/6.2;
	//计算sin(x),并画出离散的直线
	double x[LEN];
	for (int i=0; i<LEN-1; i++)
	{
		//计算sin(x)
		x[i]=2*PIE/LEN*i;
		x[i+1]=2*PIE/LEN*(i+1);
		CPoint p1,p2;
		p1.x=(int)(BaseX+x[i]*xScale);
		p1.y=(int)(BaseY-sin(x[i])*yScale);
		p2.x=(int)(BaseX+x[i+1]*xScale);
		p2.y=(int)(BaseY-sin(x[i+1])*yScale);
		//画直线
		pCanvasDC->MoveTo(p1);
		pCanvasDC->LineTo(p2);
	}
	UpdateData(FALSE);
}


void CsinDlg::OnNMCustomdrawSlider2(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	*pResult = 0;
	UpdateData();
	CString str;
	str.Format(_T("%d"),slider_int);
	edit_str=str;
	UpdateData(FALSE);
}


void CsinDlg::OnCbnSelchangeCombo1()
{
	// TODO: 在此添加控件通知处理程序代码
}


void CsinDlg::OnEnChangeEdit4()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void CsinDlg::OnCbnSelchangeCombo5()
{
	// TODO: 在此添加控件通知处理程序代码
}


void CsinDlg::OnCbnSelchangeCombo4()
{
	// TODO: 在此添加控件通知处理程序代码
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
		 default: break;//取combo box中的data数据
	}

	UpdateData(FALSE);
	
}


void CsinDlg::OnStnClickedCanvas()
{
	// TODO: 在此添加控件通知处理程序代码
}
