// Modular power using binary exponentiation
ll modpow(ll base, ll exp, ll mod) {
  ll res = 1;
  base %= mod;
  while (exp > 0) {
    if (exp%2==1) res = (res * base) % mod;
    base = (base * base) % mod;
    exp >>= 1;
  }
  return res;
}
