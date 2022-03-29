#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int t, a, b, res;
    cin >> t;
    while (t--) {
        cin >> a >> b;

        if (a % 10 == 0)
            res = 10;
        else if (b % 4 == 0)
            res = (int) pow(a % 10, 4) % 10;
        else
            res = (int) pow(a % 10, b % 4) % 10;
        cout << res << '\n';
    }
    return 0;
}
