//
// Created by 김지윤 on 2022/04/05.
//
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
    // 입출력 속도 향상
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t, k, p, x;
    long long a, b, c;

    //입력
    cin >> t;
    while (t--) {
        cin >> k;
        priority_queue<long long, vector<long long>, greater<>> pq; //최소 힙
        while(k--) {
            cin >> x;
            pq.push(x);
        }
        long long res = 0;
        while (pq.size() > 1) {
            a = pq.top();
            pq.pop();
            b = pq.top();
            pq.pop();

            c = a + b;
            res += c;
            pq.push(c);
        }
        //출력
        cout << res << '\n';
    }

    return 0;
}