/*PKJ*/
// #define DEBUG_MODE
#include <cstdio>
#include <cstring>
#include<iostream>
#include <cassert>
#include <cmath>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <bitset>
#include <map>
#include <set>
using namespace std;
typedef long long int ll;
typedef vector< int > vi;
typedef pair< int, int > ii;
typedef vector< ii > vii;
typedef vector< ll > vll;
#ifdef DEBUG_MODE
    #define errp(...) fprintf(stderr, __VA_ARGS__)
#else
    #define errp(...)
#endif
#define dbg(x) errp("[%s = %s]\n", #x, to_string(x).data())
vector<vi> adj;
vi dfs_num;
vi dfs_low;
vi visited;
vi s;
int n,m,dfscount,t;
char l[200];
char r[200];
map<string,int> exist;
string name[26];
void tarjanSCC(int u){
    // dbg(u);
    dfs_low[u]=dfs_num[u]=dfscount++;
    s.push_back(u);
    visited[u]=1;
    for(int j=0;j<adj[u].size();j++){
        int v=adj[u][j];
        if(dfs_num[v]==-1)
           tarjanSCC(v);
        if(visited[v])
            dfs_low[u]=min(dfs_low[u],dfs_low[v]);
    }
    if(dfs_low[u]==dfs_num[u]){
        vi comp;
        while(true){
            comp.push_back(s.back());
            visited[s.back()]=0;
            s.pop_back();
            if(comp.back()==u)break;
        }
        printf("%s",name[comp[0]].data());
        for(int i=1;i<comp.size();i++){
            printf(", %s",name[comp[i]].data());
        }
        printf("\n");
    }
}
int main() { 
#ifdef DEBUG_MODE
    freopen("inp.txt", "r", stdin);
    freopen("oup.txt", "w", stdout);
#endif
    t=0;
    while(scanf("%d %d",&n,&m)==2,(n+m)){
        if(t++>0)printf("\n");
        adj.assign(n,vi(0));
        s.clear();
        exist.clear();
        int cur=0;
        while(m--){
            scanf("%s %s",r,l);
            string a=string(r);
            string b=string(l);
            if(exist.find(a)==exist.end()){
                name[cur] = a;
                exist[a]=cur++;
                    }
            if(exist.find(b)==exist.end()){
                name[cur] = b;
                exist[b]=cur++;
                    }
            // errp("%d %d\n",exist[a],exist[b]);
            adj[exist[a]].push_back(exist[b]);
        }
        // for(int i=0;i<n;i++)errp("name of %d is: %s\n",i,name[i].data());
        dfs_num.assign(n,-1);
        dfs_low.assign(n,0);
        visited.assign(n,0);
        dfscount=0;
        printf("Calling circles for data set %d:\n",t);
        for(int i=0;i<n;i++)
            {   
             if(dfs_num[i]==-1)tarjanSCC(i);}
    }
}