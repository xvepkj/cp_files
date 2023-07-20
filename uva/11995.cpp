#include <cstdio>
#include<iostream>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include<stack>
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
   int n;
   while(scanf("%d",&n)!=EOF)
   {  stack<int> S;
      queue<int> Q;
      priority_queue<int> PQ;
      bool isQ=true,isS=true,isPQ=true;
      for(int z=0;z<n;z++)
      {  int op,x;
         scanf("%d %d",&op,&x);
         if(op==1)
         {
            if(isS==true)S.push(x);
            if(isQ==true)Q.push(x);
            if(isPQ==true)PQ.push(x);
         }
         if(op==2)
         {
            if(isS==true){
               if(S.empty() || S.top()!=x)
                  isS=false;
               else S.pop();
            }
            if(isQ==true){
               if(Q.empty() || Q.front()!=x)
                  isQ=false;
               else Q.pop();
            }
            if(isPQ==true){
               if(PQ.empty() || PQ.top()!=x)
                  isPQ=false;
               else PQ.pop();
            }
         }
      }
      if(isQ==true && isS==false && isPQ==false)printf("queue\n");
      else if(isQ==false && isS==true && isPQ==false)printf("stack\n");
      else if(isQ==false && isS==false && isPQ==true)printf("priority queue\n");
      else if(isQ==false && isS==false && isPQ==false)printf("impossible\n");
      else printf("not sure\n");
   }
}


