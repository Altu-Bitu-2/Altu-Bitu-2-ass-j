//
// Created by 김지윤 on 2022/03/13.
//
#include <iostream>
#include <map>


using namespace std;

int main() {
    //입력
    int n, num = 0;//파일 개수, 확장자 파일의 개수
    string file;
    cin >> n;
    map<string, int> m;
    for (int i = 0; i < n; i++) {
        cin >> file;
        file.erase(0,file.find('.')+1);
        m[file]++;
    }
    for(auto iter=m.begin();iter!=m.end();iter++){
        cout<<iter->first<<" "<<iter->second<<'\n';
    }
    return 0;
}
