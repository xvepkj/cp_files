#include <cstdio>
#include<iostream>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include<queue>
using namespace std;
typedef long long int ll;
typedef vector< int > vi;
typedef pair< int, int > ii;
typedef vector< ii > vii;
typedef vector< ll > vll;
//#define DEBUG_MODE
#ifdef DEBUG_MODE
    #define errp(...) fprintf(stderr, __VA_ARGS__)
    #define dbg(x) fprintf(stderr, "[%s = %d]\n", #x, x)
#else
    #define errp(...)
    #define dbg(x) 
#endif
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
int main () { 
   int t;
   scanf("%d",&t);
    
   while(t--){
     map<string,int> m;
    int n;
    UnionFind x(2*n+1);
     int l=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
    char s[30],e[30];
    scanf("%s %s",&s,&e);
    if(m.count(s)==0)m[s]=++l;
    if(m.count(e)==0)m[e]=++l;
    if(x.isSameSet(m[s],m[e]))printf("%d\n",x.sizeOfSet(m[s]));
    else printf("%d\n",x.sizeOfSet(m[s])+x.sizeOfSet(m[e]));
    x.unionSet(m[s],m[e]);
    }
   }
}
