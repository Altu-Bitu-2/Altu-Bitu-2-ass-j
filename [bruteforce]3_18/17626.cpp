//
// Created by 김지윤 on 2022/03/24.
//
#include <iostream>

using namespace std;
int dp[500001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    dp[1] = 1;
    for (int i = 1; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[1];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j * j <= i; j++)
            dp[i] = min(dp[i], 1 + dp[i - j * j]);
    }
    cout << dp[n];

    return 0;
}