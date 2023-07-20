#include<cstdio>
#include<iostream>
#include<cassert>
#include<cmath>
#include<random>
#include<vector>
#include<algorithm>
#include<cstdlib>
#include<set>
#include<cstring>
#include<string>
#include<utility>
#include<queue>
#include<stack>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii; 
typedef vector<ii> vii;
typedef vector<int> vi;
#define INF 1000000000 
typedef vector<int> vi;
int n,m;
vi res;
#define DEBUG_MODE
#ifdef DEBUG_MODE
    #define errp(...) fprintf(stderr, __VA_ARGS__)
    #define dbg(x) fprintf(stderr, "[%s = %d]\n", #x, x)
#else
    #define errp(...)
    #define dbg(x) 
#endif
int a[1100];
int b[1100];
int main()
{ 
  int n,d,r;
  while(scanf("%d %d %d",&n,&d,&r)==3,(n+d+r)){
    for(int i=0;i<n;i++)scanf("%d",&a[i]);
    for(int i=0;i<n;i++)scanf("%d",&b[i]);
    sort(a,a+n);
    sort(b,b+n);
    reverse(b,b+n);
    int sum=0;
    for(int i=0;i<n;i++)
    {
      if(d<(a[i]+b[i]))
        sum+=(a[i]+b[i])-d;
    }      
    printf("%d\n",sum*r); 
  }
}