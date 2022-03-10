//
//  12840.cpp
//  Altu-Bitu-2
//
//  Created by 김지윤 on 2022/03/07.
//


#include <iostream>
#define day 86400
#define h_time 3600
#define m_time 60

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int h,m,s,q,t,c,curr;
    cin >> h >> m >> s;
    curr = h*h_time + m*m_time + s;

    cin>>q;
    
    for(int i=0; i<q; i++){
        cin>>t;
        if(t==3){
            cout<<curr/h_time<<' '<<(curr/m_time)%m_time<<' '<<curr%m_time<<'\n';
        }
        else{
            cin>>c;
            if(t==1){
                curr=(curr+c)%day;
            }
            else if(t==2){
                curr=(curr-c)%day;
                if(curr<0)
                    curr+=day;
            }
        }
    }
 
    return 0;
    
}
