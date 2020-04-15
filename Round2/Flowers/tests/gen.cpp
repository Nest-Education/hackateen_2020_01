#include <bits/stdc++.h>

using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());


int main(){
   const int MAXN = 100000;
   const int MAXQ = 100000;

   int n;
   n = 1 + rng()%MAXN;
   n = 30;

   cout << n << '\n';

   vector<int> c(n + 1);
   c[1] = 1 + rng()%n;
   for (int i = 2; i <= n; i++){
      int delta = -1 + rng()%3;
      c[i] = c[i-1] + delta;
   }

   for (int i = 1; i <= n; i++) cout << c[i] << ((i == n) ? '\n' : ' ') ;

   int q;
   q = 1 + rng()%MAXQ;
   q = 20;
   
   cout << q << '\n';

   while (q--){
      int l = 1 + rng()%n;
      int r = l + rng()%(n - l + 1);
      cout << l << ' ' << r << '\n';
   }
}