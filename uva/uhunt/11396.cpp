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
int n,m,x,y,t;
int bpt(int s){
	    queue<int> Q;
    	Q.push(s);
    	color[s]=0;
    	int tots=0;
    	int zer=0;
    	while(!Q.empty()){
    		int u=Q.front();
    		tots++;
    		if(color[u])zer++;
    		Q.pop();
    		for(int i=0;i<adj[u].size();i++){
    			if(color[adj[u][i]]==-1){
    				color[adj[u][i]]=1-color[u];
    				Q.push(adj[u][i]);
    			}
    			else if(color[adj[u][i]]==color[u]){
    				return -1;
    			}
    		}}
    		if(tots==1)return 1;
    		else return min(tots-zer,zer);
}
int main() { 
#ifdef DEBUG_MODE
    freopen("inp.txt", "r", stdin);
    freopen("oup.txt", "w", stdout);
#endif
    scanf("%d",&t);
    while(t--){
    	scanf("%d %d",&n,&m);
    	color.assign(n,-1);
    	adj.assign(n,vi(0));
    	for(int i=0;i<m;i++){
    		scanf("%d %d",&x,&y);
    		adj[x].push_back(y);
    		adj[y].push_back(x);
    	}
    	int ans=0;
    	bool isbipartite=true;
    	for(int i=0;i<n && isbipartite;i++){
    		if(color[i]==-1){
    			int z=bpt(i);
    			dbg(z);
    			if(z==-1)isbipartite=false;
    			else ans+=z;
    		}
    	}
    	if(isbipartite)printf("%d\n",ans);
    	else printf("-1\n");
    }	
}