//
// Created by 김지윤 on 2022/03/30.
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int SIZE = 8;
int n, m;
int arr[10];
vector<int> num(SIZE);
vector<int> check(SIZE);

void backtracking(int cnt) { //cnt:수열 인덱스
    //기저 조건: m개의 수열 만든 경우
    if (cnt == m) {
        for (int i = 0; i < cnt; i++) {
            cout << num[i] << ' ';
        }
        cout << '\n';
        return;
    }

    int pre_num = 0; //이전에 사용한 값

    for (int i = 0; i < n; i++) { //i: 고르려는 수
        if (!check[i] && pre_num != arr[i]) { //현재 수열에 해당 수가 없고 이전에 쓴 수가 현재 값과 다르다면-> 사용 가능
            num[cnt] = arr[i]; //사용
            pre_num = arr[i]; //현재 사용한 수 기억
            check[i] = true;
            backtracking(cnt + 1); //다음 인덱스 수 호출
            check[i] = false; //원래 상태로 돌려놓음
        }
    }
}

int main() {
    //입력
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    //연산
    sort(arr, arr + n); //오름차순으로 정렬

    //연산+출력
    backtracking(0);

    return 0;
}