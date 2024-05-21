#include<iostream>
#include<vector>
#include<set>
using namespace std;
void sudoku(vector<vector<int>>& val, int i, int j, bool& flag) {
    //判断是否遍历成功
    if (i >= 9 || j >= 9) {
        flag = 1;//遍历成功，置为一
        return;
    }

    set<int> s;
    if (val[i][j] == 0)  {
        for (int k = 0; k < 9; k++) {
            s.insert(val[i][k]);    //行
            s.insert(val[k][j]);    //列
        }
        int r = i / 3, l = j / 3;   //方块
        for (int h = r * 3; h < r * 3 + 3; h++) {
            for (int k = l * 3; k < l * 3 + 3; k++) {
                s.insert(val[h][k]);
            }
        }

        for (int k = 1; k < 10; k++) {  //从一到九表
            if (!flag && s.find(k) == s.end()) {    //flag == 0 且 没有找到相同的
                val[i][j] = k;
                if (j < 8)
                    sudoku(val, i, j + 1, flag);
                else
                    sudoku(val, i + 1, 0, flag);
            }
        }

        if (flag == 0) {       //遍历不成功
            val[i][j] = 0;
            return;
        }
    }
    else {
        if (j < 8)
            sudoku(val, i, j + 1, flag);
        else
            sudoku(val, i + 1, 0, flag);
    }
}
int main() {
    vector<vector<int>> val(9, vector<int>(9));
    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++)
            cin >> val[i][j];
    bool flag = false;
    sudoku(val, 0, 0, flag);
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 8; j++)
            cout << val[i][j] << " ";
        cout << val[i][8] << endl;
    }
    return 0;
}
