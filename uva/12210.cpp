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
int b[100100];
int s[100100];
int main () { 
int t=0;
  while(true)
{
  t++;
  int n,m;
  scanf("%d %d",&n,&m);
  if((n+m)==0)break;
  int minx=100;
  for(int i=0;i<n;i++){
    scanf("%d",&b[i]);
    minx=min(b[i],minx);
  }
  for(int i=0;i<m;i++)scanf("%d",&s[i]);
  if(n<=m)printf("Case %d: 0\n",t);
  else printf("Case %d: %d %d\n",t,n-m,minx);
}
}


