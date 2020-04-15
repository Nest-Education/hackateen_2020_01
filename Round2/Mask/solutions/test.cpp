#include<iostream>
#include<fstream>
#include <iomanip>
#include <cmath>
#include <ctime>

using namespace std;

int main(){

    srand(time(NULL));

    int n, a, b;
    for (int i = 15; i < 25; i++){
        string file_name;
        if (i < 10)
            file_name = "../tests/in0" + to_string(i) + ".txt";
        else
            file_name = "../tests/in" + to_string(i) + ".txt";
        ofstream out(file_name);
        n = rand() % 100 + 1;
        out << n << endl;
        for (int j = 0; j < n; j++){
            int a, b;
            a = rand() % 100000000 + 2001;
            b = rand() % 100 + 1;
            out << a << ' ' << b << '\n';
        }
    }




    return 0;
}