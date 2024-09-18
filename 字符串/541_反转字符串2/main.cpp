#include <iostream>
#include <vector>
#include <numeric>//含有accumulate
#include <algorithm>//含有swap,max_element函数
using namespace std;
//c++中有swap函数
//bug:1.reverse函数是左开右闭的，-1会导致出错
//2.c++中作为参数传入，对其值的修改是否有效
string reverseStr(string s, int k) {
    int len=s.size();
    int remaining=len%(2*k);
    int n=len/(2*k);
    //是否默认2k一定不超过字符串的长度
    for(int i=0;i<n;i++){
        reverse(s.begin()+i*2*k,s.begin()+k+i*2*k);
    }
    if(remaining<k){
        reverse(s.begin()+n*2*k,s.end());
    }else{
        reverse(s.begin()+n*2*k,s.begin()+n*2*k+k);
    }
    return s;
}
int main() {
    string s = "abcd";
    int k = 3;
    cout<<"answer: "<<reverseStr(s,k);
}
