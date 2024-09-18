#include <iostream>
#include <vector>
#include <stack>
#include <string>
using namespace std;
//
//string reverseWords(string s) {
//    stack<string> stack1;
//    string temp;
//    for(int i=0;i<s.size();i++){
//            for(int j=i;j<s.size()&&s[i]!=' ';j++){
//                if(s[j]==' '){
//                    temp=s.substr(i,j-i);
//                    stack1.push(temp);
//                    i=j+1;
//                }
//                if(j==s.size()-1&&s[i]!=' '&&i<s.size()){
//                    temp=s.substr(i,j+1-i);
//                    stack1.push(temp);
//                    i=j+1;
//                }
//            }
//    }
//    string result;
//    result=stack1.top();
//    stack1.pop();
//    while(!stack1.empty()){
//        temp=stack1.top();
//        stack1.pop();
//        result=result+' '+temp;
//    }
//    return result;
//}
//之前的解法需要打补丁的地方太多
/*
 * 1.利用java,s.trim()可以去掉开头和末尾的空白字符
 * */
string reverseWords(string s) {

}
int main() {
    string s= "t i ";
    cout<<reverseWords(s);
}
