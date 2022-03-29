//
// Created by 김지윤 on 2022/03/27.
//
#include <iostream>
#include <deque>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, d, s, gdodo_front, gsu_front;;
    deque<int> dodo, su, gdodo, gsu;
    bool d_turn = true;
    //입력
    cin >> n >> m;

    while (n--) {
        cin >> d >> s;
        dodo.push_front(d);
        su.push_front(s);
    }
    //연산
    while (m--) {
        if (d_turn) { //도도부터 시작
            gdodo.push_front(dodo.front());
            dodo.pop_front();
            d_turn = false;
        } else {
            gsu.push_front(su.front());
            su.pop_front();
            d_turn = true;//도도-수연-다시 도도
        }

        if (dodo.empty() || su.empty()) //둘중하나라도 카드가 없으면 break
            break;

        //그라운드 덱이 비었을 때
        if (gdodo.empty()) {
            gdodo_front = 0;
        } else
            gdodo_front = gdodo.front();
        if (gsu.empty()) {
            gsu_front = 0;
        } else
            gsu_front = gsu.front();

        //수연종침
        if ((gdodo_front + gsu_front) == 5 && !gdodo.empty() && !gsu.empty()) {
            while (!gdodo.empty()) { //도도의 그라운드 뒤집어서 수연 덱 아래로 합침
                su.push_back(gdodo.back());
                gdodo.pop_back();
            }
            while (!gsu.empty()) {//수연의 그라운드 뒤집어서 수연 덱 아래로 합침
                su.push_back(gsu.back());
                gsu.pop_back();
            }
        }
        //도도종침
        if (gdodo_front == 5 || gsu_front == 5) {
            while (!gsu.empty()) { //수연의 그라운드 뒤집어서 도도 덱 아래로
                dodo.push_back(gsu.back());
                gsu.pop_back();
            }
            while (!gdodo.empty()) {//도도의 그라운드 뒤집어서 도도 덱 아래로
                dodo.push_back(gdodo.back());
                gdodo.pop_back();
            }
        }
    }
    //출력
    if (dodo.size() > su.size())
        cout << "do" ;
    else if (dodo.size() < su.size())
        cout << "su" ;
    else
        cout << "dosu" ;

    return 0;
}