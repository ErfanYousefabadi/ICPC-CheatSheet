int n, cp, p[N];
string s;
int h[LG][N];
 
bool cmp(int a , int b){
  if (h[cp - 1][a] < h[cp - 1][b]) return true;
  else if (h[cp - 1][a] > h[cp - 1][b]) return false; 
  if (a + (1 << (cp - 1)) > n + 1 || b + (1 << (cp - 1)) > n + 1) return a > b; 
  return h[cp - 1][a + (1 << (cp - 1))] < h[cp - 1][b + (1 << (cp - 1))];
}
cin >> s; 
s = '#' + s;  
n = s.size() - 1; 
for (int i = 1; i <= n; i++) {
    h[0][i] = s[i];
    p[i] = i;
}
for (cp = 1; cp < LG; cp++) {
    sort(p + 1, p + n + 1, cmp);
    h[cp][p[1]] = 1; 
    for (int i = 2; i <= n; i++) {
        h[cp][p[i]] = h[cp][p[i - 1]] + cmp(p[i - 1] , p[i]);  
    }
}
p[0] = n + 1;
for (int i = 0; i <= n; i++)
    cout << p[i] << ' ';