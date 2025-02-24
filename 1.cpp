#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define read(v) for(ll i=0;i<v.size();++i) cin>>v[i]


int how_many_trailing_zeroes(ll n) {
    int count = 0;
    while (n % 10 == 0) {
        n /= 10;
        ++count;
    }
    return count;
}


vector<int> one_to_ten_which_multiplies_to_give_trailing_zeroes(ll n) {
    vector<int> ans;
    for (int i = 1; i < 10; ++i) {
        if ((n * i) % 10 == 0) {
            ans.push_back(i);
        }
    }
    return ans;
}

void solve() {
    ll n, m;
    cin >> n >> m;

    vector<int> multiples = one_to_ten_which_multiplies_to_give_trailing_zeroes(n);

    ll ans = 0, prod = n * m;  // Store the best product
    for (auto &x : multiples) {
        ll temp_x = x;

        // Keep multiplying x by 10 until it's larger than m
        while (x <= m) {
            int trailing_zeroes = how_many_trailing_zeroes(x * n);
            if (trailing_zeroes > ans || (trailing_zeroes == ans && n * x > prod)) {
                ans = trailing_zeroes;
                prod = n * x;
            }
            x *= 10;
        }

        // Reset x
        x = temp_x;

        // Find the largest number ≤ m ending in x
        ll lastno = (m / 10) * 10 + x;
        if (lastno > m) lastno -= 10;

        // Check trailing zeroes for lastno * n
        int trailing_zeroes = how_many_trailing_zeroes(lastno * n);
        if (trailing_zeroes > ans || (trailing_zeroes == ans && n * lastno > prod)) {
            ans = trailing_zeroes;
            prod = n * lastno;
        }
    }

    // Check powers of 10 up to m
    ll power = 10;
    while (power <= m) {
        int trailing_zeroes = how_many_trailing_zeroes(power * n);
        if (trailing_zeroes > ans || (trailing_zeroes == ans && n * power > prod)) {
            ans = trailing_zeroes;
            prod = n * power;
        }
        power *= 10;
    }

    cout << prod << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
