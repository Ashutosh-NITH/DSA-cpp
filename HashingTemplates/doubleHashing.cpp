#include <iostream>
#include <vector>
#include <chrono>   // for seed
#include <random>   // for mt19937_64 and uniform_int_distribution
using namespace std;

class RollingHash {
private:
    using ll = long long;

    static const ll MOD1  = 1000000007LL;
    static const ll MOD2  = 998244353LL;

    static ll getBase1() {
    static ll val = 0;

        if (val == 0) {                                           // first time only
            ll seed = chrono::steady_clock::now()
                        .time_since_epoch()
                        .count();
            mt19937_64 rng(seed);
            val = uniform_int_distribution<ll>(1e9, 2e9)(rng);
        }

        return val;
    }

    static ll getBase2() {
        static ll val = 0;

        if (val == 0) {
            ll seed = chrono::steady_clock::now()
                        .time_since_epoch()
                        .count() + 1;   // +1 so seed differs from getBase1
            mt19937_64 rng(seed);
            val = uniform_int_distribution<ll>(2e9, 4e9)(rng);
        }

        return val;
    }

    vector<ll> pref1, pref2;
    vector<ll> power1, power2;
    vector<ll> invPower1, invPower2;

    ll modPow(ll a, ll b, ll mod) {        // ← mod is now a parameter
        ll res = 1;
        a %= mod;
        while (b > 0) {
            if (b & 1) res = res * a % mod;
            a = a * a % mod;
            b >>= 1;
        }
        return res;
    }

    void build(const vector<int>& arr,
               ll base, ll mod,
               vector<ll>& pref,
               vector<ll>& power,
               vector<ll>& invPower)
    {
        int n = arr.size();
        pref.resize(n);
        power.resize(n + 1);
        invPower.resize(n + 1);

        power[0] = 1;
        for (int i = 1; i <= n; i++)
            power[i] = power[i-1] * base % mod;

        ll invBase = modPow(base, mod - 2, mod);
        invPower[0] = 1;
        for (int i = 1; i <= n; i++)
            invPower[i] = invPower[i-1] * invBase % mod;

        pref[0] = arr[0] % mod;
        for (int i = 1; i < n; i++)
            pref[i] = (pref[i-1] + (ll)arr[i] * power[i]) % mod;
    }

public:
    RollingHash(const vector<int>& arr) {
        build(arr, getBase1(), MOD1, pref1, power1, invPower1);
        build(arr, getBase2(), MOD2, pref2, power2, invPower2);
    }

    // Returns a single 64-bit key combining both hashes
    long long getHash(int l, int r) {
        auto query = [&](vector<ll>& pref, vector<ll>& invPower, ll mod) -> ll {
            ll ans = pref[r];
            if (l > 0) ans = (ans - pref[l-1] + mod) % mod;
            return ans * invPower[l] % mod;
        };

        ll h1 = query(pref1, invPower1, MOD1);
        ll h2 = query(pref2, invPower2, MOD2);

        return h1 * MOD2 + h2;   // unique 64-bit key
    }
};

int main() {

    vector<int> arr = {5, 1, 2, 3, 1, 2};

    RollingHash rh(arr);

    cout << rh.getHash(1, 2) << endl;
    cout << rh.getHash(4, 5) << endl;
}