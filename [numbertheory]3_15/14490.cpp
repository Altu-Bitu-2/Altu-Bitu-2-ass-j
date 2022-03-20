//
// Created by 김지윤 on 2022/03/20.
//
#include <iostream>
#include <string>

using namespace std;

//최대공약수 구하는 함수
int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string s;
    int n, m;
    cin >> s;
    int l;

    for (int i = 0; i < s.length(); i++) {
        if (s[i] == ':')
            l = i;
    }
    n = stoi(s.substr(0, l));
    m = stoi(s.substr(l + 1, s.length() - l - 1));

    cout << n / gcd(max(n, m), min(n, m)) << ':' << m / gcd(max(n, m), min(n, m)) << '\n';


}