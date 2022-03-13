//
// Created by 김지윤 on 2022/03/14.
//
#include <iostream>
#include <map>

using namespace std;

int main() {
    //입력
    int c, n;//테스트 케이스, 의상의 수
    string name, type;
    cin >> c;
    map<string, int> m;

    while (c--) {
        cin >> n;
        while (n--) {
            cin >> name >> type;
            m[type]++;
        }
        int res = 1;
        for (auto iter = m.begin(); iter != m.end(); iter++) {
            res *= (iter->second + 1);
        }
        res -= 1;//알몸인 경우
        cout << res << '\n';
        m.clear();
    }
    return 0;
}

