//
// Created by 김지윤 on 2022/03/30.
//
#include <iostream>
#include <vector>

using namespace std;
const int SIZE = 1e9;

vector<bool> check;
vector<vector<int>> w;
int n;
int res = SIZE;

void backtracking(int cnt, int start, int last, int cost) {
    //기저 조건
    if (cnt == n) { //모든 도시를 거침
        //처음 도시로 다시 돌아올 수 있는가
        if (w[last][start] != 0)
            res = min(res, cost + w[last][start]);
        return;
    }

    for (int i = 0; i < n; i++) {
        if (!check[i] && w[last][i]) { //아직 안 간 도시가 있고 현재 도시에서 그 도시로 가는 길이 있을 경우
            check[i] = true; //그 도시 방문
            backtracking(cnt + 1, start, i, cost + w[last][i]);
            check[i] = false; //원 상태로 복구
        }
    }
}

int main() {
    //입력
    cin >> n;
    check.assign(n, false);
    w.assign(n, vector<int>(n,0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> w[i][j];
        }
    }

    //연산
    for (int i = 0; i < n; i++) { //아무 도시에서나 출발 가능
        check[i] = true;
        backtracking(1, i, i, 0);
        check[i] = false;
    }

    //출력
    cout << res;
    return 0;
}
