const ll P = 6065621;
ll ps[N][2], pw[N][2], inv[N][2], INV[2];

pii hsh (int l, int r) {
    pii ans;
    ans.F = ((ps[r][0] - ps[l - 1][0] + mod) % mod) * inv[l - 1][0] % mod;
    ans.S = ((ps[r][1] - ps[l - 1][1] + delta) % delta) * inv[l - 1][1] % delta;
    return ans;
}

s = '.' + s;
INV[0] = poww(P, mod - 2, mod);
INV[1] = poww(P, delta - 2, delta);
inv[0][0] = inv[0][1] = pw[0][1] = pw[0][0] = 1;
for (int i = 1; i <= sz; i++) {
    pw[i][0] = pw[i - 1][0] * P % mod;
    pw[i][1] = pw[i - 1][1] * P % delta;
    inv[i][0] = inv[i - 1][0] * INV[0] % mod;
    inv[i][1] = inv[i - 1][1] * INV[1] % delta;
    ps[i][0] = (ps[i - 1][0] + s[i] * pw[i][0]) % mod;
    ps[i][1] = (ps[i - 1][1] + s[i] * pw[i][1]) % delta;
}
