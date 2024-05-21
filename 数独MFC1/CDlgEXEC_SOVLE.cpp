// CDlgEXEC_SOVLE.cpp: 实现文件
//
#include <string>
#include <cstring>
#include "pch.h"
#include "数独MFC1.h"
#include "afxdialogex.h"
#include "CDlgEXEC_SOVLE.h"



// CDlgEXEC_SOVLE 对话框

IMPLEMENT_DYNAMIC(CDlg_SOVLE_EXEC, CDialogEx)

CDlg_SOVLE_EXEC::CDlg_SOVLE_EXEC(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_1EXEC, pParent)
{

}

CDlg_SOVLE_EXEC::~CDlg_SOVLE_EXEC()
{

}

void CDlg_SOVLE_EXEC::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO1, m_combo);
}


BEGIN_MESSAGE_MAP(CDlg_SOVLE_EXEC, CDialogEx)
	ON_WM_PAINT()
	ON_BN_CLICKED(IDOK, &CDlg_SOVLE_EXEC::OnBnClickedOk)
	ON_BN_CLICKED(IDC_BUTTON1, &CDlg_SOVLE_EXEC::OnBnClickedButton1)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()


// CDlgEXEC_SOVLE 消息处理程序


void CDlg_SOVLE_EXEC::OnOK()
{
	// TODO: 在此添加专用代码和/或调用基类
	CDialogEx::OnOK();
}


void CDlg_SOVLE_EXEC::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: 在此处添加消息处理程序代码
	// 不为绘图消息调用 CDialogEx::OnPaint()

	//准备画笔以及参数
	//画棋盘
	CDC* pdc;
	pdc = GetDC();
	CPen pen(PS_SOLID, 2, RGB(0, 0, 0));
	CPen* pOldpen = pdc->SelectObject(&pen);//获取指针
	//强调棋盘
	CDC* pdc1;
	pdc1 = GetDC();
	CPen pen1(PS_SOLID, 5, RGB(0, 0, 0));
	CPen* pOldpen1 = pdc1->SelectObject(&pen1);//获取指针
	int Ox = 50;
	int Oy = 50;
	int numx = 9;//行数
	int numy = 9;//列数 



	//棋盘外放框
	for (int i = 0; i < 2; i++)
	{
		//划竖线
		pdc->MoveTo(Ox - 25 + numx * 55 * i, Oy - 30);
		pdc->LineTo(Ox - 25 + numx * 55 * i, Oy + 15 + 50 * numy);
		//划横线
		pdc->MoveTo(Ox - 25, Oy - 30 + numx * 55 * i);
		pdc->LineTo(Ox + 20 + 50 * numx, Oy - 30 + numx * 55 * i);
	}



	//棋盘坐标参数
	dc.SetBkMode(TRANSPARENT);
	dc.TextOutW(Ox + 20 + 0 * 50, Oy - 25, TEXT("1"));
	dc.TextOutW(Ox + 20 + 1 * 50, Oy - 25, TEXT("2"));
	dc.TextOutW(Ox + 20 + 2 * 50, Oy - 25, TEXT("3"));
	dc.TextOutW(Ox + 20 + 3 * 50, Oy - 25, TEXT("4"));
	dc.TextOutW(Ox + 20 + 4 * 50, Oy - 25, TEXT("5"));
	dc.TextOutW(Ox + 20 + 5 * 50, Oy - 25, TEXT("6"));
	dc.TextOutW(Ox + 20 + 6 * 50, Oy - 25, TEXT("7"));
	dc.TextOutW(Ox + 20 + 7 * 50, Oy - 25, TEXT("8"));
	dc.TextOutW(Ox + 20 + 8 * 50, Oy - 25, TEXT("9"));

	dc.TextOutW(Ox - 20, Oy + 15 + 0 * 50, TEXT("1"));
	dc.TextOutW(Ox - 20, Oy + 15 + 1 * 50, TEXT("2"));
	dc.TextOutW(Ox - 20, Oy + 15 + 2 * 50, TEXT("3"));
	dc.TextOutW(Ox - 20, Oy + 15 + 3 * 50, TEXT("4"));
	dc.TextOutW(Ox - 20, Oy + 15 + 4 * 50, TEXT("5"));
	dc.TextOutW(Ox - 20, Oy + 15 + 5 * 50, TEXT("6"));
	dc.TextOutW(Ox - 20, Oy + 15 + 6 * 50, TEXT("7"));
	dc.TextOutW(Ox - 20, Oy + 15 + 7 * 50, TEXT("8"));
	dc.TextOutW(Ox - 20, Oy + 15 + 8 * 50, TEXT("9"));

	dc.TextOutW(Ox + 26 + 1 * 50, Oy + 25, TEXT("B"));

	//颜色填充
	CBrush brush1(RGB(119, 162, 109));
	for (int n = 0; n < numy; n += 1)
	{
		for (int m = (n % 2 == 0) ? 0 : 1; m < numx; m += 2)
		{
			CRect rc(Ox + 50 * m, Oy + n * 50, Ox + 50 + 50 * m, Oy + 50 + n * 50);
			pdc->FillRect(rc, &brush1);
		}
	}
	CBrush brush2(RGB(200, 196, 109));
	for (int n = 0; n < numy; n += 1)
	{
		for (int m = (n % 2 == 0) ? 1 : 0; m < numx; m += 2)
		{
			CRect rc(Ox + 50 * m, Oy + n * 50, Ox + 50 + 50 * m, Oy + 50 + n * 50);
			pdc->FillRect(rc, &brush2);
		}
	}

	//绘制棋盘
	for (int i = 0; i <= numx; i++)//画列线
	{
		if (i % 3 == 0) {
			pdc->MoveTo(Ox + 50 * i, Oy);
			pdc->LineTo(Ox + 50 * i, Oy + 50 * numy);
		}
	}
	for (int j = 0; j <= numy; j++)//画行线
	{
		if (j % 3 == 0) {
			pdc->MoveTo(Ox, Oy + 50 * j);
			pdc->LineTo(Ox + 50 * numx, Oy + 50 * j);
		}
	}
	
	//写入数字
	for (int i = 0; i < numx; i++) {
		for (int j = 0; j < numy; j++) {
			if (sudoku.myGame[i][j] != 0) {
				CString str(char('0' + sudoku.myGame[i][j]));
				dc.TextOutW(Ox + 20 + i * 50, Oy + 15 + j * 50, str);
			}
		}
	}

	ReleaseDC(pdc);
	ReleaseDC(pdc1);
}


void CDlg_SOVLE_EXEC::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnOK();
}


BOOL CDlg_SOVLE_EXEC::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化

	//下拉框初始化
	m_combo.AddString(TEXT("0"));
	m_combo.AddString(TEXT("1"));
	m_combo.AddString(TEXT("2"));
	m_combo.AddString(TEXT("3"));
	m_combo.AddString(TEXT("4"));
	m_combo.AddString(TEXT("5"));
	m_combo.AddString(TEXT("6"));
	m_combo.AddString(TEXT("7"));
	m_combo.AddString(TEXT("8"));
	m_combo.AddString(TEXT("9"));
	m_combo.SetCurSel(0);

	CDlg_SOVLE_EXEC::OnPaint();

	CPaintDC dc(this); // device context for painting
dc.SetBkMode(TRANSPARENT);
for (int i = 0; i < 9; i++) {
	for (int j = 0; j < 9; j++) {
		if (sudoku.myGame[i][j] != 0) {
			CString str(char('0' + sudoku.myGame[i][j]));
			dc.TextOutW(50 + 5 + i * 50, 50 + 5 + j * 50, str);
		}
	}
}



	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}


void CDlg_SOVLE_EXEC::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	sudoku.getAnswer(0);
	OnPaint();
}


void CDlg_SOVLE_EXEC::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	int x = point.x / 50 - 1;
	int y = point.y / 50 - 1;
	if (x >= 0 && x < 9 && y >= 0 && y < 9) {
		int value = m_combo.GetCurSel() ;

		CString str1(char(x + '1'));
		CString str2(char(y + '1'));
		CString str3(char(value + '0'));
		MessageBox(str1 + "," + str2 + "," + str3);

		sudoku.myGame[x][y] = value;

		//CPaintDC dc(this); // device context for painting
		//dc.SetBkMode(TRANSPARENT);
		//for (int i = 0; i < 9; i++) {
		//	for (int j = 0; j < 9; j++) {
		//		if (sudoku.myGame[i][j] != 0) {
		//			CString str(char('0' + sudoku.myGame[i][j]));
		//			dc.TextOutW(50 + 5 + i * 50, 50 + 5 + j * 50, str);
		//		}
		//	}
		//}
	}

	CDialogEx::OnLButtonDown(nFlags, point);

}
