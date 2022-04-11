//
// Created by 김지윤 on 2022/04/11.
//
#include <iostream>

using namespace std;

int a[51][51]; //바꾸기 전 행렬
int b[51][51]; //바꾼 후 행렬

//3*3 행렬의 원소를 바꾸는 함수
void rev(int x, int y) {
    for (int i = x - 1; i < x + 2; i++) {
        for (int j = y - 1; j < y + 2; j++) {
            a[i][j] = 1 - a[i][j];
        }
    }
}

int main() {
    int n, m;
    int cnt = 0;// 바꾼 횟수

    cin >> n >> m;

    //행렬 입력 받기
    for (int i = 0; i < n; i++) {
        string str;
        cin >> str;
        for (int j = 0; j < m; j++) {
            a[i][j] = str[j] - '0';
        }
    }

    for (int i = 0; i < n; i++) {
        string str;
        cin >> str;
        for (int j = 0; j < m; j++) {
            b[i][j] = str[j] - '0';
        }
    }

    //행렬 뒤집기
    for (int i = 0; i < n - 2; i++) {
        for (int j = 0; j < m - 2; j++) {
            if (a[i][j] != b[i][j]) {
                cnt++;
                rev(i + 1, j + 1);
            }
        }
    }

    //뒤집은 a행렬이 b행렬과 같은지 확인
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] != b[i][j]) {
                cout << -1 << '\n';//a를 b로 바꿀 수 없다면
                return 0;
            }
        }
    }
    cout << cnt << '\n';
    return 0;
}