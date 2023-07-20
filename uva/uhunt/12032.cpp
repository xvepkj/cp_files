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
int a[100100];
int main()
{ 
  int tst;
  scanf("%d",&tst);
  for(int y=1;y<=tst;y++){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    a[0]=0;
    int k=0;
    for(int i=1;i<=n;i++)k=max(k,a[i]-a[i-1]);
    int u=k;
    for(int i=1;i<=n;i++){
      if(k==(a[i]-a[i-1]))k--;
      else if(k<(a[i]-a[i-1])){u++;break;}
    }
    printf("Case %d: %d\n",y,u);
  }
}