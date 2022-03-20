//
// Created by 김지윤 on 2022/03/20.
//
#include <iostream>
#include <vector>

using namespace std;
const int MAX = 1e5;

vector<int> prime(MAX + 1, 0);

void findPrime() {
    prime[0] = prime[1] = -1;
    for (int i = 2; i * i <= MAX; i++) {
        if (prime[i] == -1) {
            continue;
        }
        for (int j = i * i; j <= MAX; j += i) {
            if (prime[i] == -1) {
                continue;
            }
            prime[j] = -1;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    bool flag;
    findPrime();

    while (n != 0) {
        cin >> n;
        flag = false;
        for (int i = n; i >= (n / 2); i--) {
            if (prime[i] == 0 && prime[n - i] == 0 && prime[n - i] == 2) {
                cout << n << " = " << n - i << " + " << i << '\n';
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