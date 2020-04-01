#include<iostream>
#include<vector>

using namespace std;

int main(){

    int n, m, x, sum = 0;
    cin >> n >> m;    
    vector<int> a(50000, 0);

    for (int i = 0; i < n; i++){
        cin >> x;
        if (m >=x )
            sum += a[m - x];
        a[x]++;
    }

    cout << sum << endl;

    return 0;
}