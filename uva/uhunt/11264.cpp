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
int main()
{ 
  int tst;
  scanf("%d",&tst);
  for(int y=0;y<tst;y++){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)scanf("%d",&a[i]);
    int sum=1;
    int c;
    if(n>1)c=2;
    else c=1;
    for(int i=1;i<n-1;i++){
      if(sum+a[i]<a[i+1]){
        sum=sum+a[i];
        c++;
      }
    }
    printf("%d\n",c);
  }
}