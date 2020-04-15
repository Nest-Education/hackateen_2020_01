#include<iostream>
#include<cstring>
#include<set>
#include<string>
#include<vector>
#include<algorithm>
#include<time.h>

#define maxStrLen 1000000
#define maxQ 3500
#define maxSubStrLen 100

using namespace std;

string _input, _output;
int x;

void solve() {
	vector <int> vec[52];
	vector <int> ::iterator it;
	string str;
	int q;

	cin>>str;
	for (int i=0; i<str.size(); i++){
		if (str[i]>='a') x=str[i]-'a';
		else x=str[i]-'A'+26;
		vec[x].push_back(i);
	}
	for (int i=0; i<52; i++)
		sort(vec[i].begin(),vec[i].end());

	cin>>q;
	while (q--){
		cin>>str;
		int st=-1;
		bool check=1;
		for (int i=0; i<str.size() && check; i++){
			if (str[i]>='a') x=str[i]-'a';
			else x=str[i]-'A'+26;
			it=upper_bound(vec[x].begin(),vec[x].end(),st);
			if (it==vec[x].end()) check=0;
			else st=*it;
		}

		if (check) cout << "Yes" << endl;
		else cout << "No" << endl;
	}
}

string createStr1(int n) {
	string subStr;

	for (int i=0; i<n; i++) {
		x = rand() % 52;
		if (x<26) x += 'a';
		else  x += 'A' - 26;
		subStr.push_back(x);
	}

	return subStr;
}

string createStr2(string str, int n) {
	string subStr;

	for (int i=0; i<n; i++) {
		x = rand() % str.size();
		subStr.push_back(str[x]);
	}

	return subStr;
}

string createStr3(string str, int n) {
	set<int> s;
	set<int>::iterator it;
	string subStr;

	for (int i=0; i<n; i++) {
		x = rand() % str.size();
		s.insert(x);
	}

	for (it=s.begin(); it!=s.end(); ++it)
		subStr.push_back(str[*it]);

	return subStr;
}

void test(int n){
	int strLen = 5<<n;
	int Q[20] ={10, 10, 10, 20, 50, 100, 250, 500, 800, 1000,
				1200, 1500, 2000, 3000, 3100, 3200, 3300, 3400, 3450, 3500};
	string str;
	int m;

	if (strLen > maxStrLen) strLen = maxStrLen;
	while(1) {
		x = rand() % 52;
		if (x<26) x += 'a';
		else  x += 'A' - 26;
		int y = rand() % (strLen / 1000 + 1) + 1;
		while (y && str.size()<strLen){
			str.push_back(x);
			y--;
		}
		if (str.size() == strLen) break;
	}

	cout << str << endl;
	cout << Q[n] <<endl;
	for (int i = 0; i < Q[n]; i++) {
		if (strLen > 150) m = rand() % 150 + 1;
		else m = rand() % strLen + 1;
		if (m > maxSubStrLen) m = maxSubStrLen;

		x = rand() % 3;
		if (x == 0) cout << createStr1(m) << endl;
		else if (x == 1) cout << createStr2(str, m) << endl;
		else cout << createStr3(str, m) << endl;
	}
}

int main() {
	srand(time(NULL));

	for (int I = 0; I < 20; I++) {
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
