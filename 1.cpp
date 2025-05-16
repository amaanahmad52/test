#include <bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
public:
   
    void solve() {
        ll b,c,d;
        cin>>b>>c>>d;
        
        ll a=d;
        
        for(int i=0;i<64;i++){
            if((d&(1ll<<i)) and (c&(1ll<<i))){  //d and c have set bits at i
                //make 0 at ith position of a
                a = a & ~(1ll << i);
                
            }
        }

        //extra bits should be in both b and c (extra bit means , unset bit of d) else set a
        for(int i=0;i<64;i++){
            if((b&(1ll<<i)) and (c&(1ll<<i)) and !(d&(1ll<<i))){  //b and c have set bits at i
                //make 1 at ith position of a
                a = a | (1ll << i);
            }
        }
        if((a|b) - (a&c)!=d){
            cout<<-1<<endl;
            return;
        }
        cout<<a<<endl;


        

    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    Solution s;
    while (t--) s.solve();
}
