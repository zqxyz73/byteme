//============================================================================
// Name        : b
// Date        : Sat Mar 23 11:41:58 CST 2019
// Author      : landcold7
// Description : Actions speak louder more than words
//============================================================================
#include "bits/stdc++.h"
using namespace std;

#define x first
#define y second
#define pb push_back
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define mst(x, y) memset(x, y, sizeof(x))
#define pvar(x) cout << #x << ": "
#define output(v) cout << (v) << '\n'
#define fori(i, a, b) for (int i = a; i < b; ++i)
#define jam(x, n) cout << "Case #" << x << ": " << n << "\n"
#define prt(x, a, n) { cout << x[a]; if (a < n - 1) cout << " "; }
#define par(x, s, n, v) if(v) pvar(x); fori(y, s, n) prt(x, y, n) cout << "\n"

#ifndef __has_trace
#define trace(...)
#endif
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef pair<int, int> pii;
typedef vector<pii> vpii;

void solve() {
    int n; cin >> n;
    string s; cin >> s;

    int a = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] != '>') {
            ++a;
        } else {
            break;
        }
    }

    int b = 0;
    for (int i = n - 1; i >= 0; --i) {
        if (s[i] != '<') {
            ++b;
        } else {
            break;
        }
    }
    output(min(a, b));
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t >> ws;
    fori (i, 1, t + 1) {
        solve();
    }
    return 0;
}

