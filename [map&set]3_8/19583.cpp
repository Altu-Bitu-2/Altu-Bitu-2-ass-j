//
// Created by 김지윤 on 2022/03/10.
//

#include <iostream>
#include <set>

using namespace std;
/*
int changeTime(string &s) {
    return 60 * stoi(s.substr(0, 2)) + stoi(s.substr(3, 2));
}*/

int main() {
    string s, e, q, time, name;
    int cnt = 0;
    cin >> s >> e >> q;

    set<string> in;
    set<string> att;


    while (cin >> time >> name) {//입력이 없으면 종료
        if (time <= s) {
            in.insert(name);
        } else if (time >= e && time <= q) {
            if (in.find(name)!=in.end()) {
                att.insert(name);
            }
        }
    }
    cout << att.size() << '\n';
    return 0;
}