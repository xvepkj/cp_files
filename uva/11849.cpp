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
set<int> tf;
int main () { 
   int n,m;
   while(true){
      tf.clear();
      scanf("%d %d",&n,&m);
      if((n+m)==0)break;
      int x;
      for(int i=0;i<n;i++){cin>>x;tf.insert(x);}
      int cnt=0;
      for(int i=0;i<m;i++)
      {
            scanf("%d",&x);
            if(tf.count(x)!=0)cnt++;
      }
      printf("%d\n",cnt);
   }
}


