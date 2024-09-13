#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>

void solveQueries(string &str, const int &n, const int &q, const auto&start, const auto &end) {
    vector<vector<int>> prefix(n, vector<int>(2, 0));
    for(int i=0;i<n;i++) {
        if(i == 0) {
            if(str[i] == '*') {
                prefix[i][0]++;
            } else {
                prefix[i][1]++;
            }
        } else {
            if(str[i] == '*') {
                prefix[i][0] = prefix[i-1][0] + 1;
                prefix[i][1] = prefix[i-1][1];
            } else {
                prefix[i][1] = prefix[i-1][1] + 1;
                prefix[i][0] = prefix[i-1][0];
            }
        }
    }

    vi nearestToTheLeft(n, -1);
    int x = -1;
    for(int i=0;i<n;i++) {
        while(i<n && str[i] != '|') {
            nearestToTheLeft[i] = x;
            i++;
        }
        if(i == n) break;
        x = i;
        nearestToTheLeft[i] = x;
    }
    vi nearestToTheRight(n, -1);
    x = -1;
    for(int i=n-1;i>=0;i--) {
        while(i >= 0 && str[i] != '|') {
            nearestToTheRight[i] = x;
            i--;
        }
        if(i == -1) break;
        x = i;
        nearestToTheRight[i] = x;
    }
    for(int i=0;i<q;i++) {
        int s = start[i], e = end[i];
        if(s >= e) {
            cout << "0\n";
            continue;
        }
        int left_bar = nearestToTheRight[s], right_bar = nearestToTheLeft[e];
        if(left_bar == -1) {
            cout << "0\n";
            continue;
        }
        cout << (prefix[right_bar][0] - prefix[left_bar][0]) << '\n';
    }
}

int main() {
    // steps:
    // 1. read input: number of tests, a string and 2 arrays corresponding to each
    // 2. solve:
    //     - make a normal prefix array
    //     - make two nearest '|' array
    //     - solve each query in O(1)
    int numTests;
    cin >> numTests;

    string inp;
    vi startIdx, endIdx;
    int n, q;
    while(numTests--) {
        cin >> n >> q;
        cin >> inp;
        startIdx.resize(q);
        endIdx.resize(q);
        for(int i=0;i<q;i++) cin >> startIdx[i];
        for(int i=0;i<q;i++) cin >> endIdx[i];
        solveQueries(inp, n, q, startIdx, endIdx);
    }
        
}