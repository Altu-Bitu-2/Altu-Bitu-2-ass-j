//
// Created by 김지윤 on 2022/03/16.
//
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int alp[27];

int main() {
    string s;
    cin >> s;

    for (int i = 0; i < s.size(); i++) {
        alp[s[i] - 'A']++;
    }
    //팰린드롬인지 아닌지 확인
    int odd = -1;

    for (int i = 0; i < 26; i++) {
        if (alp[i] % 2 == 1 && odd != -1) {  //3.개수가 홀수인 알파벳이 또 나오면, 이때는 odd값이 -1이 아닌 상태이므로
            cout << "I'm Sorry Hansoo" << '\n';//4.팰린드롬이 아니다.
            return 0;
        } else if (alp[i] % 2 == 1 && odd == -1)//1.개수가 홀수인 알파벳 처음으로 찾으면 odd값 변하지않음
            odd = i;//2.odd값 변함
    }
    //덱에 팰린드롬 저장
    deque<char> dq;
    if (odd != -1) { //홀수개 알파벳 하나 먼저 저장
        dq.push_back(odd + 'A');
        alp[odd]--;//alp[odd]는 짝수개가됨
    }
    for (int i = 25; i >= 0; i--) {
        while (alp[i] > 0) {
            dq.push_back(i + 'A');
            dq.push_front(i + 'A');
            alp[i] -= 2;
        }
    }
    for (int i = 0; i < dq.size(); i++) {
        cout << dq[i];
    }

    return 0;
}
