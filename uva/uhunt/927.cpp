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
int main () { 
   int T;
    scanf("%d",&T);
   while(T--){
      int n;
      scanf("%d",&n);
      ll c[30];
      for(int i=0;i<=n;i++)scanf("%lld",&c[i]);
      ll d,k;
      scanf("%lld %lld",&d,&k);
      ll ans=0;
      ll sum=0;
      int i=0;
      while(true)
      { i++;
        sum+=(i*d);
        if(sum>=k)break;
      }
      for(int j=0;j<=n;j++)
      {
        ans+=c[j]*(ll)pow(i,j);
      }
      printf("%lld\n",ans);
   }
}
