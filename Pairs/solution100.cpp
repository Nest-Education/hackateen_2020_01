#include<iostream>
#include<vector>
#include<map>
#include<unordered_map>

using namespace std;

    unordered_map<int, int> cnt;

int main(){
    // freopen("in15.txt", "r", stdin);
    // freopen("out15.txt", "w", stdout);
    
    int n, m, x, sum = 0;
    unordered_map<int, int>::iterator it;

    cin >> n >> m;    
    for (int i = 0; i < n; i++){
        cin >> x;
        it = cnt.find(m - x);    
        if (it != cnt.end())
            sum += it->second;
        it = cnt.find(x);
        if (it != cnt.end())
            it->second++;
        else
            cnt.insert(make_pair(x, 1));        
    }

    cout << sum << endl;

    return 0;
}