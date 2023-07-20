/*PKJ*/
#define DEBUG_MODE
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
vector<bool> av;
vi dfs_low;
vi dfs_parent;
vii bcl;
int dfscount,dfsRoot,rootchildren,artcount,x,y,n,bc,m;
char c,a,b,d,e,f;
void findartcount(int u){
    dfs_low[u]=dfs_num[u]=dfscount++;
    for(int j=0;j<adj[u].size();j++){
        int v=adj[u][j];
        if(dfs_num[v]==-1){
            dfs_parent[v]=u;
            findartcount(v);
            if(dfs_low[v]>dfs_num[u]){bc++;bcl.push_back(ii(min(u,v),max(u,v)));}
            dfs_low[u]=min(dfs_low[u],dfs_low[v]);            
        }
        else if(v!=dfs_parent[u])
            dfs_low[u]=min(dfs_low[u],dfs_num[v]);
    }
}
int main() { 
#ifdef DEBUG_MODE
    freopen("inp.txt", "r", stdin);
    freopen("oup.txt", "w", stdout);
#endif
    while(scanf("%d",&n)==1){
        adj.assign(n+1,vi(0));
        bcl.clear();
        for(int i = 0; i < n; i++) {
            scanf("%d ", &x);
            scanf("(%d)", &m);
            while(m--) {
                scanf("%d", &y);
                adj[x].push_back(y);
                adj[y].push_back(x);
            }
        }
            dfscount=1;
            bc=0;
            dfs_low.assign(n,0);
            dfs_num.assign(n,-1);
            dfs_parent.assign(n,0);
            for(int i=0;i<n;i++)
                if(dfs_num[i]==-1){
                    findartcount(i);
                }
    }
}