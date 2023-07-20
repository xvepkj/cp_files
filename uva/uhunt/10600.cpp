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
int n,m,t,x,y,u,v,w;
bool ispart[10100];
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
#ifdef XVENOM
    freopen("inp.txt", "r", stdin);
    freopen("oup.txt", "w", stdout);
#endif
    scanf("%d",&t);
    while(t--){
        viii dax;
        memset(ispart,false,sizeof ispart);
        scanf("%d %d",&n,&m);
        for(int i=0;i<m;i++){
            scanf("%d %d %d",&x,&y,&w);
            dax.push_back(iii(w,ii(x-1,y-1)));
        }
        sort(dax.begin(),dax.end());
        UnionFind UF(n);
        int c=0;
        for(int i=0;i<m;i++){
        if(!UF.isSameSet(dax[i].second.first,dax[i].second.second))
        {
            UF.unionSet(dax[i].second.first,dax[i].second.second);
            c+=dax[i].first;
            ispart[i]=true;
        }
        }
        int c1=0;
        int minx =1e8;
        int cnt=0;
        for(int i=0;i<m;i++){
            c1=0;
            if(ispart[i]){
                UnionFind UF1(n);
                cnt=0;
                for(int j=0;j<m;j++){
                    if((!UF1.isSameSet(dax[j].second.first,dax[j].second.second)) && j!=i)
                    {
                        UF1.unionSet(dax[j].second.first,dax[j].second.second);
                        c1+=dax[j].first;
                        cnt++;
                    }
            }
            if(c1<minx && cnt==n-1)minx=c1;
        }
    }
    printf("%d %d\n",c,minx);
    }
}


