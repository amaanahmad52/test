#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define read(v) for(ll i=0;i<v.size();++i) cin>>v[i]

// Function to count the number of times `factor` appears in `n`
int prime_factors(ll n, ll factor) {
    int count = 0;
    while (n % factor == 0) {
        n /= factor;  // Fix: Divide `n`, not `factor`
        count++;
    }
    return count;
}

void solve() {
    ll n, m;
    cin >> n >> m;

    ll count_2 = prime_factors(n, 2);  // Correctly count 2s in `n`
    ll count_5 = prime_factors(n, 5);  // Correctly count 5s in `n`

    ///2 2 2 2 2 5 5 ,, to maximize zeroes , add up 3 5s so that five 
    //pairs can be made that multiplies each to 10 ==>100000 here
    ll var = 1;

    if (count_2 > count_5) {
        while (var * 5 <= m && count_5 < count_2) {  
            var *= 5;
            count_5++;
        }
    } 
    else {
        while (var * 2 <= m && count_2 < count_5) {  
            var *= 2;
            count_2++;
        }
    }

    // Now it may be possible that var is still < m , so now we can add more 10s directly
    while (var * 10 <= m) {
        var *= 10;
    }

    // Again, it is possible that there are many multiples of var less than m
    ll more_multiples = m / var;
    ll final_var = more_multiples * var;
    ll final_output = final_var * n;

    cout << final_output << endl;
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
