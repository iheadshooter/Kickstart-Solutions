#include <bits/stdc++.h>
using namespace std;

long long int mod_exp(long long int a, long long int b, long long int p) {
    if (b == 0) {
        return 1;
    }
    if (b == 1) {
        return a;
    }
    long long int temp = mod_exp(a, b / 2, p);
    temp *= temp;
    temp %= p;
    if (b % 2 == 1) {
        temp *= a;
        temp %= p;
    }
    return temp % p;
}

int main() {
    int tc;
    cin >> tc;
    for (int t = 1 ; t <= tc ; t++) {
        long long int a, n, p;
        cin >> a >> n >> p;
        long long int res = a;
        for (long long int k = 2 ; k <= n ; k++) {
            res = mod_exp(res, k, p);
            res %= p;
        }
        cout << "Case #" << t << ": " << res % p << endl;
    }
    return 0;
}