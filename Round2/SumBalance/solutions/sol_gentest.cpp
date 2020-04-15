#include <iostream>
#include<fstream>
#include<vector>
#include<random>
#include<limits>
#include<algorithm>
#include<time.h>

#define MAXEL 10000000;

using namespace std;

void prep_tests() {
    srand(time(NULL));
    long step  = 10;
    long i = 2;
    while(i < 20) {
        if(i > 4) step = 500;
        if(i > 9) step = 10000;
        if(i > 14) step = 25000;
        string test_name = "in" + to_string(i) + ".txt";
        ofstream outp(test_name);
        long long sum = 0;
        int total = 0;

        vector<int> first;
        for(int j = 0; j < i * step - 1; j++) {
            long tmp = rand() % MAXEL;
            first.push_back(tmp);
            sum += tmp;
        }
        total = i * step;

        int divider = rand() % MAXEL;

        vector<int> second(first);
        random_shuffle(second.begin(), second.end());
        total *= 2;

        // random mergings
        int remove_from_first = rand() % 100;
        if(remove_from_first >= total / 2) remove_from_first = total / 4;
        for(unsigned int j = 0; j < first.size(); j++) {
            int index = rand() % first.size() - 1;
            if(index <= 0) index = 0;
            if(first[index] + first[index + 1] < 10000000) {
                first[index] += first[index + 1];
                first.erase(first.begin() + index + 1);
                total--;
            }
        }
        int remove_from_second = rand() % 100;
        if(remove_from_second >= total / 2) remove_from_second = total / 4;
        for(unsigned int j = 0; j < second.size(); j++) {
            int index = rand() % second.size() - 1;
            if(index <= 0) index = 0;
            if(second[index] + second[index + 1] < 10000000) {
                second[index] += second[index + 1];
                second.erase(second.begin() + index + 1);
                total--;
            } 
        }

        // poor man's assert
        long long sum_of_elems = 0;
        for (auto& x : first)
            sum_of_elems += x;
        for (auto& x : second)
            sum_of_elems -= x;
        cout << sum_of_elems << endl;


        outp << first.size() + 1 + second.size() << endl;
        for(unsigned int j = 0; j < first.size(); j++) {
            outp << first[j] << " ";
        }
        outp << divider;
        for(unsigned int j = 0; j < second.size(); j++) {
            outp << " " << second[j];
        }

        outp.close();
        i++;
    }
}

void prep_sols() {
    for (int i = 0; i < 20; i++) {
        string test_name = "in" + to_string(i) + ".txt";
        string sol_name = "out" + to_string(i) + ".txt";
        ifstream inp(test_name);
        ofstream outp(sol_name);
        long n;
        long long sum = 0;
        inp >> n;
        long a[n];
        for(long i = 0; i < n; i++){
            inp >> a[i]; 
            sum += a[i];
        }  
        long left = 0, right = n-1, leftSum = 0, rightSum = 0;
        while(left <= right){
            if(leftSum == rightSum && left == right){
                outp << left << endl;
                break;
            }
            if(leftSum < rightSum){
                leftSum += a[left++]; 
            }else if(leftSum > rightSum){
                rightSum += a[right--]; 
            }else{
                if(a[left] < a[right]) leftSum += a[left++];
                else rightSum += a[right--];
            }
        }
        if(left != right) outp << "invalid" << "\n";
        inp.close();
        outp.close();
    }
}

int main() {
    /* prep_tests(); */
    prep_sols();
    return 0;
}
