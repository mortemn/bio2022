#include <bits/stdc++.h>

using namespace std;

vector<int> fib(long n) {
    int x = 1;
    vector<int> seq;
    seq.push_back(1);
    seq.push_back(2);
    while (x < n) {
        int i = seq.size() - 1;
        x = seq[i] + seq[i-1];
        seq.push_back(x);
    }
    return seq;
}

vector<int> sum;

int zeckendorf(long n, vector<int> seq, vector<int> &ans) {
    int x;
    for (int i=seq.size()-1; i>=0; i--) {
        if (n < seq[i]) {
            x = seq[i-1];
        }
    }
    ans.push_back(x);
    if (n-x <= 0)   return x;
    sum.push_back(zeckendorf(n-x, seq, ans));
}

int main() {
    int n;
    cin >> n;

    vector<int> res = fib(n);
    vector<int> ans;
    zeckendorf(n, res, ans);
    for (int i=0; i<ans.size(); i++) {
        cout << ans[i] << " ";
    }
}
