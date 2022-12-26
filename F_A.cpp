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
        if (pol_f.ex[f_seat] > pol_s.ex[s_seat] && pol_s.coef[s_seat] != 0) {  // f������ s���� Ŭ��
            pol_a.ex[a_seat] = pol_s.ex[s_seat];  // ���� s ������ ���
            pol_a.coef[a_seat] = -pol_s.coef[s_seat];  // s������ ���̳ʽ��� ���
            s_seat += 1;
            a_seat += 1;
        }
        else if (pol_f.ex[f_seat] == pol_s.ex[s_seat]) {  //f������ s������ ������
            pol_a.ex[a_seat] = pol_s.ex[s_seat];  //�ƹ��ų� ���
            pol_a.coef[a_seat] = pol_f.coef[f_seat] - pol_s.coef[s_seat];  //���� ���
            a_seat += 1;
            f_seat += 1;
            s_seat += 1;
        }
        else if(pol_f.ex[f_seat] < pol_s.ex[s_seat] && pol_f.coef[f_seat] != 0) {
            pol_a.ex[a_seat] = pol_f.ex[f_seat]; // f������ s���� ������ f���� ���
            pol_a.coef[a_seat] = pol_f.coef[f_seat];  //f������ ���
            a_seat += 1;
            f_seat += 1;
        }
        else if(pol_f.ex[f_seat] < pol_s.ex[s_seat] && pol_f.coef[f_seat] == 0) {
            pol_a.ex[a_seat] = pol_s.ex[s_seat];  //  s ������ ���
            pol_a.coef[a_seat] = -pol_s.coef[s_seat];  // s������ ���̳ʽ��� ���
            s_seat += 1;
            a_seat += 1;
        }
        else {
            pol_a.ex[a_seat] = pol_f.ex[f_seat]; // f������ s���� ������ f���� ���
            pol_a.coef[a_seat] = pol_f.coef[f_seat];  //f������ ���
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
        if (pol_a.coef[out_i] == 0 && pol_a.ex[out_i] != 0) { //����� 0�̸鼭 ������ 0�� �ƴҶ�
            zero_count += 1;
            if (out_i == 0) {
                cout << pol_a.coef[out_i];
            }
        }
        else if (pol_a.coef[out_i] == 0 && pol_a.ex[out_i] == 0) { //����� 0�̸鼭 ������ 0�϶�
            zero_count += 1;
            if (out_i == 0 && zero_count == pol_a.ntem) {
                cout << pol_a.coef[out_i];
            }
        }
        else if (pol_a.coef[out_i] == 1 && pol_a.ex[out_i] == 1) { //����� ������ �� 1�϶��� x�� ��
            cout << "x";
        }
        else if (pol_a.coef[out_i] == -1 && pol_a.ex[out_i] == 1) { //����� -1 ������ 1�϶��� -x�� ��
            cout << "-x";
        }
        else if (pol_a.coef[out_i] == 1 && pol_a.ex[out_i] != 1 && pol_a.ex[out_i] != 0) { //����� 1�϶��� ����� ����
            cout << "x^" << pol_a.ex[out_i];
        }
        else if (pol_a.coef[out_i] == -1 && pol_a.ex[out_i] != 1 && pol_a.ex[out_i] != 0) { //����� -1�϶��� ����� ����
            cout << "-x^" << pol_a.ex[out_i];
        }
        else if (pol_a.ex[out_i] == 1 && pol_a.coef[out_i] != 1 && pol_a.coef[out_i] != 0 && pol_a.coef[out_i] != -1) { //������ 1�̸鼭 ����� -1, 1�Ǵ� 0�� �ƴҶ� ��������
            cout << pol_a.coef[out_i] << "x";
        }
        else if (pol_a.ex[out_i] == 0 && pol_a.coef[out_i] != 0) {   //������ 0�̸鼭 ����� 0�� �ƴҶ� ����� ���
            cout << pol_a.coef[out_i];
        }
        else {
            cout << pol_a.coef[out_i] << "x^" << pol_a.ex[out_i];
        }

        if ( out_i > 0 && pol_a.ex[out_i] > 0) { //�� ���� ���� ����� 1 �̻��̸鼭 ������ 1�̻��϶� +�� ����
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