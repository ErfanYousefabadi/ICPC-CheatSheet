void dfs (int v) {
    mark[v] = true;
    for (auto u: adj[v])
        if (!mark[u])
            dfs(u);
    t.pb(v);
}
 
void sfd (int v, int c) {
    col[v] = c;
    mark[v] = true;
    for (auto u: adj[v])
        if (!mark[u])
            sfd(u, c);
}

for (int i = 1; i <= n; i++)
    if (!mark[i]) dfs(i);
reverse(all(t));
memset(mark, 0, sizeof mark);
int tmp = 0;
for (auto u: t)
    if (!mark[u])
        sfd(u, ++tmp);
