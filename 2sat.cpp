// baraye i darim ~i: 2 * i + 1 va i: 2 * i

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
 
void add (int u, int v) {
    adj[u].pb(v);
    radj[v].pb(u);
}

for (int i = 2; i <= n << 1 | 1; i++) // !!!!
    if (!mark[i]) dfs(i);

reverse(all(t));

memset(mark, 0, sizeof mark);

int tmp = 0;
for (auto u: t)
if (!mark[u])
    sfd(u, ++tmp);

for (int i = 1; i <= n; i++) {
    if (col[i << 1] == col[i << 1 | 1])
        kill("NO")
    else if (col[i << 1] > col[i << 1 | 1])
        b[i] = 1;
}


