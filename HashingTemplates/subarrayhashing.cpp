#include <iostream>
#include <vector>
using namespace std;

class RollingHash {
private:
    using ll = long long;

    static const ll MOD = 1000000007;
    static const ll BASE = 911382323;

    vector<ll> pref;      // prefix hash
    vector<ll> power;     // BASE^i
    vector<ll> invPower;  // inverse(BASE^i)

    ll modPow(ll a, ll b) {
        ll res = 1;

        while (b > 0) {
            if (b & 1)
                res = (res * a) % MOD;

            a = (a * a) % MOD;
            b >>= 1;
        }

        return res;
    }

public:

    // constructor
    RollingHash(const vector<int>& arr) {

        int n = arr.size();

        pref.resize(n);
        power.resize(n + 1);
        invPower.resize(n + 1);

        power[0] = 1;

        for (int i = 1; i <= n; i++) {
            power[i] = (power[i - 1] * BASE) % MOD;
        }

        // inverse of BASE
        ll invBase = modPow(BASE, MOD - 2);

        invPower[0] = 1;

        for (int i = 1; i <= n; i++) {
            invPower[i] = (invPower[i - 1] * invBase) % MOD;
        }

        // build prefix hash
        pref[0] = arr[0];

        for (int i = 1; i < n; i++) {

            pref[i] = ( pref[i - 1] + arr[i] * power[i] ) % MOD;
        }
    }

    // get hash of subarray [l...r]
    long long getHash(int l, int r) {

        ll ans = pref[r];

        if (l > 0) {
            ans = (ans - pref[l - 1] + MOD) % MOD;
        }

        // divide by BASE^l
        ans = (ans * invPower[l]) % MOD;

        return ans;
    }
};

int main() {

    vector<int> arr = {5, 1, 2, 3, 1, 2};

    RollingHash rh(arr);

    cout << rh.getHash(1, 2) << endl;
    cout << rh.getHash(4, 5) << endl;
}