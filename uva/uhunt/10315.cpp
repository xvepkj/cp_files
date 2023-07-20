/*PKJ*/
#define DEBUG_MODE
#include <cstdio>
#include <cstring>
#include<iostream>
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
#ifdef DEBUG_MODE
    #define errp(...) fprintf(stderr, __VA_ARGS__)
#else
    #define errp(...)
#endif
#define dbg(x) errp("[%s = %s]\n", #x, to_string(x).data())
int a[200000];
int f[150001];
int main() { 
#ifdef DEBUG_MODE
    freopen("inp.txt", "r", stdin);
    freopen("oup.txt", "w", stdout);
#endif
    set<int> x;
    int n;
    scanf("%d",&n);
    memset(f,0,sizeof f);
    for(int i=0;i<n;i++){scanf("%d",&a[i]);f[a[i]]++;}
    for(int i=1;i<=150000;i++){
    	if(f[i]==1){x.insert(i);f[i]==0;}
    }
    for(int i=1;i<=150000;i++){
    	if(f[i]>0 && x.count(i)==0){x.insert(i);f[i]--;}
    	if(f[i]>0){if(i!=1 && x.count(i-1)==0){x.insert(i-1);f[i]--;}}
    	if(f[i]>0){if(x.count(i+1)==0){x.insert(i+1);f[i]--;}}
    }
    printf("%d\n",x.size());
}