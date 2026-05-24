// inverse of BASE
        ll invBase = modPow(BASE, MOD - 2);

        invPower[0] = 1;

        for (int i = 1; i <= n; i++) {
            invPower[i] = (invPower[i - 1] * invBase) % MOD;
        }