memset(dis, 63, sizeof dis);
dis[1] = 0;
priority_queue<pll, vector<pll>, greater<pll>> q;
q.push({0, 1});
int added = 0;
ll ans = 0;
while (added < n) {
    if (q.empty()) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }
    auto [w, v] = q.top();
    q.pop();
    if (dis[v] < w) continue;
    added++;
    mark[v] = true;
    ans += w;
    for (auto &[u, ww] : adj[v]) {
        if (!mark[u] && ww < dis[u]) {
            dis[u] = ww;
            q.push({ww, u});
        }
    }
}
cout << ans << '\n';