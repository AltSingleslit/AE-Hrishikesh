// Monotonic Stack Template
// ----------------------------------------------------------------------------------------
// Purpose: Compute 1-based index of Previous/Next Smaller/Greater Element for each index
// Usage examples: PSE(arr), NSE(arr), PGE(arr), NGE(arr)

template<typename Compare>
vll mono_stack(const vll &a, bool rev, Compare cmp, ll none_val) {
    int n = sz(a);
    vll res(n, 0);
    stkint stk;

    if (!rev) {
        fi(n) {
            while (!stk.empty() && cmp(a[i], a[stk.top()])) stk.pop();
            res[i] = stk.empty() ? none_val : stk.top() + 1;
            stk.push(i);
        }
    } else {
        rfori(i, n - 1, -1) {
            while (!stk.empty() && cmp(a[i], a[stk.top()])) stk.pop();
            res[i] = stk.empty() ? none_val : stk.top() + 1;
            stk.push(i);
        }
    }
    return res;
}

inline vll PSE(const vll &a) { return mono_stack(a, 0, [](ll a, ll b) { return a < b; }, 0); }
inline vll NSE(const vll &a) { return mono_stack(a, 1, [](ll a, ll b) { return b >= a; }, sz(a) + 1); }
inline vll PGE(const vll &a) { return mono_stack(a, 0, [](ll a, ll b) { return a > b; }, 0); }
inline vll NGE(const vll &a) { return mono_stack(a, 1, [](ll a, ll b) { return b <= a; }, sz(a) + 1); }
// ----------------------------------------------------------------------------------------
