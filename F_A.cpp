#include <iostream>
#include <algorithm>

using namespace std;

struct polynomial
{
    int ntem = 0;
    int coef[3000] = { 0 };
    int ex[3000] = { 0 };
};
polynomial pol_f;
polynomial pol_s;
polynomial pol_a;


void sub() {

    int a_seat = 0;
    int f_seat = 0;
    int s_seat = 0;

    cin >> pol_f.ntem;
    int f_i = pol_f.ntem;
    for (int i = 0; i < pol_f.ntem; i++) {
        f_i -= 1;
        cin >> pol_f.coef[f_i] >> pol_f.ex[f_i];
    }
    cin >> pol_s.ntem;
    int s_i = pol_s.ntem;
    for (int i = 0; i < pol_s.ntem; i++) {
        s_i -= 1;
        cin >> pol_s.coef[s_i] >> pol_s.ex[s_i];
    }

    pol_a.ntem = pol_f.ntem + pol_s.ntem;
    for (int i = 0; i < pol_a.ntem; i++) {
        if (pol_f.ex[f_seat] > pol_s.ex[s_seat] && pol_s.coef[s_seat] != 0) {  // f지수가 s보다 클때
            pol_a.ex[a_seat] = pol_s.ex[s_seat];  // 작은 s 지수를 등록
            pol_a.coef[a_seat] = -pol_s.coef[s_seat];  // s지수를 마이너스로 등록
            s_seat += 1;
            a_seat += 1;
        }
        else if (pol_f.ex[f_seat] == pol_s.ex[s_seat]) {  //f지수와 s지수가 같을때
            pol_a.ex[a_seat] = pol_s.ex[s_seat];  //아무거나 등록
            pol_a.coef[a_seat] = pol_f.coef[f_seat] - pol_s.coef[s_seat];  //빼서 등록
            a_seat += 1;
            f_seat += 1;
            s_seat += 1;
        }
        else if(pol_f.ex[f_seat] < pol_s.ex[s_seat] && pol_f.coef[f_seat] != 0) {
            pol_a.ex[a_seat] = pol_f.ex[f_seat]; // f지수가 s보다 작을때 f지수 등록
            pol_a.coef[a_seat] = pol_f.coef[f_seat];  //f지수를 등록
            a_seat += 1;
            f_seat += 1;
        }
        else if(pol_f.ex[f_seat] < pol_s.ex[s_seat] && pol_f.coef[f_seat] == 0) {
            pol_a.ex[a_seat] = pol_s.ex[s_seat];  //  s 지수를 등록
            pol_a.coef[a_seat] = -pol_s.coef[s_seat];  // s지수를 마이너스로 등록
            s_seat += 1;
            a_seat += 1;
        }
        else {
            pol_a.ex[a_seat] = pol_f.ex[f_seat]; // f지수가 s보다 작을때 f지수 등록
            pol_a.coef[a_seat] = pol_f.coef[f_seat];  //f지수를 등록
            a_seat += 1;
            f_seat += 1;
        }
    }
    int out_i = 0;
    int zero_count = 0;
    out_i = pol_a.ntem;
    for (int i = 0; i < pol_a.ntem; i++) {
        if (out_i > 0) {
            out_i -= 1;
        }
        if (pol_a.coef[out_i] == 0 && pol_a.ex[out_i] != 0) { //계수가 0이면서 지수는 0이 아닐때
            zero_count += 1;
            if (out_i == 0) {
                cout << pol_a.coef[out_i];
            }
        }
        else if (pol_a.coef[out_i] == 0 && pol_a.ex[out_i] == 0) { //계수가 0이면서 지수도 0일때
            zero_count += 1;
            if (out_i == 0 && zero_count == pol_a.ntem) {
                cout << pol_a.coef[out_i];
            }
        }
        else if (pol_a.coef[out_i] == 1 && pol_a.ex[out_i] == 1) { //계수랑 지수가 다 1일때는 x만 씀
            cout << "x";
        }
        else if (pol_a.coef[out_i] == -1 && pol_a.ex[out_i] == 1) { //계수는 -1 지수는 1일때는 -x만 씀
            cout << "-x";
        }
        else if (pol_a.coef[out_i] == 1 && pol_a.ex[out_i] != 1 && pol_a.ex[out_i] != 0) { //계수가 1일때는 계수를 생략
            cout << "x^" << pol_a.ex[out_i];
        }
        else if (pol_a.coef[out_i] == -1 && pol_a.ex[out_i] != 1 && pol_a.ex[out_i] != 0) { //계수가 -1일때는 계수를 생략
            cout << "-x^" << pol_a.ex[out_i];
        }
        else if (pol_a.ex[out_i] == 1 && pol_a.coef[out_i] != 1 && pol_a.coef[out_i] != 0 && pol_a.coef[out_i] != -1) { //지수가 1이면서 계수는 -1, 1또는 0이 아닐때 제곱생략
            cout << pol_a.coef[out_i] << "x";
        }
        else if (pol_a.ex[out_i] == 0 && pol_a.coef[out_i] != 0) {   //지수가 0이면서 계수가 0이 아닐때 계수만 출력
            cout << pol_a.coef[out_i];
        }
        else {
            cout << pol_a.coef[out_i] << "x^" << pol_a.ex[out_i];
        }

        if ( out_i > 0 && pol_a.ex[out_i] > 0) { //그 다음 오는 계수가 1 이상이면서 지수가 1이상일때 +를 붙임
            if (pol_a.coef[out_i - 1] > 0) {
                cout << "+";
            }
        }

    }
    cout << endl;
    for (int i = 0; i < pol_a.ntem; i++) {
        pol_f.coef[i] = 0;
        pol_f.ex[i] = 0;
        pol_s.coef[i] = 0;
        pol_s.ex[i] = 0;
        pol_a.coef[i] = 0;
        pol_a.ex[i] = 0;
    }
}

int main() {
    int Testcase = 0;
    cin >> Testcase;

    for (int i = 0; i < Testcase; i++) {
        sub();
    }
}