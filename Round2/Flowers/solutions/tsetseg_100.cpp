// 100 avah bodolt

// O(NlogN + QlogN)

#include <bits/stdc++.h>
#define pb push_back
#define ff first
#define ss second
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int maxN = 100005;

int c[maxN];
pii st[4 * maxN];

// first deer ni max, second deer ni min
// hadgaldag segment tree

void build(int tl, int tr, int node){
   if (tl == tr){
      st[node] = {c[tl], c[tl]};
      return ;
   }
   int tm = (tl + tr) >> 1;
   build(tl, tm, node * 2 + 1);
   build(tm+1, tr, node * 2 + 2);
   st[node].ff = max(st[node * 2 + 1].ff, st[node * 2 + 2].ff);
   st[node].ss = min(st[node * 2 + 1].ss, st[node * 2 + 2].ss);
}

pii query(int ql, int qr, int tl, int tr, int node){
   if (ql <= tl && tr <= qr) return st[node];
   if (tl > qr || tr < ql) return {-1e9, 1e9};
   int tm = (tl + tr) >> 1;
   pii left = query(ql, qr, tl, tm, node * 2 + 1);
   pii right = query(ql, qr, tm+1, tr, node * 2 + 2);
   return {
      max(left.ff, right.ff),
      min(left.ss, right.ss)
   };
}

int main(){
   int n;
   cin >> n;
   for (int i = 0; i < n; i++){
      cin >> c[i];
   }
   build(0, n-1, 0);

   int q;
   cin >> q;
   while (q--){
      int l, r;
      cin >> l >> r;
      l--; r--;
      pii a = query(l, r, 0, n-1, 0);
      cout << a.ff - a.ss + 1 << '\n';
   }
}