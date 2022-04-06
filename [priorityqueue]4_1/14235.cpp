//
// Created by 김지윤 on 2022/04/04.
//
#include <iostream>
#include <queue>

using namespace std;

//우선순위 큐 선언
priority_queue<int> pq;
int n,a;

void sol(int n){

    while(n--){
        cin>>a;
        //아이들을 만났다면
        if(a==0)
        {
            if(pq.size()==0) //선물이 없다면 -1 출력
                cout<<-1<<'\n';
            else{//선물이 있다면
                cout<<pq.top()<<'\n'; //선물을 줌
                pq.pop(); //선물을 줬으니까 큐에서 삭제
            }
        }
            //거점지를 방문했다면
        else{
            int val;//선물 가치
            for(int i=0;i<a;i++){
                cin>>val;
                pq.push(val);
            }
        }
    }
}

int main(){
    // 입출력 속도 향상
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    //입력
    cin>>n;
    //연산,출력
    sol(n);

    return 0;
}
