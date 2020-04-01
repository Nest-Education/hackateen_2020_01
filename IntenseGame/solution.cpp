#include <iostream>

using namespace std;

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

int main() {
	solve();
	return 0;
}