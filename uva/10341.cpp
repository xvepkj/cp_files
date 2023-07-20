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
#define EPS 1e-7
typedef vector<int> vi;
int n,m;
vi res;
int c[100010];
int d[100010],f[100010],b[100010];
int e[100010];
int tle[100010];
#define DEBUG_MODE
#ifdef DEBUG_MODE
    #define errp(...) fprintf(stderr, __VA_ARGS__)
    #define dbg(x) fprintf(stderr, "[%s = %d]\n", #x, x)
#else
    #define errp(...)
    #define dbg(x) 
#endif
int p,q,r,s,t,u;
double fx(double x){
  return (p*exp(-x))+(q*sin(x))+(r*cos(x))+(s*tan(x))+(t*x*x)+u;
}
double bisection(){
  double lo = 0, hi = 1;
  for(int i=0;i<30;i++){
    double x = (lo+hi)/2;
    if(fx(x)>0)lo=x;
    else hi=x;}
  return (lo+hi)/2;
}
int main()
{ 
  while(scanf("%d %d %d %d %d %d",&p,&q,&r,&s,&t,&u)!=EOF){
    if((fx(0)*fx(1))>0)puts("No solution");
    else {     
      printf("%.4lf\n",bisection());
    }
  }
}