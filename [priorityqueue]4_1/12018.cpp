//
// Created by 김지윤 on 2022/04/04.
//
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
    // 입출력 속도 향상
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m, cnt = 0;
    //최대 힙
    priority_queue<int, vector<int>, greater<>> pq;
    //입력
    cin >> n >> m;
    while (n--) {
        int p, l;
        cin >> p >> l;
        vector<int> v(p);
        for (int i = 0; i < p; i++) //다른 사람들이 투자한 마일리지 입력받음
            cin >> v[i];
        sort(v.begin(), v.end(), greater<>());//내림차순으로 정렬
        //신청인원보다 수강인원이 작으면 가장 작은 마일리지 투자
        if (p < l) {
            pq.push(1);
            continue;
        }
        //수강인원안에 들기 위해서는 (수강인원)번째 사람과 같은 마일리지를 넣어야함
        pq.push(v[l - 1]);

    }

    while (!pq.empty()) {
        m -= pq.top();
        pq.pop();
        if(m>=0)
            cnt++;
    }

    //출력
    cout<<cnt<<'\n';

    return 0;
}
