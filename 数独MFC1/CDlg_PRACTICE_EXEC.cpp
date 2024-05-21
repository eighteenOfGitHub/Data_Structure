// CDlg_PRACTICE_EXEC.cpp: 实现文件
//

#include "pch.h"
#include "数独MFC1.h"
#include "afxdialogex.h"
#include "CDlg_PRACTICE_EXEC.h"
#include "Sudoku.h"
using namespace std;

// CDlg_PRACTICE_EXEC 对话框

IMPLEMENT_DYNAMIC(CDlg_PRACTICE_EXEC, CDialogEx)

CDlg_PRACTICE_EXEC::CDlg_PRACTICE_EXEC(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_2EXEC, pParent)
{
	//得到游戏
	sudoku.getGame();
	//设置游戏当前状态，挖空
	int option = 2;
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			sudoku.curGame[i][j] = sudoku.myGame[i][j];
		}
	}
	int brank = 0;//挖去的空白格子数
	if (option == 0) {
	}
	else if (option == 1) {
		brank = 25;//25
	}
	else if (option == 2) {
		brank = 40;//40
	}
	else {
		brank = 55;//55
	}

	for (int i = 1; i <= brank; i++) {
		int x = rand() % 9;
		int y = rand() % 9;
		while (sudoku.curGame[x][y] == 0) {
			x = rand() % 9;
			y = rand() % 9;
		}
		sudoku.curGame[x][y] = 0;
	}
}

CDlg_PRACTICE_EXEC::~CDlg_PRACTICE_EXEC()
{
}

void CDlg_PRACTICE_EXEC::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO1, m_combo);
}


BEGIN_MESSAGE_MAP(CDlg_PRACTICE_EXEC, CDialogEx)
	ON_WM_PAINT()
	ON_BN_CLICKED(IDC_BUTTON4, &CDlg_PRACTICE_EXEC::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON3, &CDlg_PRACTICE_EXEC::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON2, &CDlg_PRACTICE_EXEC::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON1, &CDlg_PRACTICE_EXEC::OnBnClickedButton1)
END_MESSAGE_MAP()


// CDlg_PRACTICE_EXEC 消息处理程序


void CDlg_PRACTICE_EXEC::OnPaint()
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
			if (sudoku.curGame[i][j] != 0) {
				CString str(char('0' + sudoku.curGame[i][j]));
				dc.TextOutW(Ox + 20 + i * 50, Oy + 15 + j * 50, str);
			}
		}
	}

	ReleaseDC(pdc);
	ReleaseDC(pdc1);
}


BOOL CDlg_PRACTICE_EXEC::OnInitDialog()
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

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}


void CDlg_PRACTICE_EXEC::OnBnClickedButton4()	//提示	
{
	// TODO: 在此添加控件通知处理程序代码
	srand((unsigned)time(NULL));
	int n = rand() % 81;
	while (sudoku.curGame[n / 9][n % 9] != 0) {
		n = rand() % 81;
	}

	CString str1(char(n / 9 + 1 + '0'));
	CString str2(char(n % 9 + 1 + '0'));
	CString str3(char(sudoku.myGame[n / 9][n % 9] + '0'));
	MessageBox(str1 + " 行, " + str2 + " 列, 数字为 " + str3);
}


void CDlg_PRACTICE_EXEC::OnBnClickedButton3()	//检查
{
	// TODO: 在此添加控件通知处理程序代码
	bool haveWrong = 0;
	bool iscomplete = 1;
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (sudoku.curGame[i][j] != 0) {
				if (sudoku.curGame[i][j] != sudoku.myGame[i][j]) {
					CString str1(char(i + 1 + '0'));
					CString str2(char(j + 1 + '0'));
					MessageBox(str1 + " 行, " + str2 + " 列, 数字错误");
					haveWrong = 1;
				}
			}
			else {
				haveWrong = 1;
				iscomplete = 0;
			}
		}
	}
	if (iscomplete && !haveWrong) {
		end_time = clock();
		int time = (end_time - start_time);
		if (option == 2 && time < 600) {
			MessageBox(TEXT("恭喜你！挑战成功！你的成绩为 A "));
		}
		else if ((option == 2 && time >= 600 && time < 1800) || (option == 1 && time < 600)) {
			MessageBox(TEXT("恭喜你！挑战成功！你的成绩为 B "));
		}
		else if ((option == 2 && time >= 1800 && time < 3600) || (option == 1 && time >= 600 && time < 1800)) {
			MessageBox(TEXT("恭喜你！挑战成功！你的成绩为 C "));
		}
		else if ((option == 2 && time >= 3600) || (option == 1 && time >= 1800 && time < 3600)) {
			MessageBox(TEXT("恭喜你！挑战成功！你的成绩为 D "));
		}
		else {//(option == 1 && time >= 3600)
			MessageBox(TEXT("恭喜你！挑战成功！你的成绩为 E "));
		}
		return;
	}
	else if (!iscomplete && !haveWrong) {
		MessageBox(TEXT("不错哟！暂时没有错误！"));
	}
}

void CDlg_PRACTICE_EXEC::OnBnClickedButton2()	//撤销
{
	// TODO: 在此添加控件通知处理程序代码
	if (sudoku.myremove.empty()) {
		MessageBox(TEXT("撤销失败！请先填入数字！"));
	}
	else {
		MyRemove remove;
		sudoku.myremove.get_top(remove);
		sudoku.curGame[remove.x][remove.y] = 0;
		sudoku.myremove.pop();
		MessageBox(TEXT("撤销成功！"));
		OnPaint();
	}
}


void CDlg_PRACTICE_EXEC::OnBnClickedButton1()	//查看答案
{
	// TODO: 在此添加控件通知处理程序代码
	CPaintDC dc(this);
	dc.SetBkMode(TRANSPARENT);
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (sudoku.curGame[i][j] != 0) {
				CString str(char('0' + sudoku.myGame[i][j]));
				dc.TextOutW(50 + 20 + i * 50, 50 + 15 + j * 50, str);
			}
		}
	}
}
