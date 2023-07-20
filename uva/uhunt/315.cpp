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
vector<bool> av;
vi dfs_low;
vi dfs_parent;
int dfscount,dfsRoot,rootchildren,artcount,x,y,n;
char c;
void findartcount(int u){
    dfs_low[u]=dfs_num[u]=dfscount++;
    for(int j=0;j<adj[u].size();j++){
        int v=adj[u][j];
        if(dfs_num[v]==-1){
            dfs_parent[v]=u;
            if(u==dfsRoot)rootchildren++;
            findartcount(v);
            if(u!=dfsRoot && dfs_low[v]>=dfs_num[u])av[u]=true;
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
    while(scanf("%d",&n),n){
        adj.assign(n+1,vi(0));
        while(scanf("%d", &x),x) {
            while(scanf("%d%c", &y, &c) == 2) {
                adj[x].push_back(y);
                adj[y].push_back(x);
                if(c == '\n')   break;
            }
        }
            dfscount=1;
            dfs_low.assign(n+1,0);
            dfs_num.assign(n+1,-1);
            dfs_parent.assign(n+1,0);
            av.assign(n+1,false);
            artcount=0;
            for(int i=1;i<=n;i++)
                if(dfs_num[i]==-1){
                    dfsRoot=i;rootchildren=0;
                    findartcount(i);
                    if(rootchildren>1)av[i]=true;
                }
              printf("%d\n",count(av.begin(), av.end(), true));
    }
}