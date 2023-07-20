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
typedef pair< double, ii > fii;
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
int t,m,u,v;
double r,n;
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
    scanf("%d",&t);
    for(int f=1;f<=t;f++){
        vii x;
        vector<pair<double,ii>> y;
        scanf("%lf %lf",&n,&r);
        for(int i=0;i<n;i++)
           {scanf("%d %d",&u,&v);
            x.push_back(ii(u,v));}
        UnionFind UF(n);
        double roads=0;
        double rr=0;
        int states=0;
        int E=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                double k=(x[i].first-x[j].first)*(x[i].first-x[j].first);
                double l=(x[i].second-x[j].second)*(x[i].second-x[j].second);
                double h=(k+l);
                y.push_back(fii(h,ii(i,j)));
                E++;
                }
        }
        sort(y.begin(),y.end());
        for(int i=0;i<E;i++){
            if(!UF.isSameSet(y[i].second.first,y[i].second.second) && sqrt(y[i].first)<=r){
                roads+=sqrt(y[i].first);
                UF.unionSet(y[i].second.first,y[i].second.second);
            }
        }
        int ans=UF.numDisjointSets();
        for(int i=0;i<E;i++)if(!UF.isSameSet(y[i].second.first,y[i].second.second)){
            UF.unionSet(y[i].second.first,y[i].second.second);
            rr+=sqrt(y[i].first);
        }
            int ans1=round(roads);
            int ans2=round(rr);
        printf("Case #%d: %d %d %d\n",f,ans,ans1,ans2);
    }
}
