#include <cstdio>
#include<iostream>
#include <cstring>
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
typedef pair< float, ii > fii;
typedef pair< int, ii > iii;
typedef vector< ii > vii;
typedef vector< iii > viii;
typedef vector< ll > vll;
#ifdef XVENOM
    #define errp(...) fprintf(stderr, __VA_ARGS__)
#else
    #define errp(...)
#endif
#define dbg(x) errp("[%s = %s]\n", #x, to_string(x).data())
const int MAXLEN=10010;

int n,m,t,x,y,u,v,w;
vector<vi> adj;
vi d;
int f[3000];
void bfs(int s){
    queue<int> Q;
    Q.push(s);
    d[s]=0;
    while(!Q.empty()){
        int u=Q.front();
        Q.pop();
        for(int i=0;i<(int)adj[u].size();i++){
            int v=adj[u][i];
            if(d[v]==1e5){
                Q.push(v);
                d[v]=d[u]+1;
                f[d[v]]++;
            }
        }
    }
}
int main() { 
#ifdef XVENOM
    freopen("inp.txt", "r", stdin);
    freopen("oup.txt", "w", stdout);
#endif
    scanf("%d",&n);
    adj.assign(n,vi(0));
    for(int i=0;i<n;i++){
        scanf("%d",&x);
        while(x--){
            scanf("%d",&y);
            adj[i].push_back(y);
        }
    }
    scanf("%d",&t);
    while(t--){
        memset(f,0,sizeof f);
        d.assign(n,1e5);
        scanf("%d",&w);
        bfs(w);
        int maxx=0;
        int kiskamax=0;
        for(int i=1;i<=n;i++){
            if(f[i]>maxx){
                maxx=f[i];
                kiskamax=i;
            }
        }
        if(maxx==0)printf("0\n");
        else printf("%d %d\n",maxx,kiskamax);
    }
}


