//
// Created by 김지윤 on 2022/04/03.
//
#include <iostream>

using namespace std;

int dp[1001][11]; //dp[i][j]: 길이가 i이면서 j로 시작하는 수의 개수 저장
const int MOD = 10007;

int main() {
    //입력
    int n, ans = 0;
    cin >> n;

    //연산
    for (int i = 0; i < 10; i++) {
        dp[1][i] = 1;// 길이가 1이고 i로 시작하는 오르막수는 1개
    }

    for (int i = 2; i <= n; i++) {
        for (int j = 0; j <= 9; j++) {
            dp[i][j] = (dp[i][j - 1] + dp[i - 1][j]) % MOD;
        }
    }

    for (int i = 0; i <= 9; i++) {
        ans += dp[n][i];
    }
    ans %= MOD;

    //출력
    cout << ans << '\n';

    return 0;
}