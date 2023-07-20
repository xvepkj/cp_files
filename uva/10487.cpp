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
    int count=0;
   while(true){
    count++;
    int n;
    scanf("%d",&n);
    if(n==0)break;
    ll a[n];
    for(int i=0;i<n;i++)scanf("%lld",&a[i]);
    ll m;
    scanf("%lld",&m);
    printf("Case %d:\n",count);
    ll x;
    ll sum;
    ll ans;
    for(int r=0;r<m;r++){
      scanf("%lld",&x);
      ll mn=1e18;
      for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++)
        {  sum=a[i]+a[j];
          if(a[i]!=a[j])
            {
              if(abs(sum-x)<mn)
              {
                ans=sum;
                mn=abs(sum-x);
              }
            }
        }
      }
      printf("Closest sum to %lld is %lld.\n",x,ans);
    }
   }
}
