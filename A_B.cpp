#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<int, int>> v, v_r;

bool comp(pair<int, int> a, pair<int, int> b) {
    if (a.first == b.first) {
        return a.second < b.second;
    }
    else {
        return a.first < b.first;
    }
}

bool comp_r(pair<int, int> a, pair<int, int> b) {
    if (a.second == b.second) {
        return a.first < b.first;
    }
    else {
        return a.second < b.second;
    }
}

int main() {
    int TestCase;
    int cnt = 3;
    int cnt_r = 3;

    cin >> TestCase;

    for (int i = 0; i < TestCase; i++) {
        int x, y;
        cin >> x >> y;
        v.push_back({ x,y });
        v_r.push_back({ x, y });
    }

    sort(v.begin(), v.end(), comp);
    sort(v_r.begin(), v_r.end(), comp_r);

    int now, now_r;
    int a = v[0].second, b = v[1].second, c = v[2].second;
    int a_r = v_r[0].second, b_r = v_r[1].second, c_r = v_r[2].second;
    for (int i = 3; i < TestCase; i++) {
        now = v[i].first;
        if (now >= a) {
            cnt++;
            a = v[i].second;
        }
        else if (now >= b) {
            cnt++;
            b = v[i].second;
        }
        else if (now >= c) {
            cnt++;
            c = v[i].second;
        }
    }

    for (int i = 3; i < TestCase; i++) {
        now_r = v_r[i].first;
        if (now_r >= a_r) {
            cnt_r++;
            a_r = v_r[i].second;
        }
        else if (now_r >= b_r) {
            cnt_r++;
            b_r = v_r[i].second;
        }
        else if (now_r >= c_r) {
            cnt_r++;
            c_r = v_r[i].second;
        }
    }

    if (cnt > cnt_r) {
        cout << cnt;
    }
    else {
        cout << cnt_r;
    }
}