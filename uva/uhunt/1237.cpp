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
   int T;
   scanf("%d",&T);
   for(int y=0;y<T;y++){
    if(y)printf("\n");
    int D;
    scanf("%d",&D);
    char nm[D][30];
    int L[D];
    int H[D];
    for(int i=0;i<D;i++)
    {
      scanf("%s %d %d",nm[i],&L[i],&H[i]);
    }
    int Q;
    scanf("%d",&Q);
    while(Q--){
      int count=0;
      string ans;
     int P;
     scanf("%d",&P);
     int x;
     for(int i=0;i<D;i++){
      if(L[i]<=P && P<=H[i]){count++;x=i;}
      if(count>1)break;
     }
     if(count==1)printf("%s\n",nm[x]);
     else printf("UNDETERMINED\n");
   }
 }
}
