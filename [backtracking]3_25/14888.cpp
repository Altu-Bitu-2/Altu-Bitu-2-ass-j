//
// Created by 김지윤 on 2022/03/30.
//
#include <iostream>

using namespace std;
const int MAX = 1e9 + 1;
int n;
int maxN = -MAX; //최대
int minN = MAX; //최소
int num[12];
int op[4];

void backtracking(int cnt, int res) {
    //기저 조건
    if (cnt == n) {
        if (res > maxN) //res가 최댓값보다 크면 최댓값 갱신
            maxN = res;
        if (res < minN) //res가 최솟값보다 작으면 최솟값 갱신
            minN = res;
        return;
    }

    for (int i = 0; i < 4; i++) { //i:고르려는 연산자
        if (op[i] > 0) { //연산기호가 있다면
            op[i]--; //사용
            if (i == 0) {
                backtracking(cnt + 1, res + num[cnt]); //다음 인덱스 호출
            } else if (i == 1) {
                backtracking(cnt + 1, res - num[cnt]);
            } else if (i == 2) {
                backtracking(cnt + 1, res * num[cnt]);
            } else
                backtracking(cnt + 1, res / num[cnt]);
            op[i]++; //원래 상태로 돌려놓음
        }
    }
}

int main() {
    //입력
    cin >> n;
    //숫자 입력
    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }
    //연산자 입력
    for (int i = 0; i < 4; i++) {
        cin >> op[i];
    }

    //연산
    backtracking(1, num[0]);
    //출력
    cout << maxN << '\n' << minN << '\n';

    return 0;
}