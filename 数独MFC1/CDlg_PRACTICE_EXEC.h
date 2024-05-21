#pragma once
#include "afxdialogex.h"
#include "Sudoku.h"

// CDlg_PRACTICE_EXEC 对话框

class CDlg_PRACTICE_EXEC : public CDialogEx
{
	DECLARE_DYNAMIC(CDlg_PRACTICE_EXEC)

public:
	CDlg_PRACTICE_EXEC(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CDlg_PRACTICE_EXEC();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_2EXEC };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPaint();

private:
	Sudoku sudoku;

public:
	clock_t start_time;
	clock_t end_time;
	CComboBox m_combo;
	int option;
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton1();
};
