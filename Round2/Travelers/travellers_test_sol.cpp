#include<iostream>
#include<vector>
#include<algorithm>
#include<time.h>
#include<fstream>

using namespace std;

void prepTests() {
    srand(time(NULL));
    for(int i = 0; i < 20; i++) {
        string test_name = "in" + to_string(i) + ".txt";
        ofstream test_file(test_name);
        int T = i + 1;
        test_file << T << endl;
        for(int j = 0; j < T; j++) {
            int n = rand() % (T * 50) + 1;
            test_file <<  n << endl;
            for(int z = 0; z < n - 1; z++) {
                test_file << rand() % 1000 + 1 << " ";
            }
            test_file << rand() % 1000 + 1 << endl;
        }
        test_file.close(); 
    }
}

void prepSolutions() {
    for(int i = 0; i < 20; i++) {
        string test_name = "in" + to_string(i) + ".txt";
        string sol_name = "out" + to_string(i) + ".txt";
        ifstream inp(test_name);
        ofstream outp(sol_name);
        int T, n;
        inp >> T;
        while(T--)
        { 
            inp >> n;
            vector<int> speeds(n);
            long total = 0, j;
            for(j = 0; j < n; j++)
                inp >> speeds[j];
            sort(speeds.begin(), speeds.end());

            for(j = n - 1; j >= 3; j -= 2)
            {
                if(2 * speeds[1] >= speeds[0] + speeds[j - 1]) {
                    total += 2 * speeds[0] + speeds[j - 1] + speeds[j];
                } else {
                    total += 2 * speeds[1] + speeds[0] + speeds[j];  

                }
            }
            if(j == 2) total += speeds[0] + speeds[1] + speeds[2];
            if(j == 1) total += speeds[1];
            if(j == 0) total += speeds[0];
            outp << total << endl;
        } 
        inp.close();
        outp.close();
    }
}

int main()
{
    /* prepTests(); */
    prepSolutions();
    return 0;
}

