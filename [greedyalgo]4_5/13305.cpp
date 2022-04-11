//
// Created by 김지윤 on 2022/04/11.
//
#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

// 1.현재 주유소 가격 > 다음 주유소 가격 -> 다음 도로갈때 드는 기름만 삼
// 2.현재 주요소 가격 < 다음 주요소 가격 -> 그다음 주요소 가격들 비교
// 다음 도로 건널때까지 드는 기름까지 삼 계속 반복
long long solve(vector<ll> &length, vector<ll> &price) {
    int cur = 0;//현재 도시 인덱스
    int next = 1;//다음 도시 인덱스
    ll cost = 0; //총 비용

    while(cur<price.size()-1) {
        //1번
        cost += length[cur] * price[cur];
        //2번
        while(price[cur] < price[next] && next < price.size() - 1) {
            cost += length[next] * price[cur];
            next++; //다음 주유소들 계속 비교위해 ++해줌
        }
        cur = next; //현재 도시는 next(이동한만큼)이 된다
        next++;
    }
    return cost;
}

int main() {
    int n;
    vector<ll> length; //도로 길이
    vector<ll> price; //주유소 가격
    length.assign(n-1,0);
    price.assign(n,0);

    //입력
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        cin >> length[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> price[i];
    }
    //연산&출력
    cout << solve(length, price) << '\n';

    return 0;
}