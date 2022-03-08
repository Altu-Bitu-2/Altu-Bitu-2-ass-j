//
// Created by 김지윤 on 2022/03/08.
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//문자열에서 숫자 추출 후 합 구하는 함수
int sum_integer(string str){
    int sum=0;
    for(int i=0; str[i]!=0;i++){
        if(str[i]>=48 &&str[i]<57){ //아스키 코드 값 확인
           sum+=(str[i]-48);//숫자 취급위해 아스키 코드값 48 빼주기
        }
    }
    return sum;
}

bool cmp(string a,string b){
    if(a.size()<b.size()){
        return a<b;
    }
    if(sum_integer(a)< sum_integer(b)){
        return a<b;
    }
    return a<b;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    //입력
    cin >> n;
    vector<string> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    //연산
    sort(v.begin(),v.end(),cmp);
    //출력
    for(int i=0;i<n;i++){
        cout<<v[i]<<'\n';
    }

    return 0;
}
