//
// Created by 김지윤 on 2022/04/06.
//
#include <iostream>
#include <set>

using namespace std;

int main() {
    // 입출력 속도 향상
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    //입력
    cin >> t;

    while (t--) {
        multiset<int> ms; //중복값 저장 가능
        int k;
        cin >> k;
        while (k--) {
            char c;
            int n;

            cin >> c >> n;
            //연산
            switch (c) {
                case 'I': //삽입
                    ms.insert(n);
                    break;
                case 'D': //삭제
                    if(ms.empty())
                        break;
                    if(n==1){//최댓값 삭제
                        ms.erase(--ms.end()); //--ms.end(): 최댓값
                    }
                    if(n==-1){//최솟값 삭제
                        ms.erase(ms.begin());//ms.begin(): 최솟값
                         }
                    break;
            }
        }
        //출력
        if (ms.empty()) {
            cout << "EMPTY" << '\n';
        } else {
            cout << *--ms.end() << ' ' << *ms.begin() << '\n';
        }
    }
    return 0;
}
