//
// Created by 김지윤 on 2022/03/30.
//
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, s, p, rank = 1;
    //입력
    cin >> n >> s >> p;
    vector<int> score(n);
    for(int i=0;i<n;i++)
        cin>>score[i];

    if(n==p && score[n-1]>=s)//리스트가 full일때 가장 낮은 점수와 같거나 작으면 -1
        rank=-1;
    else{
        for(int i=0;i<n;i++)
            if(score[i]>s)
                rank++;
        }
    //출력
    cout<<rank;
    return 0;
}
