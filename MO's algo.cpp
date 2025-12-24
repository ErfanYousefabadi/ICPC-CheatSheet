bool cmp(Query A, Query B)
{
  if (A.l / S ！= B.l / S) return A.l / S < B.l / S;
  return A.r > B.r
}
// erfan
bool cmp(pair<pii, int> a, pair<pii, int> b) {
  if (a.F.F / SQ != b.F.F / SQ) return a.F.F < b.F.F;
  return ((a.F.F / SQ) & 1) ? (a.F.S > b.F.S) : (a.F.S < b.F.S);
}
