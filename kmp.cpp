int k = 0;
f[0] = -1;
for (int i = 2; i <= n; i++) {
    while (k != -1 && s[k] != s[i - 1]) k  = f[k];
    f[i] = ++k;
}