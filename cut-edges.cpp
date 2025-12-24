int cut(int v, int he, int p) {//1, 0, -1
    mark[v] = true;
    h[v] = he;
    int mn = he;
    for (auto u : g[v]) {
        if (mark[u] && u != p)
            mn = min(mn, h[u]);
        else if (!mark[u]) {
            int tmp = cut(u, he + 1, v);
            if (tmp > he)
                cedges.pb(pii(u, v));
            mn = min(mn, tmp);
        }
    }
    return mn;
}
