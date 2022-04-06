//
// Created by 김지윤 on 2022/03/23.
//
#include <iostream>
#include <string>
#include <cstring>

using namespace std;

//답일 가능성이 있으면 참, 아니면 거짓으로 저장
bool answer_num[1000];

void answer_numSet() {
    memset(answer_num, true, sizeof(answer_num));
    for (int i = 123; i < 1000; i++) {
        string number = to_string(i); //숫자를 문자열 타입으로 변환
        if (number[0] - '0' == 0 || number[1] - '0' == 0 || number[2] - '0' == 0) //1부터 9까지의 숫자만 사용 가능
            answer_num[i] = false;
        if (number[0] == number[1] || number[1] == number[2] || number[2] == number[0])
            answer_num[i] = false;
    }
}

//strike와 ball 함수
//a와 b의 s_cnt와 b_cnt가 strike,ball과 같으면 참, 아니면 거짓
bool sbGame(string a, string b, int strike, int ball) {
    int s_cnt = 0, b_cnt = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (i == j && a[i] == b[i]) { //위치와 값이 같으면 strike++
                s_cnt++;
            } else if (a[i] == b[j]) //값만 같으면 ball++
                b_cnt++;
        }
    }
    if (strike == s_cnt && ball == b_cnt) //입력된 값과 계산 값이 같으면 true 리턴, 아니면 false 리턴
        return true;
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, s, b, ans = 0;
    string num;
    bool tmp = true;
    cin >> n;
    answer_numSet();//답일 가능성을 저장한 배열 초기화

    //입력, 연산
    while (n--) {
        cin >> num >> s >> b;
        for (int i = 123; i < 1000; i++) { //1부터 9까지의 서로 다른 숫자로 구성해야하므로 123 미만은 어차피 해당 안됨
            if (tmp)  //초기 answer_num이 참인것들 중에서만 확인하면 됨
                answer_num[i] = sbGame(to_string(i), num, s, b); //sbGame의 결과에 따라 answer_num 변경
            else //while문이 진행되면서 앞서 false였던게 다시 true가 될 수 없게 해야함
                answer_num[i] = answer_num[i] && sbGame(to_string(i), num, s, b);
        }
        tmp = false;
    }

    for (int i = 123; i < 1000; i++) {
        if (answer_num[i])
            ans++;
    }

    cout << ans << '\n';

    return 0;
}