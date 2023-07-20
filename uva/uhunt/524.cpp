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
bool prime[1000];
int n;
int ans[100];
bool taken[1000];
void soe(int m){
      for(int i=2;i<=m;i++)
        prime[i]=true;
        int x=(int)sqrt(m);
      for(int i=2;i<=x;i++)
      {
        if(prime[i]){
          for(int j=i*i;j<=m;j+=i)
            prime[j]=false;
        }
      }
}
void cir(int x){
  if(x==n+1){
    if(prime[ans[n]+1]){
      for(int i=1;i<=n;i++)
        {
          if(i==n)printf("%d",ans[i]);
          else printf("%d ",ans[i]);
                            }
        printf("\n");
    }
  }
  for(int i=2;i<=n;i++)
  {
    if(prime[ans[x-1]+i] && !taken[i])
    {
      if(x==n+1)
      ans[x]=i;
      taken[i]=true;
      cir(x+1);
      taken[i]=false;
    }
  }
}
int main () { 
   soe(1000);
   ans[1]=1;
   int i=0;
   while(scanf("%d",&n)==1)
   {  
      if(i)printf("\n");
      i++;
      printf("Case %d:\n",i);
      cir(2);
   }
}


