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
using namespace std;
typedef long long int ll;
typedef vector< int > vi;
typedef pair< int, int > ii;
typedef vector< ii > vii;
typedef vector< ll > vll;
//#define DEBUG_MODE
#ifdef DEBUG_MODE
    #define errp(...) fprintf(stderr, __VA_ARGS__)
    #define dbg(x) fprintf(stderr, "[%s = %d]\n", #x, x)
#else
    #define errp(...)
    #define dbg(x) 
#endif
multiset<int> cst;
int main () { 
   vii reg;
   string s;
   int id,tm;
   while(true)
   {
    scanf("%s %d %d",s,&id,&tm);
    if(s[0]=='#')break;
    reg.push_back(ii(tm,id));
   }
   sort(reg.begin(),reg.end());
   int k;
   scanf("%d",&k);
   int n=reg.size();
   for(int i=0,c=0;c<k;i++,c++)
   {
    if(i==n-1)i=0;
    printf("%d\n",reg[i].second);
   }
}
