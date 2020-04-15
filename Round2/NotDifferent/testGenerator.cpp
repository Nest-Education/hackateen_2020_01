#include <bits/stdc++.h>
#include <fstream>
using namespace std;
#define int long long


signed main () {
  ios_base :: sync_with_stdio(false);
  cin.tie(0);


  ofstream fout;
  int testNo = 0;
  string fileRoot = "input_";
  string nums[20] = {"01", "02", "03", "04", "05", "06", "07", "08", "09", "10", "11", "12", "13", "14", "15"};

  srand(time(NULL));

  while (testNo < 15) {
    string fileName = fileRoot + nums[testNo] + ".txt";
    fout.open(fileName);

    int T = 100;
    fout << T << endl;

    while (T -- ) {
      int n = rand() % 10000 + 1;
      fout << n << endl;
      for (int i = 0; i < n; i ++) {
        int a = rand() % 1000;
        int op = rand() % 2;
        if (op) fout << a << " ";
        else fout << -a << " ";
      }
    }
    fout.close();
    testNo ++;
  }
  return 0;
}