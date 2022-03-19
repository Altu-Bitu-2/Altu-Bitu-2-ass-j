//
// Created by 김지윤 on 2022/03/16.
//
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, num, max = 0, min = 0;
    double sum = 0;
    cin >> n;
    vector<int> v;
    int mode[8001] = {0,};

    //입력
    for (int i = 0; i < n; i++) {
        cin >> num;
        v.push_back(num);

        sum += num;
    }

    //산술평균 출력
    cout << (int) round(sum / n) << '\n';

    //중앙값 출력
    sort(v.begin(), v.end());
    cout << v[n / 2] << '\n';

    //최빈값 출력
    //빈도수 계산
    for (int i = 0; i < n; i++) {
        mode[v[i] + 4000]++;
    }
    int m_max = 0;//최대 빈도수
    int val;
    for (int i = 0; i < 8001; i++) {
        if (m_max < mode[i]) {
            m_max = mode[i];
            val = i - 4000;
        }
    }
    int cnt = 0;
    for (int i = 0; i < 8001; i++) {
        if (m_max == mode[i]) {
            cnt++;
        }
        if (cnt == 2) {
            val = i - 4000;
            break;
        }

    }
    cout << val << '\n';

    //범위 출력
    cout << v[n - 1] - v[0] << '\n';

    return 0;
}