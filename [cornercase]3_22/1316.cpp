//
// Created by 김지윤 on 2022/03/27.
//
#include <iostream>
#include <vector>

using namespace std;

bool checker(string s) {
    int check[26] = {0,};
    for (int i = 0; i < s.length(); i++) {
        if (i == 0)
            check[s[i] - 'a']++;
        else {
            if (s[i - 1] == s[i]) //같은 글자 연속이면 continue
                continue;
            if (check[s[i] - 'a'] == 1) //연속이 아닌데 나왔던 글자가 또 나오면 false
                return false;
            else check[s[i]-'a']++;
        }
    }
    return true;
}

int main() {
    int n, cnt = 0;
    string s;
    cin >> n;
    while (n--) {
        cin >> s;
        if (checker(s))
            cnt++;
    }

    cout<<cnt<<'\n';

    return 0;
}
