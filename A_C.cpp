#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    int o;
    cin >> n;
    int arr[100001] = { 0 };

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cin >> o;
    int len = n;
    int start = 0;
    int end = len - 1;
    int mid;
    int key;
    int sum[10001] = { 0 };
    for (int i = 0; i < o; i++) {
        end = len - 1;
        start = 0;
        mid = (start + end) / 2;
        cin >> key;
        while (end - start >= 0) {
            mid = (start + end) / 2; // �߾� ��

            if (arr[mid] == key) { // key ���� ã���� ��
                sum[i] = mid;
                break;
            }
            else if (arr[mid] > key) { // key ���� mid�� ������ ������ (��������)
                end = mid - 1;
            }
            else if (arr[mid] < key && key <= arr[end]) { // key ���� mid�� ������ Ŭ ��(����������)
                start = mid + 1;
            }
            else {
                sum[i] = -1;
                break;
            }
            if (end - start >= 0) {
                sum[i] = -1;
            }
        }
    }

    for (int i = 0; i < o; i++) {
        cout << sum[i] << endl;
    }
    return 0;
}