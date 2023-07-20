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
struct zeb{
  int per,tot,id;
};
struct comp{
bool operator()(zeb a,zeb b) const
{
  if(a.tot!=b.tot)return a.tot>b.tot;
  else return a.id>b.id;
}};
int main () { 
   zeb reg;
   priority_queue<zeb,vector<zeb>,comp> ha;
   char s[200];
   int id,tm;
   while(true)
   {
    scanf("%s",s);
    if(s[0]=='#')break;
    scanf("%d %d",&id,&tm);
    reg.id=id;reg.tot=tm;reg.per=tm;
    ha.push(reg);
   }
   int k;
   scanf("%d",&k);
  for(int i=0;i<k;i++)
  {
    printf("%d\n",ha.top().id);
    reg=ha.top();
    ha.pop();
    reg.tot+=reg.per;
    ha.push(reg);
  }
}
