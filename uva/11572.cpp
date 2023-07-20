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
// #define DEBUG_MODE
#ifdef DEBUG_MODE
    #define errp(...) fprintf(stderr, __VA_ARGS__)
    #define dbg(x) fprintf(stderr, "[%s = %d]\n", #x, x)
#else
    #define errp(...)
    #define dbg(x) 
#endif
map<int,int> killme;
int main () { 
   int t;
   scanf("%d",&t);
   while(t--)
   {
      int n;
      scanf("%d",&n);
      killme.clear();
      int x;
      int maxx=1,cursum=0;
      for(int i=0;i<n;i++)
      {
        scanf("%d",&x);
        cursum++;
        if(killme.count(x)>0){map<int,int>:: iterator it=killme.find(x);
        killme.begin()=++it;
        maxx=max(maxx,cursum);
        cursum-=(killme[x]+1);
        }
        killme[x]=i;
      }
      printf("%d\n",maxx);
   }
}


