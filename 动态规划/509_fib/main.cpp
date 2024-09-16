#include <vector>
#include <stack>
#include <unordered_map>
using namespace std;
//本题出现的bug

int fib(int n) {
    int dp[50];
    dp[0]=0;
    dp[1]=1;
    for(int i=2;i<=n;i++){
        dp[i]=dp[i-1]+dp[i-2];
    }
    return dp[n];
}
int main() {
    cout<<fib(4);
}
