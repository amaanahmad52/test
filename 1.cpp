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



void solve() {
    ll n,m;cin>>n>>m;
    string s;cin>>s;
    vector<vector<ll>>a(n,vector<ll>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>a[i][j];
        }
    }
    vll colsum(m,0),rowsum(n,0);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            rowsum[i]+=a[i][j];
            colsum[j]+=a[i][j];
        }
    }
    ll curRow=0,curCol=0;
    for(int i=0;i<s.size();i++){
        if(s[i]=='D'){
            //we need to make current row sum as 0 , so  update matrix a[i][j] value and update colsum accordingly
            a[curRow][curCol]=-rowsum[curRow];
            colsum[curCol]-=rowsum[curRow];
            rowsum[curRow]=0;
            curRow++;
        }
        else{
            //we need to make current col sum as 0 , so  update matrix a[i][j] value and update rowsum accordingly
            a[curRow][curCol]=-colsum[curCol];
            rowsum[curRow]-=colsum[curCol];
            colsum[curCol]=0;
            curCol++;
        }

    }
    if (curRow == n - 1 && curCol == m - 1) {
        a[curRow][curCol] = -rowsum[curRow];
        colsum[curCol] -= rowsum[curRow];
        rowsum[curRow] = 0;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }

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