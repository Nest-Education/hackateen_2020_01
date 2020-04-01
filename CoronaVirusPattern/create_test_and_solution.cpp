#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <string>
#include <cmath>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <time.h>

#define xx first
#define yy second
#define mp make_pair
#define pb push_back
#define mod 1000000007ll
#define LL long long

using namespace std;

string _input, _output;

void solve(){
	int count[1<<10] = {0};
	long long ans = 0;
	int s = 0;

	string a;

	cin >> a;

	count[0] = 1;
	for (int i = 0; i < a.size(); i++) {
		int x = (a[i] - '0');
		s ^= 1<<x;

		ans += count[s];

		count[s] ++;
	}

	cout << ans << endl;
}

void test(int n){
	int m;
	if (n < 3) {
		m = 1000;
	} else if (n < 6) {
		m = 10000;
	} else {
		m = 10000000;
	}

	for (int i = 0; i < m; i++) {
		cout << ('0' + rand() % 10);
	}
	cout << endl;
}

int main() {
  int ANS[105] = {0};

  srand(time(NULL));

  for (int I = 0; I < 10; I++) {
    _input = "input/input";
    _input += char('0' + I / 10);
    _input += char('0' + I % 10);
    _input += ".txt";
    _output = "output/output";
    _output += char('0' + I / 10);
    _output += char('0' + I % 10);
    _output += ".txt";

    freopen(_input.c_str(), "w", stdout);

    test(I);

    freopen(_input.c_str(), "r", stdin);
    freopen(_output.c_str(), "w", stdout);

    solve();
  }

  return 0;
}
