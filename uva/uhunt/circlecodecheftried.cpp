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
double x1,x2,y1,y2,r1,r2;
int t;
int main() { 
#ifdef DEBUG_MODE
    freopen("inp.txt", "r", stdin);
    freopen("oup.txt", "w", stdout);
#endif
   scanf("%d",&t);
   while(t--){
    scanf("%lf %lf %lf %lf %lf %lf",&x1,&y1,&r1,&x2,&y2,&r2);
    vii pts;
    double ans1,ans2;
    pts.push_back(ii(x1+r1,y1));
    pts.push_back(ii(x1,y1+r1));
    pts.push_back(ii(x1,y1-r1));
    pts.push_back(ii(x1-r1,y1));
    bool ispos=false;
    for(int i=0;i<4;i++)errp("%d %d\n",pts[i].first,pts[i].second);
    for(int i=0;i<4;i++){
        double a=(pts[i].first-x2)*(pts[i].first-x2);
        double b=(pts[i].second-y2)*(pts[i].second-y2);
        double d=sqrt(a+b);
        dbg(d);
        if(d>r2){
            ispos=true;
            ans1=pts[i].first;
            ans2=pts[i].second;
        }
    }
    if(ispos){printf("YES\n");printf("%.7f %.7f\n",ans1,ans2);}
    else printf("NO\n");
}
}