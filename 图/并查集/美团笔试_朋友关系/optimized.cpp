#include<iostream>
#include<map>
#include<set>
#include<vector>
using namespace std;
map<int,int> fathers;
int find(int u){
    if(fathers[u]==u){return u;}
    return fathers[u]=find(fathers[u]);
}
bool isSame(int u,int v){
    u=find(u);
    v=find(v);
    return u==v;
}
void join(int u,int v){
    u=find(u);
    v=find(v);
    if(u==v){return;}
    fathers[u]=v;
}
int main(){
    int n,m,q;
    cin>>n>>m>>q;

    //为了避免重边，用set存储朋友关系
    set<pair<int,int>> relations;
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        fathers[u]=u;
        fathers[v]=v;
        if(u>v){
            swap(u,v);
        }

        relations.insert({u,v});
    }
    vector<vector<int>> commands;
    for(int i=0;i<q;i++){
        int op,u,v;
        cin>>op>>u>>v;
        fathers[u]=u;
        fathers[v]=v;
        if(u>v){
            swap(u,v);
        }
        if(op==1){
            if(relations.find({u,v})!=relations.end()){
                relations.erase({u,v});
            }else{
                continue;//此时的删除关系是不合法的不进行操作
            }
        }
        commands.push_back({op,u,v});
    }
    for(auto& relation:relations){
        join(relation.first,relation.second);
    }
    vector<string> result;
    for(int i=commands.size()-1;i>=0;i--){
        int op,u,v;
        op=commands[i][0];
        u=commands[i][1];
        v=commands[i][2];
        if(op==2){
            if(isSame(u,v)){
                result.push_back("Yes");
            }else{
                result.push_back("No");
            }
        }else if(op==1){
            join(u,v);
        }
    }
    for(int i=result.size()-1;i>=0;i--){
        cout<<result[i]<<endl;
    }
}
