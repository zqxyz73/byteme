/* created   : 2021-04-10 21:09:15
 * accepted  : $ACCEPTED
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
using ar = array<int, 2>;

vector<vector<int>> g;
vector<int> sz;
vector<int> cnt;
vector<int> visit;
int N;
int K;
ll ans;
int max_depth;

int get_subtree(int u, int p = -1) {
  sz[u] = 1;
  for (int v : g[u]) {
    if (v != p && !visit[v]) {
      sz[u] += get_subtree(v, u);
    }
  }
  return sz[u];
}

int get_centroid(int n, int u, int p=-1) {
  for (int v : g[u]) {
    if (sz[v] >= n / 2 && v != p && !visit[v]) {
      return get_centroid(n, v, u);
    }
  }
  return u;
}

void dfs(int u, int p, bool fill, int depth = 1) {
  if (depth > K) return;
  max_depth = max(max_depth, depth);
  if (fill) {
    cnt[depth]++;
  }
  else {
    ans += cnt[K - depth];
  }
  for (int v : g[u]) {
    if (v != p && !visit[v]) {
      dfs(v, u, fill, depth + 1);
    }
  }
}

void centroid_decomposition(int u) {
  int c = get_centroid(get_subtree(u), u);
  // trace(c);
  visit[c] = true;
  cnt[0] = 1;
  max_depth = 0;
  for (int v : g[c]) {
    if (!visit[v]) {
      dfs(v, c, false);
      dfs(v, c, true);
    }
  }
  fill(cnt.begin(), cnt.begin() + max_depth + 1, 0);
  for (int v : g[c]) {
    if (!visit[v]) {
      centroid_decomposition(v);
    }
  }
}

void solve() {
  cin >> N >> K;
  g.resize(N);
  sz.resize(N);
  visit.resize(N);
  cnt.resize(N);
  for (int i = 0; i < N - 1; i++) {
    int u, v; cin >> u >> v;
    u--, v--;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  centroid_decomposition(0);
  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  solve();
}
