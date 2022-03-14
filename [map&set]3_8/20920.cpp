//
// Created by 김지윤 on 2022/03/14.
//
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> mem;
map<string, int> w;

bool cmp(const string &a, const string &b) {
    if (w[a] != w[b]) {//1.단어가 나오는 횟수가 감소하는 순서
        return w[a] > w[b];
    }
    if (a.length() != b.length()) {//2.단어의 길이가 같으면 감소하는 순서
        return a.length() > b.length();
    }
    return a < b;//3.(단어가 나오는 횟수와 길이 모두 같고) 단어가 사전 순으로 증가하는 순서
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;//단어의 개수, 길이 기준
    string word;
    cin >> n >> m;
    while (n--) {
        cin >> word;
        if (word.length() < m)
            continue;
        if (w.find(word)==w.end()) {
            w[word]=0;
            mem.push_back(word);
        }
        w[word]++;
    }
    sort(mem.begin(), mem.end(), cmp);

    //출력
    for (int i = 0; i < mem.size(); i++) {
        cout << mem[i] << '\n';
    }

    return 0;
}