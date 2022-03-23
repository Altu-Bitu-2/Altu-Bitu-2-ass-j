//
// Created by 김지윤 on 2022/03/20.
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int sum = 0;
bool flag = true;
vector<int> v;

bool cmp(char a, char b) {
    return a > b;
}

int checkThirty(string n){
    for (int i = 0; i < n.length(); i++) {
        if (n[i] - '0' == 0) {
            flag = false;
        }
        sum += (n[i] - '0');
        v.push_back(n[i] - '0');
    }

    if (!flag && sum % 3 == 0) {
        sort(v.begin(), v.end(), cmp);
        for (int i = 0; i < v.size(); i++) {
            cout << v[i];
        }
    } else cout << -1 << '\n';
}

int main() {
    string n;
    cin >> n;

    checkThirty(n);
    return 0;
}


