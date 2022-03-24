//
// Created by 김지윤 on 2022/03/24.
//
#include <iostream>

using namespace std;

int main() {
    int r, b, l, w;
    cin >> r >> b;
    int i = 2;

    while (++i) {
        if (((r + b) % i == 0) && (b % (i - 2) == 0)) {
            l = i;
            w = (r + b) / i;
            if((l-2)*(w-2)==b)
                break;
        }
    }
    if(l<w)
        swap(l,w);

    cout<<l<<" "<<w<<'\n';
    return 0;

}
