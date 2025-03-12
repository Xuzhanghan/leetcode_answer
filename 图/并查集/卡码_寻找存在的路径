#include<iostream>
#include<vector>
using namespace std;
void init(vector<int>& fathers){
    for(int i=0;i<fathers.size();i++){
        fathers[i]=i;
    }
}
int find(int u,vector<int>& fathers){
    if(fathers[u]==u){return u;}
    else return fathers[u]=find(fathers[u],fathers);
}
void join(int u,int v,vector<int>& fathers){
    u=find(u,fathers);
    v=find(v,fathers);
    if(u==v) return;
    fathers[u]=v;
}
bool isSame(int u,int v,vector<int>& fathers){
    u=find(u,fathers);
    v=find(v,fathers);
    return u==v;
}
int main(){
    int N,M;
    cin>>N>>M;//有N个节点，即数组用N+1个
    vector<int> fathers(N+1,0);
    init(fathers);
    for(int i=0;i<M;i++){
        int s,t;
        cin>>s>>t;
        join(s,t,fathers);
    }
    int source,destination;
    cin>>source>>destination;
    if(isSame(source,destination,fathers)){
        cout<<"1";
    }else{
        cout<<"0";
    }
}
