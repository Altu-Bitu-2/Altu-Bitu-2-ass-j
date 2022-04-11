//
// Created by 김지윤 on 2022/04/11.
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    //입력
    cin >> n;
    vector<int> weight;
    for(int i=0;i<n;i++) {
        int num;
        cin >> num;
        weight.push_back(num);
    }
    sort(weight.begin(), weight.end());
    //연산
    int sum=1;
    for(int i=0;i<n;i++){
        if(sum<weight[i])
            break;
        sum +=weight[i];
    }
    //출력
    cout<<sum<<'\n';

    return 0;
}