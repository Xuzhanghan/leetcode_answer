#include <iostream>
#include <vector>
#include <numeric>//含有accumulate
#include <algorithm>//含有swap,max_element函数
using namespace std;
//c++中有swap函数
void reverseString(vector<char>& s) {
    int len=s.size();
    int left=0;
    int right=len-1;
    while(left<right){
//        char temp=s[right];
//        s[right]=s[left];
//        s[left]=temp;
        swap(s[right],s[left]);
        left++;
        right--;
    }
}
int main() {
    vector<char> s={'H','a','n','n','a','h'};
    reverseString(s);
    for(int i=0;i<s.size();i++){
        cout<<s[i];
    }
}
