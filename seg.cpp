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
#define task "main"

struct SegTree {
  int n;
  vector<int> tree, lazy;

  SegTree(int _n) {
    n = _n;
    tree.assign(4*n, 0);
    lazy.assign(4*n, 0);
  }

  void build(int id, int l, int r, vector<int> &a) {
    if (l == r) {
      tree[id] = a[l];
      return;
    }
    int mid = (l + r) >> 1;
    build(id<<1, l, mid, a);
    build(id<<1|1, mid+1, r, a);
    tree[id] = tree[id<<1] + tree[id<<1|1];
  }

  void push(int id, int l, int r) {
    if (!lazy[id]) return;
    int mid = (l + r) >> 1;
    tree[id<<1] += lazy[id] * (mid - l + 1);
    lazy[id<<1] += lazy[id];
    tree[id<<1|1] += lazy[id] * (r - mid);
    lazy[id<<1|1] += lazy[id];
    lazy[id] = 0;
  }

  void update(int id, int l, int r, int u, int v, int val) {
    if (r < u || v < l) return;
    if (u <= l && r <= v) {
      tree[id] += val * (r - l + 1);
      lazy[id] += val;
      return;
    }
    push(id, l, r);
    int mid = (l + r) >> 1;
    update(id<<1, l, mid, u, v, val);
    update(id<<1|1, mid+1, r, u, v, val);
    tree[id] = tree[id<<1] + tree[id<<1|1];
  }

  int query(int id, int l, int r, int u, int v) {
    if (r < u || v < l) return 0;
    if (u <= l && r <= v) return tree[id];
    push(id, l, r);
    int mid = (l + r) >> 1;
    return query(id<<1, l, mid, u, v) + query(id<<1|1, mid+1, r, u, v);
  }

  void build(vector<int> &a) {
    build(1, 0, n-1, a);
  }

  void update(int l, int r, int val) {
    update(1, 0, n-1, l, r, val);
  }

  int query(int l, int r) {
    return query(1, 0, n-1, l, r);
  }
};

void solve() {
  int n, q; cin >> n;
  vector<int> a(n);
  for (auto& x : a) cin >> x;
  SegTree tree(n);
  tree.build(a);
  cin >> q;
  while (q--) {
    int type ; cin >> type;
    if (type == 1) {
      int i, v; cin >> i >> v;
      i--;
      tree.update(i, i, v - a[i]);
      a[i] = v;
    }
    else if (type == 2) {
      int l, r; cin >> l >> r;
      l--; r--;
      cout << tree.query(l, r) << endl;
    }
  }
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