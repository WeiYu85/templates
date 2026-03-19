#include <bits/stdc++.h>
#pragma GCC optimize("Ofast,unroll-loops")
#define int long long
#define double long double
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define lb lower_bound
#define ub upper_bound
#define pb push_back
#define pii pair<int,int>
#define fi first 
#define se second
#define popcnt __builtin_popcountll
#define BIT(x, i) (((x) >> (i)) & 1)
#define fast_io ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
const int inf = LLONG_MAX;
const int maxn = 1e6+5;
const int mod = 1e9+7;
const int base = rng()%(mod/3)+(mod/3);
// const int base = 19937
#define task "main"

struct Hash {
  vector<int> hs, rhs;
  static vector<int> pw;
  static void init(int n) {
    if ((int)pw.size() >= n + 1) return;
    int eh = pw.size();
    pw.resize(n + 1);
    if (eh == 0) {
      pw[0] = 1;
      eh = 1;
    }
    for (int i = eh; i <= n; i++) pw[i] = pw[i-1] * base % mod;
  }
  Hash() {}
  Hash(const string &s) {
    int n = s.size();
    init(n);
    hs.resize(n + 1);
    rhs.resize(n + 2);
    hs[0] = 0;
    for (int i = 0; i < n; i++) {
      hs[i+1] = (hs[i] * base + (int)s[i]) % mod;
    }
    rhs[n+1] = 0;
    for (int i = n; i >= 1; i--) {
      rhs[i] = (rhs[i+1] * base + (int)s[i-1]) % mod;
    }
  }
  int get(int l, int r) {
    int res = hs[r] - hs[l-1] * pw[r-l+1] % mod;
    if (res < 0) res += mod;
    return res;
  }
  int rev(int l, int r) {
    int res = rhs[l] - rhs[r+1] * pw[r-l+1] % mod;
    if (res < 0) res += mod;
    return res;
  }
  bool palin(int l, int r) {
    return get(l, r) == rev(l, r);
  }
};
vector<int> Hash::pw;

void solve() {

}

signed main() { 
  fast_io;
  if(fopen(task".INP", "r")) {
    freopen(task".INP", "r", stdin);
    freopen(task".OUT", "w", stdout);
  }
  int t = 1; 
  // cin >> t;
  while (t--) solve();
  return 0;
}
