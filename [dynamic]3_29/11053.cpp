//
// Created by 김지윤 on 2022/04/03.
//
#include <iostream>
#include <vector>

using namespace std;
const int MAX = 1001;

int main() {
    int n,ans=0;
    int arr[MAX];
    int dp[MAX]; //d[i]: 수열의 i항까지 가장 긴 증가하는 부분 수열의 길이
    // 입력
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    //연산
    for (int i = 0; i < n; i++) {
        dp[i] = 1;
        for (int j = 0; j < i; j++) {
            if (arr[i] > arr[j]){
                dp[i]=max(dp[i],dp[j]+1);
            }
        }
        ans=max(ans,dp[i]);
    }
    //출
    cout<<ans<<'\n';

    return 0;
}
