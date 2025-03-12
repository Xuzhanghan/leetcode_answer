#include <iostream>
#include <vector>
using namespace std;
int N=1005;
vector<int> fathers(N,0);
void init(){
    for(int i=0;i<N;i++){
        fathers[i]=i;
    }
}
int find(int u){
    if(fathers[u]==u){return u;}
    else return fathers[u]=find(fathers[u]);
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
    int n;
    cin>>n;
    init();
    
    for(int i=0;i<n;i++){
        int s,t;
        cin>>s>>t;
        if(isSame(s,t)){
            cout<<s<<" "<<t;
            break;
        }
        join(s,t);
    }
    

}
