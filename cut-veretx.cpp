void dfs (int v, int p = -1) {
    int cnt = 0;
    up[v] = h[v];
    bool b = false;
    mark[v] = true;
    for (auto u: adj[v]) {
        if (u == p) continue;
        if (mark[u]) up[v] = min(up[v], h[u]);
        else {
            h[u] = h[v] + 1;
            dfs(u, v);
            cnt++;
            up[v] = min(up[v], up[u]);
            if (up[u] >= h[v]) b = true;
        }
    }
    if (p == -1) b = cnt > 1;
    if (b) ans.pb(v);
}
