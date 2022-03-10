//
//  10804.cpp
//  Altu-Bitu-2
//
//  Created by 김지윤 on 2022/03/07.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int b,e; //begin, end
    
    vector<int> arr(21);
    for(int i=1;i<21;i++){
        arr[i]=i;
    }
    
    //입력,연산
    for(int i=0;i<10;i++){
        cin >>b>>e;
        reverse(arr.begin()+b, arr.begin()+e+1);
    }
    
    //출력
    for(int i=1;i<21;i++){
        cout<<arr[i]<<' ';
    }
    
    return 0;
}
