//
// Created by 김지윤 on 2022/03/17.
//
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    deque<int> dq;
    vector<int> v;
    //입력
    int n, a, tmp;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a;
        v.push_back(a);
    }
    int input = 1;

    for (int i = n - 1; i >= 0; i--) {
        if (v[i] == 1) //1.제일 위의 카드 1장을 바닥에 내려놓는다
            dq.push_front(input++);
        else if (v[i] == 2 && v.size() >= 2) { //2.위에서 두번째 카드를 내려놓는다. 카드가 2장 이상일 때만 쓸 수 있다
            tmp = dq.front();
            dq.pop_front();
            dq.push_front(input++);
            dq.push_front(tmp);
        } else dq.push_back(input++);//3.제일 밑에 있는 카드 내려놓음
    }
    while (!dq.empty()) {
        cout << dq.front() << ' ';
        dq.pop_front();
    }

    return 0;
}
