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
int main()
{ 
  int tst;
  scanf("%d",&tst);
  for(int r=1;r<=tst;r++){
  int n;
  scanf("%d",&n);
  char a[130];
  int c=0;
  scanf("%s",a);
  for(int i=0;i<n;i++){
      if(a[i]=='.'){
        a[i]=a[i+1]=a[i+2]='#';
        c++;
      }
  }
  printf("Case %d: %d\n",r,c);
}
}