//并查集的特点是很容易实现加入两个点，但是删除并不容易，本题的思路为倒序，把删除关系转化为添加关系反向操作
//存在问题：空间超限！题目中的数据范围太大，不能单纯的采用数组结构来存储，考虑使用哈希表来节省空间
//同时,注意重复的边的问题
#include <iostream>
#include <string>
#include <vector>
using namespace std;
void init(vector<int>& fathers){
    for(int i=0;i<fathers.size();i++){
        fathers[i]=i;
    }
}
int find(int u,vector<int>& fathers){
    if(fathers[u]==u){return u;}
    return fathers[u]=find(fathers[u],fathers);
}
bool isSame(int u,int v,vector<int>& fathers){
    u=find(u,fathers);
    v=find(v,fathers);
    return u==v;
}
void join(int u,int v,vector<int>& fathers){
    u=find(u,fathers);
    v=find(v,fathers);
    if(u==v){return;}
    fathers[u]=v;
}
int main() {
    int n,m,q;
    cin>>n>>m>>q;
    vector<int> fathers(n+1,0);
    init(fathers);
    vector<vector<int>> map(n+1,vector<int>(n+1,0));
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        map[u][v]=1;
    }
    vector<vector<int>> commands;
    for(int i=0;i<q;i++){
        int op,u,v;
        cin>>op>>u>>v;
        if(op==1){
            map[u][v]=0;
        }
        commands.push_back({op,u,v});
    }
    //根据最终的关系建立fathers数组
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(map[i][j]==1){
                join(i,j,fathers);
            }
        }
    }
    vector<string> result;
    for(int i=commands.size()-1;i>=0;i--){
        vector<int> command=commands[i];
        int op,u,v;
        op=command[0];
        u=command[1];
        v=command[2];
        if(op==2){
            if(isSame(u, v, fathers)){
                result.emplace_back("Yes");
            }else{
                result.emplace_back("No");
            }
        }else if(op==1){
            join(u,v,fathers);
        }
    }
    for(int i=result.size()-1;i>=0;i--){
        cout<<result[i]<<endl;
    }
}
