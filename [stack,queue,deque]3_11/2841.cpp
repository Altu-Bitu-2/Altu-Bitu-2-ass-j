//
// Created by 김지윤 on 2022/03/17.
//
#include <iostream>
#include <stack>

using namespace std;

int main() {
    int n, p, line, fret, cnt = 0;
    cin >> n >> p;

    stack<int> st[7];

    while (n--) {
        cin >> line >> fret;

        if (st[line].empty()) {// 해당 line의 스택이 비어있으면 fret 추가
            st[line].push(fret);
            cnt++;
        } else {//줄이 비어있지 않고
            if (st[line].top() < fret) {//입력 받은 fret이 원래 있던 fret보다 높으면 추가
                st[line].push(fret);
                cnt++;
            } else if (st[line].top() == fret) {//입력받은 fret==원래 있던 fret이면, 다음 line,fret 입력받음
                continue;
            } else {//입력받은 fret이 원래 있던 fret보다 낮으면 입력fret이 스택의 top과 같거나 높을 때까지 pop
                while (!st[line].empty()) {
                    if (st[line].top() > fret) {
                        st[line].pop();
                        cnt++;
                    } else {
                        break;
                    }
                }
                if (!st[line].empty() && st[line].top() == fret) continue; //스택의 탑이 프렛과 같아지면 다음으로 넘어감
                st[line].push(fret);
                cnt++;
            }
        }

    }
    //출력
    cout<<cnt<<'\n';

    return 0;
}
