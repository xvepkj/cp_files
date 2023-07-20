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
    map<string,int> tr;
    int testcase;
    string s1;
    scanf("%d",&testcase);
    getline(cin,s1);
    getline(cin,s1);
    for(int h=0;h<testcase;h++)
    {
      if(h)printf("\n");
      tr.clear();
      string s;
      long sum=0;
      while(getline(cin,s))
      {      if(s.compare("") == 0)
                        break;
            tr[s]++;
            sum++;
      }
      map<string, int>::iterator it = tr.begin();
       for (it; it != tr.end(); it++)
    printf("%s %0.4f\n", ((string)it->first).c_str(),(double)it->second/(double)sum*100.0);
    }
}


