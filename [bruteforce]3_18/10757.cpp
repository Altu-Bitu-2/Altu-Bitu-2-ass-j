//
// Created by 김지윤 on 2022/03/23.
//
#include <iostream>
#include <algorithm>

using namespace std;

string plusString(string a, string b) {
    int sum = 0;
    string res;

    if (a.size() < b.size()) {//a의 길이가 더 길게
        swap(a, b);
    }

    for (int i = a.size() - 1; i >= 0; i--) {
        if ((i - a.size() + b.size()) >= 0)
            sum += ((a[i] - '0') + (b[i - a.size() + b.size()] - '0'));
        else //b index가 음수일 때
            sum += (a[i] - '0');

        res.push_back(sum % 10 + '0'); //sum의 1의자리 수만 pushback
        cout << res << '\n';
        sum /= 10;//sum의 십의 자리 수는 다음 덧셈에 합쳐서 더함
    }
    if (sum > 0)
        res.push_back(sum + '0');

    reverse(res.begin(), res.end());
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string a, b;
    cin >> a >> b;
    cout << plusString(a, b);
    return 0;
}