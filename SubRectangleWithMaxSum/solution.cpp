#include<iostream>
#include<cstring>
#include<algorithm>

#define maxn 400+5

using namespace std;

int N, m[maxn][maxn], x[maxn];

int find_max() {
	int cur_sum=x[0], sum=0;
	for (int l = 0; l < N; l++) {
		sum += x[l];
		cur_sum = max(sum, cur_sum);
		if (sum < 0) sum = 0;
	}
	return cur_sum;
}

void solve(){
	int MaxSum = -200;
	for (int i = 0; i < N; i++) {
		memset(x, 0, sizeof(x));
		for (int j = i; j < N; j++) {
			for (int k = 0; k < N; k++)
                x[k] += m[j][k];
			MaxSum = max(MaxSum, find_max());
		}
	}
	cout << MaxSum << endl;
}

int main() {

	while (cin >> N) {
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				cin >> m[i][j];
		solve();
	}

	return 0;
}
