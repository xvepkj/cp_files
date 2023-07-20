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
vi color;
vector<vi> adj;
int n,m,x,y;
int main() { 
#ifdef DEBUG_MODE
    freopen("inp.txt", "r", stdin);
    freopen("oup.txt", "w", stdout);
#endif
    while(scanf("%d",&n),n){
    	color.assign(n,-1);
    	adj.assign(n,vi(0));
    	color[0]=0;
    	bool isbipartite=true;
    	scanf("%d",&m);
    	for(int i=0;i<m;i++){
    		scanf("%d %d",&x,&y);
    		adj[x].push_back(y);
    		adj[y].push_back(x);
    	}
    	queue<int> Q;
    	Q.push(0);
    	while(!Q.empty() && isbipartite){
    		int u=Q.front();
    		Q.pop();
    		for(int i=0;i<adj[u].size();i++){
    			if(color[adj[u][i]]==-1){
    				color[adj[u][i]]=1-color[u];
    				Q.push(adj[u][i]);
    			}
    			else if(color[adj[u][i]]==color[u]){
    				isbipartite=false;
    				break;
    			}
    		}
    	}
    	if(isbipartite)printf("BICOLORABLE.\n");
    	else printf("NOT BICOLORABLE.\n");
    }  	
}