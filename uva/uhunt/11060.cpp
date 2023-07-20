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
int n,m;
int cases=0;
char name[105][105];
char temp[105];
int main() { 
#ifdef DEBUG_MODE
    freopen("inp.txt", "r", stdin);
    freopen("oup.txt", "w", stdout);
#endif
    while(scanf("%d",&n)==1){
    	memset(name,-1,sizeof name);
    	int indeg[105] = {};
    	adj.assign(n,vi(0));
    	cases++;
    	map<string,int> ele;
    	for(int i=0;i<n;i++){
    		scanf("%s",name[i]);
    		ele[name[i]]=i;
    	}
    	scanf("%d",&m);
    	while(m--){
    		scanf("%s",temp);
    		int x=ele[temp];
    		scanf("%s",temp);
    		int y=ele[temp];
    		adj[x].push_back(y);
    		indeg[y]++;
    	}
    	priority_queue<int, vector<int>, greater<int> > Q;
        for(int i = 0; i < n; i++)
            if(indeg[i] == 0)
                Q.push(i);
        printf("Case #%d: Dilbert should drink beverages in this order:",cases);
        while(!Q.empty()) {
            int z = Q.top();
            Q.pop();
            for(int i=0;i<adj[z].size();i++) {
                indeg[adj[z][i]]--;
                if(indeg[adj[z][i]] == 0)
                    Q.push(adj[z][i]);
            }
            printf(" %s", name[z]);
        }
        puts(".\n");
    }
}