void dfs (int v) {
    while (adj[v].size()) {
        int a = adj[v].back().F;
        int b = adj[v].back().S;
        adj[v].pop_back();
        if (!mark[b]) {
            mark[b] = true;
            dfs(a);
        }
        // ans.pb(b); yal
    }
    ans.pb(v);
}
