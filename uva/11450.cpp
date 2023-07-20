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
int price[25][25];
bool rc[25][220];        
int main () { 
    int tst;
    scanf("%d",&tst);
    while(tst--){
      int M,C;
      scanf("%d %d",&M,&C);
      for(int g=0;g<C;g++){
        scanf("%d",&price[g][0]);
        for(int i=1;i<=price[g][0];i++)
          scanf("%d",&price[g][i]);
      }
      memset(rc,false,sizeof rc);
      for(int i=1;i<=price[0][0];i++){
        if(M-price[0][i]>=0)
          rc[0][M-price[0][i]]=true;
      }
      for(int g=1;g<C;g++){
        for(int mo=0;mo<M;mo++){
          if(rc[g-1][mo])
            for(int k=1;k<=price[g][0];k++)
              if(mo-price[g][k]>=0)
                rc[g][mo-price[g][k]]=true;
        }
      }
      int i;
      for(i=0;i<=M && !rc[C-1][i];i++);
        if(i==(M+1))printf("no solution\n");
          else printf("%d\n",M-i);
    }
}



