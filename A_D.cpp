#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int v[64][64];

// Àç±ÍÇÔ¼ö
void  Quad_tree(int size, int y, int x)
{
    int sum = v[y][x];

    for (int i = y; i < y + size; i++)
        for (int j = x; j < x + size; j++)
            if (v[i][j] != sum)
            {
                cout << '(';
                Quad_tree(size / 2, y, x);
                Quad_tree(size / 2, y, x + size / 2);
                Quad_tree(size / 2, y + size / 2, x);
                Quad_tree(size / 2, y + size / 2, x + size / 2);
                cout << ')';
                return;
            }

    cout << sum;
}

int main()
{
    int TestCase;
    cin >> TestCase;

    int N;
    for (int i = 0; i < TestCase; i++) {
        cin >> N;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cin >> v[i][j];
            }
        }
        Quad_tree(N, 0, 0);
        cout << endl;
    }

    return 0;
}