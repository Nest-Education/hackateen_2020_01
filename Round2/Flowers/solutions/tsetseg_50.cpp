// 50 avah bodolt

// Shuud set ashiglaad bruteforce
// QNlogN

#include <bits/stdc++.h>
#define pb push_back
#define ff first
#define ss second
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int maxN = 100005;

int c[maxN];

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
      set<int> st;
      for (int i = l; i <= r; i++) st.insert(c[i]);
      cout << st.size() << '\n';
   }
}