#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf (int)1e18


int a[11000];

int b[4] = {1, 2, 5};


int dp[4][2002];

int calc(int id, int rem) {
   if(id >= 3) return inf;
   if(rem < 0) return inf;
   if(rem == 0) return 0;
   
   if(dp[id][rem] != -1) return dp[id][rem];

   int res = inf;
   res = min(res, calc(id, rem - b[id]) + 1);
   res = min(res, calc(id + 1, rem));
   
   return dp[id][rem] = res;
}


signed main() {

   int T;
   cin >> T;
   memset(dp, -1, sizeof dp);
   while( T -- ) {
      int n;
      cin >> n;
      for(int i = 0; i < n; i ++ ) {
         cin >> a[i];
         a[i] += 1000;
      }

      sort(a, a + n);
      int ans = inf;
      for(int tar = 0; tar <= a[0]; tar ++ ) {
         int res = 0;
         for(int i = 0; i < n; i ++ ) {
            res += calc(0, a[i] - tar);
         }
         ans = min(ans, res);
      }
      cout << ans << endl;
   }

   return 0;
}
