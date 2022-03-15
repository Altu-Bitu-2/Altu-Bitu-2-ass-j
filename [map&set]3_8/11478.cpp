//
// Created by 김지윤 on 2022/03/13.
//
#include <iostream>
#include <set>

using namespace std;

int main(){
    string str;
    //문자열 입력
    cin>>str;
    set<string> s;

    //부분문자열 구하기
    for(int i=0;i<str.length();i++){
        for(int j=1;j<str.length()+1-i;j++){
            s.insert(str.substr(i,j));
        }
    }
    //출력
    cout<<s.size()<<'\n';
    return 0;
}

