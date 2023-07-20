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
char a[210][100];
char s[100];
char e[100];
char xx[100];
vector<vi> adj;
vi d;
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
            }
        }
    }
}
int main() { 
#ifdef XVENOM
    freopen("inp.txt", "r", stdin);
    freopen("oup.txt", "w", stdout);
#endif
    scanf("%d",&t);
    getchar();
    gets(s);
    while(t--){
        map<string,int> mapx;
        int n=0;
        while(gets(a[n])){
            if(a[n][0]=='*')break;
            mapx[a[n]]=n;
            n++;
        }
        adj.assign(n,vi(0));
        d.assign(n,1e5);
        for(int j=0;j<n;j++){
            for(int k=j+1;k<n;k++){
               int cnt=0;
               if(strlen(a[j])==strlen(a[k])){
                    for(int i=0;a[j][i]!='\0';i++)if(a[j][i]!=a[k][i])cnt++;
                    if(cnt==1){
                        adj[mapx[a[j]]].push_back(mapx[a[k]]);
                        adj[mapx[a[k]]].push_back(mapx[a[j]]);
                    }
               }
            }
        }
        while(gets(xx)){
            if(xx[0]=='\0')break;
            sscanf(xx,"%s %s",s,e);
            bfs(mapx[s]);
            printf("%s %s %d\n",s,e,d[mapx[e]]);
        }
        if(t)printf("\n");
    }
}


