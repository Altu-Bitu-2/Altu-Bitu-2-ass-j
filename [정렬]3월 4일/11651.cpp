//
// Created by 김지윤 on 2022/03/08.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(const pair<int, int> &a, const pair<int, int> &b) {
    if (a.second == b.second) {
        return a.first < b.first;
    }
    return a.second < b.second;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    //입력
    cin >> n;

    vector<pair<int, int>> v(n);

    for (int i = 0; i < n; i++) {
        cin >> v[i].first >> v[i].second;
    }
    //연산
    sort(v.begin(), v.end(), cmp);

    //출력
    for (int i = 0; i < n; i++) {
        cout << v[i].first <<" "<< v[i].second << '\n';
    }
    return 0;
}
