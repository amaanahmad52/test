#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vpll = vector<pair<ll, ll>>;
using vvi = vector<vi>;

#define read(v) for (int i = 0; i < v.size(); ++i) cin >> v[i]
#define Prn(x) cout << (x) << '\n'

using pll = pair<ll,ll> ;

int digits(ll n){
    int cnt=0;
    while(n){
        n/=10;
        cnt++;
    }
    return cnt;
}
int countDecimalTrailingZeroes(int num) {
    int count = 0;
    while (num % 10 == 0 && num > 0) {  // Check divisibility by 10
        count++;
        num /= 10;  // Remove last zero
    }
    return count;
}
void solve() {
    ll n,m;cin>>n>>m;
    vll v(n);read(v);
    
    //make a vector pair, of number, number of trailing zeroes in that number and sort it as per pair second element

    vpll vp;
    for (int i = 0; i < n; i++) {
        vp.push_back({v[i], countDecimalTrailingZeroes(v[i])});
    }

    sort(vp.begin(),vp.end(),[](pll a,pll b){
        return a.second>b.second;
    });

    int ok=0;
    bool anna=1;
    for(int i=0;i<vp.size();i++){

        // cout<<vp[i].first<<" "<<vp[i].second<<endl;
        if(vp[i].second==0){
            //if no trailing zeroes
            ok+=digits(vp[i].first);
        }
        else{
            if(anna){
                ll no_of_zeroes=vp[i].second;
                ll no_of_digits=digits(vp[i].first);
                
                no_of_digits-=no_of_zeroes;
                ok+=no_of_digits;
                anna=0;

            }
            else{
                ll no_of_digits=digits(vp[i].first);
                
                ok+=no_of_digits;
                anna=1;
            }
        }
    }

    if(ok>=m+1)Prn("Sasha");
    else Prn("Anna");
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}