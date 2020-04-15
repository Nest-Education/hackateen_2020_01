#include <bits/stdc++.h>
#define pb push_back
#define ff first
#define ss second
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int maxN = 100005;

int c[maxN];
bool vis[maxN];

int main(){
   int n;
   cin >> n;
   for (int i = 0; i < n; i++){
      cin >> c[i];
   }

   int q;
   cin >> q;
   while (q--){
      int l, r;
      cin >> l >> r;
      l--; r--;
      memset(vis, 0, sizeof vis);
      int cnt = 0;
      for (int i = l; i <= r; i++) {
         if (!vis[c[i]]){
            vis[c[i]] = 1;
            cnt++;
         }
      }
      cout << cnt << '\n';
   }
}