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
int n;
  while(scanf("%d",&n),n)
{
  int sum=0;
  for(int i=0;i<n;i++){
    scanf("%d",&a[i]);
    sum+=a[i];
  }
  int x,y;
  for(int i=0;i<n;i++){
    if(a[i]!=0){x=i;break;}
  }
  for(int i=n-1;i>=0;i--){
    if(a[i]!=0){y=i;break;}
  }
  if(sum==0)puts("0");
  else {
    for(int i=x;i<y;i++)
      if(a[i]!=0)
      printf("%d ",a[i]);
    printf("%d\n",a[y]);
  }
}
}


