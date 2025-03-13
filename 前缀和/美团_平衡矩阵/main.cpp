#include <iostream>
#include <vector>
using namespace std;

int main() {

    //得到矩阵大小
    int n;
    cin >> n;

    vector<vector<int>> nums(n+1,vector<int>(n+1,0));
    string str;
    for(int i=1;i<=n;i++){
        cin>>str;
        for(int j=1;j<=n;j++){
            if(str[j-1]=='1'){
                nums[i][j]=1;
            }else{
                nums[i][j]=0;
            }
        }
    }
    vector<vector<int>> pre_data(n+1,vector<int>(n+1,0));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            int a=pre_data[i][j-1];
            int b=pre_data[i-1][j];
            int c=pre_data[i-1][j-1];
            int d=nums[i][j];
            pre_data[i][j]=pre_data[i][j-1]+pre_data[i-1][j]-pre_data[i-1][j-1]+nums[i][j];
        }
    }

    for(int k=1;k<=n;k++){
        int count=0;
        if(k%2==0){
            for(int i=1;i<=n-k+1;i++){
                for(int j=1;j<=n-k+1;j++){
                    int sum=pre_data[i+k-1][j+k-1]-pre_data[i+k-1][j-1]-pre_data[i-1][j+k-1]+pre_data[i-1][j-1];
                    if(sum*2==k*k){
                        count++;
                    }
                }
            }
        }
        cout<<count<<endl;
    }

}
