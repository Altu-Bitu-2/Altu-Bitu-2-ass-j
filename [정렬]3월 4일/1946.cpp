//
// Created by 김지윤 on 2022/03/08.
//

#include <iostream>
#include <algorithm>

using namespace std;

pair<int, int> arr[100000];//서류심사 성적, 면접 성적

int main() {
    int T, N;
    cin >> T;

    while (T--) {
        cin >> N;
        for (int i = 0; i < N; i++) {
            cin >> arr[i].first >> arr[i].second;
        }
        sort(arr, arr + N);

        int picked = 1;//정렬된 첫번째 지원자는 무조건 선발됨
        int temp = arr[0].second;
        for (int i = 1; i < N; i++) {
            if (temp > arr[i].second) {
                picked++;
                temp = arr[i].second;
            }
        }
        cout << picked << '\n';
    }
    return 0;
}

