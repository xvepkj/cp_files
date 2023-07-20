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
vi ts;
int vis[200];
int n,m;
void dfs(int z){
	vis[z]=1;
	for(int i=0;i<adj[z].size();i++)
		if(vis[adj[z][i]]==-1)dfs(adj[z][i]);
	ts.push_back(z);
}
int main() { 
#ifdef DEBUG_MODE
    freopen("inp.txt", "r", stdin);
    freopen("oup.txt", "w", stdout);
#endif
    while(scanf("%d %d",&n,&m),(n+m)){
    	ts.clear();
    	memset(vis,-1,sizeof vis);
    	adj.assign(n,vi(0));
    	int x,y;
    	for(int i=0;i<m;i++){
    		scanf("%d %d",&x,&y);
    		adj[x-1].push_back(y-1);
    	}
    	for(int i=0;i<n;i++)
    		if(vis[i]==-1)dfs(i);
    	reverse(ts.begin(),ts.end());
    	printf("%d",ts[0]+1);
    	for(int i=1;i<ts.size();i++)
    		printf(" %d",ts[i]+1);
    	printf("\n");
    }
}