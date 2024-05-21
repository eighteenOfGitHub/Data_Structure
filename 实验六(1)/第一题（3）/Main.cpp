#include<iostream>
#include<string>
#include"Stack.h"
using namespace std;

int n;
int map[10][10];
int passed[10][10];
Stack path;
Stack bestPath;

class XY {
public:
    int x;
    int y;

    XY() {}
    XY(int x, int y);
    bool isAccess();
    void setPassed();
    bool isEnd();
    bool equals(XY xy);
};

void dfs(XY& xy) {
    xy.setPassed();
	Node* node = new Node(xy.x,xy.y);
	node->next = NULL;
    path.push(node);
    if (xy.isEnd()) {   //判断是否结束
        if (bestPath.empty() || bestPath.size() >= path.size()) {
            bestPath.removeAll();
            bestPath.addAll(path);
        }
        path.pop();
        passed[xy.x][xy.y] = 0;
        return;
    }

    //down
    XY down(xy.x + 1, xy.y);
    if (down.isAccess()) {
        dfs(down);
    }
    //right
    XY right(xy.x, xy.y + 1);
    if (right.isAccess()) {
        dfs(right);
    }
    //left
    XY left(xy.x, xy.y - 1);
    if (left.isAccess()) {
        dfs(left);
    }
    //up
    XY up(xy.x - 1, xy.y);
    if (up.isAccess()) {
        dfs(up);
    }
    path.pop();
    passed[xy.x][xy.y] = 0;
}

int main(){

    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> map[i][j];
        }
    }
    XY start(1, 1);
    XY end(n - 2, n - 2);
    if (!start.isAccess() || !end.isAccess()) {
        cout << "No" << endl;
    }
    dfs(start);
    if (bestPath.empty()) {
        cout << "No" << endl;
    }
    else {
        while (!bestPath.empty()) {
            Node* node;
            bestPath.get_top(node);
            cout << "(" << node->x << "," << node->y << ")"<<' ';
            bestPath.pop();
        }
    }
        return 0;   
}

//--------------------XY类实现------------------
XY::XY(int x, int y) {
    this->x = x;
    this->y = y;
}

bool XY::isAccess() {
    Node* node = new Node(x, y);
    if (x < 1 || x > n - 2 || y < 1 || y > n - 2 || map[x][y] == 1 || path.contains(node) || passed[x][y] == 1) {
        return false;
    }
    return true;
}

void XY::setPassed() {
    passed[x][y] = 1;
}

bool XY::isEnd() {
    return x == n - 2 && x == y;
}

bool XY::equals(XY xy) {
    return this->x == xy.x && this->y == xy.y;
}

/*
4
1 1 1 1
1 0 1 1
1 0 0 1
1 1 1 1



10
1 1 1 1 1 1 1 1 1 1
1 0 0 1 0 0 0 1 0 1
1 0 0 1 0 0 0 1 0 1
1 0 0 0 0 1 1 0 0 1
1 0 1 1 1 0 0 0 0 1
1 0 0 0 1 0 0 0 0 1
1 0 1 0 0 0 1 0 0 1
1 0 1 1 1 0 1 1 0 1
1 1 0 0 0 0 0 0 0 1
1 1 1 1 1 1 1 1 1 1

*/