//
// Created by 김지윤 on 2022/03/30.
//
#include <iostream>
#include <deque>

using namespace std;

int n, k;
int cnt = 0, ans = 0;//내구도가 0인 칸의 개수 count, 몇번째 단계가 진행되고 있는지 count
deque<int> dur;//내구도
deque<bool> robot; //로봇이 있으면 true, 없으면 false

//회전 함수
void rotate() {
    ans++;

    //벨트 회전: 로봇회전+내구성회전
    robot.push_front(robot.back());
    robot.pop_back();
    dur.push_front(dur.back());
    dur.pop_back();
    robot[n - 1] = false; //n번에 있는 로봇은 내림

    //로봇 한칸 회전
    for (int i = n - 2; i >= 0; i--) { //가장 먼저 벨트에 올라간 로봇부터
        if (robot[i] && !robot[i + 1] && dur[i + 1] >= 1) {
            robot[i + 1] = true;
            robot[i] = false; //i에 있던 로봇이 i+1로 감
            dur[i + 1]--;
            if (dur[i + 1] == 0)
                cnt++;
        }
    }
    robot[n - 1] = false;

    //로봇 올리기
    if (dur[0] > 0) {
        dur[0]--;
        robot[0] = true;
        if (dur[0] == 0)
            cnt++;
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    //입력
    int a;
    cin >> n >> k;
    for (int i = 0; i < 2 * n; i++) {
        cin >> a;
        dur.push_back(a);
        robot.push_back(false);//robot 덱 false로 초기화
    }
    //연산, 출력
    while (true) {
        rotate();
        if(cnt==k){
            cout << ans << '\n';
            return 0;
        }
    }

    return 0;
}