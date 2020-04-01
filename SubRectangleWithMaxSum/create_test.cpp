#include<iostream>
#include<cstring>
#include<algorithm>
#include<time.h>

#define maxn 400+5

using namespace std;

string _input, _output;
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

void test(int n){
	int m[10] = {1, 4, 10, 30, 50, 100, 200, 250, 300, 400};

	cout << m[n] <<endl;
	for (int i = 0; i < m[n]; i++) {
        for (int j = 0; j < m[n]; j++)
            cout << rand() % 255 - 127 << " ";
        cout << endl;
	}
}

int main() {
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

		cin >> N;
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				cin >> m[i][j];
		solve();
	}

	return 0;
}
