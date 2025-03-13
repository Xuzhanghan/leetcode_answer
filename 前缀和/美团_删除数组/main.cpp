//涉及前缀和与滑动窗口（用来降低时间复杂度）
//这个写法没有使用滑动窗口
#include <iostream>
#include <vector>
using namespace std;
int get_count(int x, int factor) {
    int count = 0;
    while (x % factor == 0) { // 只要能整除 factor 就继续
        count++;
        x /= factor;
    }
    return count;
}

int main() {
    int n,k;
    cin>>n>>k;
    vector<int> a;
    for(int i=0;i<n;i++){
        int tmp;
        cin>>tmp;
        a.push_back(tmp);
    }
    vector<int> prefix2(n+1,0);
    vector<int> prefix5(n+1,0);//统计2,5，使用前缀和
    for(int i=0;i<n;i++){
        int count_2= get_count(a[i],2);
        int count_5= get_count(a[i],5);
        prefix2[i+1]=prefix2[i]+count_2;
        prefix5[i+1]=prefix5[i]+count_5;
    }
    int result=0;
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            int left_pair_2 = prefix2[n] - (prefix2[j+1] - prefix2[i]);
            int left_pair_5 = prefix5[n] - (prefix5[j+1] - prefix5[i]);
            int left_pair = min(left_pair_2, left_pair_5);
            if(left_pair>=k){
                result++;
            }else{
                break;
            }
        }
    }
    cout<<result;
}
