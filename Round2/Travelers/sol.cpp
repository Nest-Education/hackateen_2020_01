#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
    int t, n, i;
    cin >> t;
    while(t--)
    { 
        cin >> n;
        vector<int> speeds(n);
        long total = 0;
        for(i = 0; i < n; i++)
            cin >> speeds[i];
        sort(speeds.begin(), speeds.end());
        for(i = n - 1; i >= 3; i -= 2)
        {
            if(2 * speeds[1] >= speeds[0] + speeds[i - 1]) {
                total += 2 * speeds[0] + speeds[i - 1] + speeds[i];
            } else {
                total += 2 * speeds[1] + speeds[0] + speeds[i];  

            }
        }
        if(i == 2) total += speeds[0] + speeds[1] + speeds[2];
        if(i == 1) total += speeds[1];
        if(i == 0) total += speeds[0];
        cout << total << endl;
    } 
    return 0;
}

