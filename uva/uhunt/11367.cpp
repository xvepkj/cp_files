// #define DEBUG_MODE
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
typedef pair< int, ii > iii;
typedef vector< ii > vii;
typedef vector< iii > viii;
typedef vector< ll > vll;
#ifdef DEBUG_MODE
    #define errp(...) fprintf(stderr, __VA_ARGS__)
#else
    #define errp(...)
#endif
#define dbg(x) errp("[%s = %s]\n", #x, to_string(x).data())
const int maxfuel=100;
const int max_destination_vertexes=1000;
int alreadycalculated[105][1001];
int p[1010];
vector<viii> adj;
int n,m,c,q,a,b,u,v,w,s,e,fuel,curlocation,start,cost,destination,cost1,fuelneeded;
int main() { 
#ifdef DEBUG_MODE
    freopen("inp.txt", "r", stdin);
    freopen("oup.txt", "w", stdout);
#endif
    while(scanf("%d %d",&n,&m)!=EOF){
        adj.assign(n,viii(0));
        for(int i=0;i<n;i++){
            scanf("%d",&p[i]);
        }
        for(int i=0;i<m;i++){
            scanf("%d %d %d",&u,&v,&fuel);
            adj[u].push_back(iii(0,ii(v,fuel)));
            adj[v].push_back(iii(0,ii(u,fuel)));
        }
        scanf("%d",&q);
        while(q--){
            priority_queue <iii, vector<iii>, greater<iii> > Q;
            scanf("%d %d %d",&c,&s,&e);
            memset(alreadycalculated,-1,sizeof(alreadycalculated));
            Q.push(iii(0,ii(s,0)));
            ll ans=-1;
            while(!Q.empty()){
                cost=Q.top().first;
                curlocation=Q.top().second.first;
                fuel=Q.top().second.second;
                //dbg(curlocation);
                //dbg(cost);
                Q.pop();
                if(curlocation==e){ans=cost;break;}
                if(alreadycalculated[fuel][curlocation]!=-1)continue;
                alreadycalculated[fuel][curlocation]=cost;
                if(fuel<c){
                    Q.push(iii((cost+p[curlocation]),ii(curlocation,fuel+1)));
                }
                for(int i=0;i<adj[curlocation].size();i++){
                    cost1=adj[curlocation][i].first; //never used
                    destination=adj[curlocation][i].second.first;
                    fuelneeded=adj[curlocation][i].second.second;
                    if(fuelneeded<=fuel){
                        Q.push(iii(cost,ii(destination,fuel-fuelneeded)));
                    }
                }       
            }
        if(ans==-1)printf("impossible\n");
        else printf("%lld\n",ans);
        }
    }
}
