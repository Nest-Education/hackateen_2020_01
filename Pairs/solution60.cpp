#include<iostream>
#include<vector>

using namespace std;

int main(){

    int n, m, x, sum = 0;
    cin >> n >> m;    
    vector<int> a(n);

    for (int i = 0; i < n; i++)
        cin >> a[i];

    for (int i = 0; i < n; i++){
        for (int j = i + 1; j < n; j++){
            if (a[i] + a[j] == m)
                sum++;
        }
    }
    cout << sum << endl;

    return 0;
}