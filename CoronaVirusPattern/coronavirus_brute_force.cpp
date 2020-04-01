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

int main() {
	string a;
    long long ans = 0;
	cin >> a;

	for (int i = 0; i < a.size(); i++) {
        int count[10] = {0};
        for (int j = i; j < a.size(); j++) {
            int x = (a[j] - '0');
            count[x] ++;

            x = 1;
            for (int y = 0; y < 10; y++) {
                if (count[y] % 2 == 1) {
                    x = 0;
                }
            }
            ans += x;
        }
	}

    cout << ans << endl;

    return 0;
}
