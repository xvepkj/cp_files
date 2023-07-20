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
#include<bitset>
using namespace std;
typedef long long int ll;
typedef vector< int > vi;
typedef pair< int, int > ii;
typedef vector< ii > vii;
typedef vector< ll > vll;
#define DEBUG_MODE
#ifdef DEBUG_MODE
    #define errp(...) fprintf(stderr, __VA_ARGS__)
    #define dbg(x) fprintf(stderr, "[%s = %d]\n", #x, x)
#else
    #define errp(...)
    #define dbg(x) 
#endif
int main () { 
   int n,m;
   while(scanf("%d %d",&n,&m)!=EOF){
      vector<vi> occ;
      occ.assign(1000001,vi());
      int a[n+1];
      for(int i=1;i<n+1;i++)scanf("%d",&a[i]);
      for(int i=1;i<n+1;i++){
         occ[a[i]].push_back(i);
      }
      for(int i=0;i<m;i++)
      {
         int k,v;
         scanf("%d %d",&k,&v);
         if(k<=occ[v].size())
         printf("%d\n",occ[v][k-1]);
      else printf("%d\n",0);
      }
   }
}

