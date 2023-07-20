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
// #define DEBUG_MODE
#ifdef DEBUG_MODE
    #define errp(...) fprintf(stderr, __VA_ARGS__)
    #define dbg(x) fprintf(stderr, "[%s = %d]\n", #x, x)
#else
    #define errp(...)
    #define dbg(x) 
#endif

int main () { 
   int n;
   while(true)
   {
      scanf("%d",&n);
      if(n==0)break;
      map<string,int> frosh;
      int maxx=-1;
      string x[5];
      for(int i=0;i<n;i++)
      {     string s;
            cin>>x[0]>>x[1]>>x[2]>>x[3]>>x[4]>>x[5];
            for(int j=0;j<5;j++)s+=x[j];
            frosh[s]++;
            int x=frosh[s];
            maxx=max(x,maxx);
      }
      int count=0;
      map<string,int>::iterator it;
      for(it=frosh.begin();it!=frosh.end();it++)
            if(it->second==maxx)count+=it->second;
      printf("%d\n",count);
   }
}


