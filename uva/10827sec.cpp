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
ll A[1000][1000];
int main() {
    int tst;
    scanf("%lld",&tst);
    for(ll t=1;t<=tst;t++){
    ll n,m,k;
    scanf("%lld %lld %lld",&n,&m,&k);
    for(int i=0;i<n;i++)
      for(int j=0;j<m;j++)
        {scanf("%lld",&A[i][j]);
      if(i>0)A[i][j]+=A[i-1][j];}
    ll mxy=-1e15;
    ll sub=0;
    ll x=0;
    for(int i=0;i<n;i++)for(int j=i;j<n;j++)
    {
      sub=0;
      x=0;
    for(int c=0;c<n;c++){
      sub+=A[j][c];
      if(i>0)sub-=A[i-1][c];
      if(sub<0){sub=0;x=c;}
    }}
    printf("%lld\n", );
  }
}
