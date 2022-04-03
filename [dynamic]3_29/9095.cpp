//
// Created by 김지윤 on 2022/04/03.
//
#include <iostream>

using namespace std;

int main(){
    int t,n;
    int dp[12];
    //입력
    cin>>t;
    //dp[n]=dp[n-1]+dp[n-2]+dp[n-3]
    dp[0]=0;
    dp[1]=1;
    dp[2]=2;
    dp[3]=4;

    while(t--){
        cin>>n;
        for(int i=4;i<=n;i++){
            dp[i]=dp[i-1]+dp[i-2]+dp[i-3];
        }
        cout<<dp[n]<<'\n';
    }

    return 0;
}
