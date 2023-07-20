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
   int t;
   scanf("%d",&t);
   while(t--){
      int n;
      scanf("%d",&n);
      int a[n];
      int tot=0;
      for(int i=0;i<n;i++)
      {
        scanf("%d",&a[i]);
        if(i>=1){
          for(int j=0;j<i;j++)
            if(a[j]<=a[i])tot++;
        }
      }
      printf("%d\n",tot);
   }
}
