//
// Created by 김지윤 on 2022/03/10.
//

#include <iostream>
#include <set>

using namespace std;

int changeTime(string &s) {
    return 60 * stoi(s.substr(0, 2)) + stoi(s.substr(3, 2));
}

int main() {
    string s, e, q, time, name;
    int cnt = 0, start, end, quit, t;
    cin >> s >> e >> q;
    start = changeTime(s);
    end = changeTime(e);
    quit = changeTime(q);

    set<string> in;
    set<string> att;


    while (!cin.eof()) {//입력이 없으면 종료
        cin >> time >> name;
        t = changeTime(time);
        if (t <= start) {
            in.insert(name);
        } else if (t >= end && t <= quit) {
            if (in.find(name)!=in.end()) {
                att.insert(name);
            }
        }
    }
    cout << att.size() << '\n';
    return 0;
}