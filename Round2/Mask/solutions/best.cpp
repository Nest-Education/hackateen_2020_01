#include<iostream>
#include<fstream>
#include <iomanip>
#include <cmath>
#include <ctime>

using namespace std;

int main(){
    string file_name, out_name;

    for (int i = 0; i < 50; i++){
        if (i < 10){
            file_name = "../tests/in0" + to_string(i) + ".txt";
            out_name = "../tests/out0" + to_string(i) + ".txt";
        }else{
            file_name = "../tests/in" + to_string(i) + ".txt";
            out_name = "../tests/out" + to_string(i) + ".txt";
        }
        ifstream in(file_name);
        ofstream out(out_name);
        int n, max_price;
        double bill, cnt, per_price, original_price, discount, min_price;
        in >> n;
        for (int i = 0; i < n; i++){
            in >> bill >> cnt;
            bill -= 2000;
            if (cnt < 10)
                discount = 100;
            else if (cnt <= 30)
                discount = 90;
            else if (cnt < 50)
                discount = 85;
            else
                discount = 80;

            per_price = bill / cnt;
            original_price = per_price * 100.0 / discount;

            if (i == 0)
                min_price = original_price;
            else
                min_price = min(min_price, original_price);
        }

        out << fixed << setprecision(2) << min_price << endl;
    }

    return 0;
}