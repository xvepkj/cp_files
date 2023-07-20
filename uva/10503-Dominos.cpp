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
vii x;
bool taken[20];
int l1,l2,r1,r2;
int n;
int m;
bool tog=false; 
void solve(int y,int c){
    if(c==n){
      if(y==r1)tog=true;
      return;
    }
    for(int i=0;i<m;i++)
    {
      if(x[i].second == y && !taken[i]){taken[i]=true;solve(x[i].first,c+1);taken[i]=false;}
      if(x[i].first == y && !taken[i]){taken[i]=true;solve(x[i].second,c+1);taken[i]=false;}
    }
}
int main () { 
  for(int i=0;i<20;i++)taken[i]=false;
  while(scanf("%d",&n)==1){
    if(n==0)break;
    tog=false;
    x.clear();
    scanf("%d",&m);
    scanf("%d %d",&l1,&l2);
    scanf("%d %d",&r1,&r2);
    int a,b;
    for(int i=0;i<m;i++){
      scanf("%d %d",&a,&b);
      x.push_back(ii(a,b));
    }
    solve(l2,0);
    if(tog)printf("YES\n");
    else printf("NO\n");
  }
}


