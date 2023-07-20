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
int a[15];
int t,n;
int l=0;
vi res;
set<vi> ans;
void sum(int lef,int j){
  if(lef==0){
      ans.insert(res);
      return;
  }
    if(j==n)return;
      if(a[j]<=lef){
        lef-=a[j];
        res.push_back(a[j]);
        sum(lef,j+1);
        res.pop_back();
        lef+=a[j];
      }
      sum(lef,j+1);
}
int main () { 
   while(scanf("%d %d",&t,&n)==2){
    l=0;
    if((t+n)==0)break;
    ans.clear();
    for(int i=0;i<n;i++)scanf("%d",&a[i]);
    sort(a,a+n);
    reverse(a,a+n);
    printf("Sums of %d:\n",t);
    sum(t,0);
    if(!ans.size())printf("NONE\n");
    else {
      for(auto it=ans.rbegin();it!=ans.rend();it++)
      {
        for(auto ix=(*it).begin();ix!=(*it).end();ix++)
          if(ix==(*it).end()-1)printf("%d\n",*ix);
          else printf("%d+",*ix);
      }
    }
   }
}


