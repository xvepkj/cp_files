/*f(x,y):denotes cost till y where x is 0 or 1 acc to height 1 or 2
Now f[0][0]=b;(given)
f[1][0]=Not possible.
if(a[i-1]==1)f[0][i]=not possible as we know last gap had 1 so can't have 1 unit long pillar.
             f[1][i]=f[1][i-1]+a+2*b
Now if(a[i-1]==0)Then we have multiple choices
for f[1][i] -> 1.If it came from f[1][i-1] we add a+2*b(1 straight pipe two unit long pillar)
                2.If it came from f[0][i-1] we add  2*a+2*b(.5+.5 horizontal pipes+1 vertical +2 pillar)
                3.Take 1 & 2 minimum.
for f[0][i] ->1.If it came from f[1][i-1] we  add 2*a+b(.5+.5 horizontal pipes+1 vertical +1 pillar) 
              2.If it came from f[0][i-1] we add a+b(1 pillar 1 horz pipe)
              3.Take 1 & 2 minimum.

we know at end it is 0 so ans will be f[0][n]*/
#include <cstdio>
#include <cstring>
#include<iostream>
#include<stack>
#include <cassert>
#include <cmath>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <bitset>
#include <map>
#include <set>
using namespace std;
typedef long long int ll;
typedef vector< int > vi;
typedef pair< int, int > ii;
typedef vector< ii > vii;
typedef vector< ll > vll;
#ifdef XVENOM
    #define errp(...) fprintf(stderr, __VA_ARGS__)
#else
    #define errp(...)
#endif
#define dbg(x) errp("[%s = %s]\n", #x, to_string(x).data())
char s1[200100];
ll f[2][200100];
ll vlval=1e18;
int n,a,b;
int t;
int main() { 
#ifdef XVENOM
    freopen("inp.txt", "r", stdin);
    freopen("oup.txt", "w", stdout);
#endif
    scanf("%d",&n);   
    printf("%d\n",n);
}