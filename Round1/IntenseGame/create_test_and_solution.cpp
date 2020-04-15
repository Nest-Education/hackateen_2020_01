#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <time.h>


using namespace std;

string _input, _output;

void solve(){
	int T, n;

	int fib[50], f;
	fib[0] = 1;
	fib[1] = 1;
	for(int i = 2; i < 50; i++) {
		if (fib[i - 1] + fib[i - 2] <= 100000000) {
			fib[i] = fib[i - 1] + fib[i - 2];
			f = i;
		} else {
			break;
		}
	}
	cin >> T;
	while(T--) {
		cin >> n;
		if(n == 1) {
			cout << "FIRST" << endl;
			continue;
		}
		bool ok = true;
		for(int i = 0; i <= f; i++) {
			if(n == fib[i]) {
				ok = false;
			}
		}
		if(ok) {
			cout << "FIRST" << endl;
		} else {
			cout << "SECOND" << endl;
		}
	}
}

void test(int n){
	int fib[50], f;
	fib[0] = 1;
	fib[1] = 1;
	for(int i = 2; i < 50; i++) {
		if (fib[i - 1] + fib[i - 2] <= 100000000) {
			fib[i] = fib[i - 1] + fib[i - 2];
			f = i;
		} else {
			break;
		}
	}

	int m, T, tm;
	if (n < 2) {
		m = 100 - 1;
		f = 12;
	} else if (n < 5) {
		m = 100000 - 1;
		f = 25;
	} else {
		m = 100000000 - 1;
		f ++;
	}

	T = 8 + rand() % 3;
	cout << T << endl;

	for (int i = 0; i < T; i++) {
		if (rand() % 3) {
			cout << 1 + (rand() % m) << endl;
		} else {
			cout << fib[rand() % f] << endl;
		}
	}
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
