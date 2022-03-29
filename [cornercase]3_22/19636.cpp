//
// Created by 김지윤 on 2022/03/27.
//
#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

int main() {
    int w, i, t, d, i_daily, a;
    cin >> w >> i >> t >> d >> i_daily >> a;
    int before_i = i; //다이어트 전 기초 대사량

    //일일 기초 대사량 변화 고려 X
    int w_x = w + (i_daily - (i + a)) * d;
    if (w_x <= 0)
        cout << "Danger Diet" << '\n';
    else
        cout << w_x << " " << i << '\n';

    //일일 기초 대사량 변화 고려 O
    while (d--) {
        w += (i_daily - (i + a));
        if (abs(i_daily - (i + a)) > t)
            i += (int)floor((i_daily - (i + a)) / 2.0) ;

        if (w <= 0 || i <= 0) {
            cout << "Danger Diet" << '\n';
            return 0;
        }
    }
    cout << w << " " << i << " ";

    if (before_i > i)
        cout << "YOYO" << '\n';
    else
        cout << "NO" << '\n';

    return 0;
}
