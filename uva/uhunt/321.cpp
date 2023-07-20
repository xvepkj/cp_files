#include <cstdio>
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
int t,m,u,v,n,x,y,z,c1,c2,q,r,i,j,d,s;
ii p[11][1<<11];
string s1;
void printpath(int i,int j){
  if(i==0 && j==1)return;
    ii x=p[i][j];
    errp("%d %d",x.first,x.second);
    if(x.first==i){
        int h=j^x.second;
        int k=0;
        for(int g=0;g<r;g++)if(h&(1<<g))k=g;
        printpath(x.first,x.second);
        if(x.second&(1<<k))s1="off";
        else s1="on";
        printf("- Switch %s light in room %d.\n",s1.data(),k+1);
    }
    else {
        printpath(x.first,x.second);
        printf("- Move to room %d.\n",i+1);
    }
}
int main() { 
#ifdef XVENOM
    freopen("inp.txt", "r", stdin);
    freopen("oup.txt", "w", stdout);
#endif
    t=0;
    while(scanf("%d %d %d",&r,&d,&s),(r+d+s)){
        t++;
        vector<vi> rw;
        int dis[11][1<<11];
        int lights[11][11];
        rw.assign(r,vi(0));
        memset(dis,-1,sizeof dis);
        memset(lights,-1,sizeof lights);
        for(int i=0;i<d;i++){
            scanf("%d %d",&x,&y);
            rw[x-1].push_back(y-1);
            rw[y-1].push_back(x-1);
            }
        for(int i=0;i<s;i++){
            scanf("%d %d",&x,&y);
            lights[x-1][y-1]=1;
        }
        queue<ii> Q;
        Q.push(ii(0,1));
        dis[0][1]=0;
        while(!Q.empty()){
            ii u=Q.front();
            Q.pop();
            int r1=u.first;
            int L=u.second;
            // dbg(r1);
            // dbg(L);
            for(int i=0;i<(int)rw[r1].size();i++){
                int v=rw[r1][i];
                if(dis[v][L]==-1){
                if(L&(1<<v)){
                    dis[v][L]=dis[r1][L]+1;
                    p[v][L]=ii(r1,L);
                    Q.push({v,L});
                }
                }
            }
            for(int i=0;i<r;i++){
                if(i!=r1 && lights[r1][i]==1){
                    // dbg(i);
                    int L1=L^(1<<i);
                    if(dis[r1][L1]==-1){
                        dis[r1][L1]=dis[r1][L]+1;
                        p[r1][L1]=ii(r1,L);
                        Q.push(ii(r1,L1));
                    }
                }
            }
        }
    printf("Villa #%d\n",t);
    if(dis[r-1][1<<(r-1)]!=-1){
        printf("The problem can be solved in %d steps:\n",dis[r-1][1<<(r-1)]);
        printpath(r-1,1<<(r-1));
    }
    else printf("The problem cannot be solved.\n");
    printf("\n");
    }
}

