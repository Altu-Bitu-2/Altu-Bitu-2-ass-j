//
// Created by 김지윤 on 2022/04/06.
//
#include <iostream>
#include <stack>

using namespace std;

int main() {
    int t;
    stack<char> s1, s2;
    //입력
    cin >> t;

    while (t--) {
        string l;
        cin >> l;
        //연산
        for (int i = 0; i < l.length(); i++) {
            if ((l[i] >= 'a' && l[i] <= 'z') || (l[i] >= 'A' && l[i] <= 'Z') ||
                (l[i] >= '0' && l[i] <= '9'))//문자이거나 숫자이면
                s1.push(l[i]);
            else if (l[i] == '-' && !s1.empty())
                s1.pop();
            else if (l[i] == '<' && !s1.empty()) {
                s2.push(s1.top()); //앞서 입력된 문자열의 맨 마지막 문자를 s2에 저장
                s1.pop();//s2에 저장된 문자는 s1에서 삭제
            } else if (l[i] == '>' && !s2.empty()) {
                s1.push(s2.top());
                s2.pop();
            }
        }
        //s1+s2
        while (!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }
        //출력
        while (!s2.empty()) {
            cout << s2.top();
            s2.pop();
        }
        cout << '\n';
    }
    return 0;
}



