//
// Created by 김지윤 on 2022/03/24.
//
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, sum = 0, max = 0;
    cin >> n >> m;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                sum = arr[i] + arr[j] + arr[k];
                if (sum <= m && sum > max)
                    max = sum;
            }
        }
    }

    cout << max << '\n';
    //시간초과,,
/*
    do {
        for (int i = 0; i < 3; i++)
            sum += arr[i];
        if (sum <= m)
            res = min(m - sum, res);
    } while (next_permutation(arr, arr + n));

    cout << m - res << '\n';
    */

    return 0;
}