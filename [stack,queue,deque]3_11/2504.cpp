//
// Created by 김지윤 on 2022/03/17.
//
#include <iostream>
#include <stack>

using namespace std;

int main() {
    string s;
    cin >> s;
    int tmp = 1, res = 0;
    stack<char> st;

    for (int i = 0; i < s.length(); i++) {
        //( 이면 스택에 저장, *2
        if (s[i] == '(') {
            st.push(s[i]);
            tmp *= 2;
        }//[ 이면 스택에 저장, *3
        else if (s[i] == '[') {
            st.push(s[i]);
            tmp *= 3;
        }//) 이면
        else if (s[i] == ')') {
            if (st.empty() || st.top() != '(') { //스택이 비었거나, 종류 안맞음
                cout << 0 << '\n';
                return 0;
            }
            //() 쌍이 맞으면 tmp 더하기
            if (s[i - 1] == '(')
                res += tmp;
            //스택에서 제거하고 /2
            st.pop();
            tmp /= 2;
        }
            //] 이면
        else if (s[i] == ']') {
            if (st.empty() || st.top() != '[') { //스택이 비었거나, 종류 안맞음
                cout << 0 << '\n';
                return 0;
            }
            //() 쌍이 맞으면 tmp 더하기
            if (s[i - 1] == '[')
                res += tmp;
            //스택에서 제거하고 /3
            st.pop();
            tmp /= 3;
        }
    }

    //스택이 비어있지 않으면 쌍이 안 맞음
    if (!st.empty()) {
        res = 0;
    }
    cout << res << '\n';
    return 0;
}
