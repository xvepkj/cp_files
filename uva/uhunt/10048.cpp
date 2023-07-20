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
int t,m,u,v,n,x,y,z,c1,c2,q,r;
bool visited[200];
int king;
vector<vii> adj;
class UnionFind {                                              // OOP style
private:
  vi p, rank, setSize;                       // remember: vi is vector<int>
  int numSets;
public:
  UnionFind(int N) {
    setSize.assign(N, 1); numSets = N; rank.assign(N, 0);
    p.assign(N, 0); for (int i = 0; i < N; i++) p[i] = i; }
  int findSet(int i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); }
  bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }
  void unionSet(int i, int j) { 
    if (!isSameSet(i, j)) { numSets--; 
    int x = findSet(i), y = findSet(j);
    // rank is used to keep the tree short
    if (rank[x] > rank[y]) { p[y] = x; setSize[x] += setSize[y]; }
    else                   { p[x] = y; setSize[y] += setSize[x];
                             if (rank[x] == rank[y]) rank[y]++; } } }
  int numDisjointSets() { return numSets; }
  int sizeOfSet(int i) { return setSize[findSet(i)]; }
};
void dfs(int i,int ans){
    int x;
    visited[i]=true;
    if(i==(c2-1))king=ans;
    for(int j=0;j<(int)adj[i].size();j++){
        int v=adj[i][j].first;
        x=max(ans,adj[i][j].second);
        if(!visited[v])dfs(v,x);
    }
}
int main() { 
#ifdef XVENOM
    freopen("inp.txt", "r", stdin);
    freopen("oup.txt", "w", stdout);
#endif
    int t=0;
    while(scanf("%d %d %d",&n,&m,&q),(m+n+q)){
    if(t)printf("\n");
    t++;
    adj.assign(n,vii(0));
    viii dax;
    for(int i=0;i<m;i++){
        scanf("%d %d %d",&x,&y,&z);
        dax.push_back(iii(z,ii(x-1,y-1)));
    }
    UnionFind UF(n);
    sort(dax.begin(),dax.end());
    for(int i=0;i<m;i++){
        if(!UF.isSameSet(dax[i].second.first,dax[i].second.second))
        {
            UF.unionSet(dax[i].second.first,dax[i].second.second);
            adj[dax[i].second.first].push_back(ii(dax[i].second.second,dax[i].first));
            adj[dax[i].second.second].push_back(ii(dax[i].second.first,dax[i].first));
        }
    }
    printf("Case #%d\n",t);
    while(q--){
        scanf("%d %d",&c1,&c2);
        memset(visited,false,sizeof visited);
        dfs(c1-1,0);
        if(!visited[c2-1])printf("no path\n");
        else printf("%d\n",king);
    }
}
}
