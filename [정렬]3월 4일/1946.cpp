//
// Created by 김지윤 on 2022/03/08.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


int main() {
    int t, n;
        cin >> t;

        while (t--) {
            cin >> n;
            vector<pair<int, int>> v(n);//서류심사 성적, 면접 성적
            for (int i = 0; i < n; i++) {
                cin >> arr[i].first >> arr[i].second;
            }
            sort(arr.begin(), arr.end());

            int picked = 1;//정렬된 첫번째 지원자는 무조건 선발됨
            int temp = arr[0].second;
            for (int i = 1; i < n; i++) {
                if (temp > arr[i].second) {
                    picked++;
                    temp = arr[i].second;
                }
            }
            cout << picked << '\n';
        }
        return 0;
}

