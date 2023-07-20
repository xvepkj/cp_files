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
typedef pair< float, ii > fii;
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
int t,m,u,v,n,x,y,z;
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
int main() { 
#ifdef DEBUG_MODE
    freopen("inp.txt", "r", stdin);
    freopen("oup.txt", "w", stdout);
#endif
    while(scanf("%d %d",&n,&m),(m+n)){
    viii dax;
    int tot=0;
    for(int i=0;i<m;i++){
        scanf("%d %d %d",&x,&y,&z);
        dax.push_back(iii(z,ii(x,y)));
        tot+=z;
    }
    UnionFind UF(n);
    int ans=0;
    sort(dax.begin(),dax.end());
    for(int i=0;i<m;i++){
        if(!UF.isSameSet(dax[i].second.first,dax[i].second.second))
        {
            ans+=dax[i].first;
            UF.unionSet(dax[i].second.first,dax[i].second.second);
        }
    }
    printf("%d\n",tot-ans);
}
}
