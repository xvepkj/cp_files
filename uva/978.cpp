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
#define DEBUG_MODE
#ifdef DEBUG_MODE
    #define errp(...) fprintf(stderr, __VA_ARGS__)
    #define dbg(x) fprintf(stderr, "[%s = %d]\n", #x, x)
#else
    #define errp(...)
    #define dbg(x) 
#endif
int main () { 
   int tst;
   scanf("%d",&tst);
   for(int m=0;m<tst;m++)
   {  multiset<int,greater<int>> b,g;
      if(m)printf("\n");
      int n,sg,sb;
      scanf("%d %d %d",&n,&sg,&sb);
      vi rg,rb;
      int x;
      for(int i=0;i<sg;i++){scanf("%d",&x);g.insert(x);}
      for(int i=0;i<sb;i++){scanf("%d",&x);b.insert(x);}
      while(!b.empty() && !g.empty())
      {
            multiset<int,greater<int>>::iterator git=g.begin(),bit=b.begin();
            for(int i=0;i<n && git!=g.end() && bit!=b.end();i++)
            {     
                  if(*bit>*git)
                        rb.push_back(*bit-*git);
                  else if(*git>*bit) rg.push_back(*git-*bit);
                  multiset<int,greater<int>>::iterator git2=git,bit2=bit;
                  git++;bit++;
                  b.erase(bit2);g.erase(git2);
            }
            for(int i=0;i<rg.size();i++)
                  g.insert(rg[i]);
            for(int i=0;i<rb.size();i++)
                  b.insert(rb[i]);
            rg.clear();
            rb.clear();
      }
      if(g.size()==0 && b.size()==0)printf("green and blue died\n");
      else {
            if(g.size()>0)
            {     printf("green wins\n");
                  for(multiset<int,greater<int>>::iterator it=g.begin();it!=g.end();it++)
                        printf("%d\n",*it);
            }
            else{
                  printf("blue wins\n");
                  for(multiset<int,greater<int>>::iterator it=b.begin();it!=b.end();it++)
                        printf("%d\n",*it);
            }
      }
   }
}


