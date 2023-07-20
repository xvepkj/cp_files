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
multiset<int> cst;
int main () { 
   int n;
   while(true){
      scanf("%d",&n);
      if(n==0)break;
      int k;
      long long sum=0;
      cst.clear();
      for (int i = 0; i < n; ++i)
      {
         scanf("%d",&k);
         for(int j=0;j<k;j++){
            int x;scanf("%d",&x);
            cst.insert(x);
         }
         multiset<int>::iterator ib=cst.begin();
         multiset<int>::iterator ie=cst.end();
         ie--;
         sum+=*ie-*ib;
         cst.erase(ie);cst.erase(ib);
      }
      printf("%lld\n",sum);
   }
   
}
