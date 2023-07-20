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
int main () { 
   int k;
   while(cin>>k){
      vii ans;
      for(int i=k+1;i<=2*k;i++)
        if((k*i)%(i-k)==0)ans.push_back(ii((k*i)/(i-k),i));
      printf("%d\n",ans.size());
      for(int i=0;i<ans.size();i++)
      {
        printf("1/%d = 1/%d + 1/%d\n",k,ans[i].first,ans[i].second);
      }
   }
}
