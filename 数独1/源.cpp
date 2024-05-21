#include<iostream>
#include<vector>
#include<set>
using namespace std;
void sudoku(vector<vector<int>>& val, int i, int j, bool& flag) {
    //�ж��Ƿ�����ɹ�
    if (i >= 9 || j >= 9) {
        flag = 1;//�����ɹ�����Ϊһ
        return;
    }

    set<int> s;
    if (val[i][j] == 0)  {
        for (int k = 0; k < 9; k++) {
            s.insert(val[i][k]);    //��
            s.insert(val[k][j]);    //��
        }
        int r = i / 3, l = j / 3;   //����
        for (int h = r * 3; h < r * 3 + 3; h++) {
            for (int k = l * 3; k < l * 3 + 3; k++) {
                s.insert(val[h][k]);
            }
        }

        for (int k = 1; k < 10; k++) {  //��һ���ű�
            if (!flag && s.find(k) == s.end()) {    //flag == 0 �� û���ҵ���ͬ��
                val[i][j] = k;
                if (j < 8)
                    sudoku(val, i, j + 1, flag);
                else
                    sudoku(val, i + 1, 0, flag);
            }
        }

        if (flag == 0) {       //�������ɹ�
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
