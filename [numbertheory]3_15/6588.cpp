//
// Created by 김지윤 on 2022/03/20.
//
#include <iostream>
#include <vector>

using namespace std;
const int MAX = 1e6;
vector<bool> isprime(MAX + 1, true);

void findPrime() {
    isprime[0] = isprime[1] = false; //0과1은 소수가 아니므로 false
    for (int i = 2; i * i <= MAX; i++) {
        if (!isprime[i]) { //i가 소수가 아니라면
            continue;
        }
        //i가 소수라면, i의 배수를 순서대로 방문하기
        for (int j = i * i; j <= MAX; j += i) {
            //이미 표기된 수라면 넘어가기
            if (!isprime[j])
                continue;
            isprime[j] = false;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;

    findPrime();

    while (true) {
        cin >> n;
        if (n == 0) break; //0이면 종료
        bool flag = false;
        //연산
        for (int i = 3; i <= (n / 2); i++) {
            if (isprime[i] == true && isprime[n - i] == true) {
                cout << n << " = " << i << " + " << n - i << '\n';
                flag = true;
                break;
            }
        }
        if (!flag) {
            cout << "Goldbach's conjecture is wrong." << '\n';
        }
    }
    return 0;
}