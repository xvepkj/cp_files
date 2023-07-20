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
int b[100100];
int main () { 
  int n,m;
  while(scanf("%d %d",&n,&m),(n+m)){
    for(int i=0;i<n;i++)scanf("%d",&a[i]);
    for(int i=0;i<m;i++)scanf("%d",&b[i]);
    if(n>m)printf("Loowater is doomed!\n");
    else {
      sort(a,a+n);
      sort(b,b+m);
      int j=0;
      int i=0;
      int gc=0;
      bool flg=true;
      while(i<n && j<m){
        while(b[j]<a[i])j++;
        gc+=b[j];
        i++;j++;
      }
      if(i==n)printf("%d\n",gc);
      else printf("Loowater is doomed!\n");
    }
  }
}


