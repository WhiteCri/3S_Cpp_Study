//
//  main.cpp
//  PJ1_4
//
//  Created by 김재은 on 2017. 4. 5..
//  Copyright © 2017년 김재은. All rights reserved.
//

#include <iostream>

using namespace std;
int main(){
    double get_Money, interest_Percent, par_Value, time;
    
    cout << "받고자 하는 금액, 이자율(%), 지속기간(년)을 입력하시오: ";
    cin >> get_Money >> interest_Percent >> time;
    
    interest_Percent /=100; // 이자율 퍼센트 계산
    
    par_Value = get_Money / (1- interest_Percent * time); // 액면가 계산
    
    cout << "액면가는 $"<<par_Value<<"이다."<<endl;
    
    return 0;
}
