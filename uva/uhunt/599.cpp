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
   int tst;
   scanf("%d",&tst);
   for(int t=0;t<tst;t++){
      bitset<26> frien;
      char s[50];
      int e=0;
      while(true){
         scanf("%s",s);
         if(s[0]!='(')break;
         e++;
         int x=s[1]-65;
         int y=s[3]-65;
         frien.set(x,1);
         frien.set(y,1);
      }
      scanf("%s",s);
      int v=(strlen(s)/2)+1;
      int tot=v-e;
      int ac=0;
      for(int i=0;i<strlen(s);i+=2)
      {
         int z=s[i]-65;
         if(!frien.test(z))ac++;
      }
      int tr=tot-ac;
      printf("There are %d tree(s) and %d acorn(s).\n",tr,ac);
   }
}


