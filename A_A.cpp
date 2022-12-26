#pragma warning(disable:4996)
#include<iostream>
#include<algorithm>
#include<math.h>
using namespace std;

int main()
{
    int Money[5] = {10000, 5000, 1000, 500, 100};
    int TestCase = 0;
    int Pay;
    int result[5] = { 0 };

    cin >> TestCase;
    for (int i = 0; i < TestCase; i++) {
        cin >> Pay;
        for (int j = 0; j < 5; j++) {
            result[j] += Pay / Money[j];
            Pay = Pay % Money[j];
            
            cout << result[j] << " ";

            result[j] = 0;
        }
    }

    return 0;
}