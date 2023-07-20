#include <cstdio>
#include<iostream>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
#include<stack>
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
#define isOn(S, j) (S & (1 << j))
#define DEBUG_MODE
#ifdef DEBUG_MODE
    #define errp(...) fprintf(stderr, __VA_ARGS__)
    #define dbg(x) fprintf(stderr, "[%s = %d]\n", #x, x)
#else
    #define errp(...)
    #define dbg(x) 
#endif
int a[100100];
int main () { 
ll n,u,l;
while(scanf("%lld %lld %lld",&n,&l,&u)!=EOF){
 ll ans=0;
 for(ll i=31;i>=0;i--){
  if(n&(1LL<<i)){
    ll y=ans+(1LL<<i);



    
    if(y<=l){
      ans+=(1LL<<i);
    }
  }
  else{
    ll x=ans+(1LL<<i);
    if(x<=u){
      ans+=(1LL<<i);
    }
  }
 }
 printf("%lld\n",ans);
}
}


