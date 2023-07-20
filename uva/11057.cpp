#include <cstdio>
#include<iostream>
#include <cstring>
#include<cstdlib>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include<queue>
#include<bitset>
using namespace std;
typedef long long int ll;
typedef vector< int > vi;
typedef pair< int, int > ii;
typedef vector< ii > vii;
typedef vector< ll > vll;
#define DEBUG_MODE
#ifdef DEBUG_MODE
    #define errp(...) fprintf(stderr, __VA_ARGS__)
    #define dbg(x) fprintf(stderr, "[%s = %d]\n", #x, x)
#else
    #define errp(...)
    #define dbg(x) 
#endif
int main () { 
  int n;
  while(scanf("%d",&n)==1){
  	vi r;
  	int t;
  	int u=0;
  	for(int i=0;i<n;i++){scanf("%d",&t);r.push_back(t);}
  	int x;
  	scanf("%d",&x);
  	bool flg=false;
  	if(x%2==0){
  		for(int i=0;i<n;i++)
  			if(r[i]==(x/2))u++;
  		if(u>1){printf("Peter should buy books whose prices are %d and %d.\n",x/2,x/2);flg=true;}
  	}
  	if(flg==false){
      sort(r.begin(),r.end());
      int minx=x+1;
      int ans[2];
    for(int i=0;i<n && flg!=true;i++)
    {
    if(binary_search(r.begin(),r.end(),x-r[i]))
    {
        if(abs(x-(2*r[i]))<minx)
        {
          ans[0]=r[i];
          ans[1]=x-r[i];
          minx=abs(x-(2*r[i]));
        }
    }
  }
  sort(ans,ans+2);
  printf("Peter should buy books whose prices are %d and %d.\n",ans[0],ans[1]);
  	}
  	printf("\n");
  }
}
