#pragma once
#include "afxdialogex.h"
#include "Sudoku.h"


// CDlgEXEC_SOVLE 对话框

class CDlg_SOVLE_EXEC : public CDialogEx
{
	DECLARE_DYNAMIC(CDlg_SOVLE_EXEC)

public:
	CDlg_SOVLE_EXEC(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CDlg_SOVLE_EXEC();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_1EXEC };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
		virtual void OnOK();
public:
	afx_msg void OnPaint();
	afx_msg void OnBnClickedOk();
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedButton1();

public:
	Sudoku sudoku;
	int curGame[9][9];
	CComboBox m_combo;
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
};
