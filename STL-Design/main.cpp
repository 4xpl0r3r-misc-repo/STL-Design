//
//  main.cpp
//  STL-Design
//
//  Created by 张开楠 on 2021/1/2.
//

#include <iostream>
#include "vector.hpp"
#include "list.hpp"
using namespace std;

int main(){
    // sort和search使用统一sort函数完成，copy使用运算符重载和构造函数完成
    istd::vector<int> myV,myV1(1);
    myV1.push_back(5);
    cout<<myV1[0]<<myV1[1]<<myV1[2]<<endl;
    istd::vector<int> myV2(myV1);
    istd::list<int> myL,myL1(myL);
    return 0;
}
