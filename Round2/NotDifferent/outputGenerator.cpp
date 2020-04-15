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
   
  ifstream fin;
  ofstream fout;
  int testNo = 0;
  string inputRoot = "input_";
  string outRoot = "output_";
  string nums[20] = {"01", "02", "03", "04", "05", "06", "07", "08", "09", "10", "11", "12", "13", "14", "15"};

  while (testNo < 15) {
    string fileName = outRoot + nums[testNo] + ".txt";
    fout.open(fileName);
    fileName = inputRoot + nums[testNo] + ".txt";
    fin.open(fileName);

   int T;
   fin >> T;
   memset(dp, -1, sizeof dp);
   while( T -- ) {
      int n;
      fin >> n;
      for(int i = 0; i < n; i ++ ) {
         fin >> a[i];
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
      fout << ans << endl;
   }
   fout.close();
   fin.close();
   testNo ++;
  }
   return 0;
}