
// sinDlg.h : ͷ�ļ�
//

#pragma once
#include "afxcolorbutton.h"
const double PIE=3.1415926;


// CsinDlg �Ի���
class CsinDlg : public CDialogEx
{
// ����
public:
	CsinDlg(CWnd* pParent = NULL);	// ��׼���캯��
	

// �Ի�������
	enum { IDD = IDD_SIN_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedMfccolorbutton1();
	afx_msg void OnBnClickedButton1();
	void DrawSinFun(CDC* pCanvasDC, const CRect &rect);
    COLORREF SinCurve;
    int Draw();
	CMFCColorButton ClrBtn;
	afx_msg void OnNMCustomdrawSlider2(NMHDR *pNMHDR, LRESULT *pResult);
	int slider_int;
	CString edit_str;
	afx_msg void OnCbnSelchangeCombo1();
	CString combo_int;
	CString edit_str2;
	double sin_edit_double;
	int sin_edit_int;
	afx_msg void OnEnChangeEdit4();
	afx_msg void OnCbnSelchangeCombo5();
	afx_msg void OnCbnSelchangeCombo4();
	afx_msg void OnStnClickedCanvas();
};
