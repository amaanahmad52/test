#include <bits/stdc++.h>
using namespace std;



class Solution {
public:
    bool good(int i,int j,int n,int m){
        return i>=0 and j>=0 and i<n and j<m;
    }
    void solve() {
        int n,m;cin>>n>>m;
        vector<vector<char>>mat(n,vector<char>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>mat[i][j];
            }
        } 
        // set<pair<int,int>>vis;
        //getting all the safe cells
        //top row
        vector<pair<int,int>>safe;
        for(int i=0;i<m;i++){
            if(mat[0][i]=='U'){
                safe.push_back({0,i});
                // vis.insert({0,i});
                mat[0][i]='#';
            }
        }
        //right column
        for(int i=0;i<n;i++){
            if(mat[i][m-1]=='R'){
                safe.push_back({i,m-1});
                // vis.insert({i,m-1});
                mat[i][m-1]='#';
            }
        }
        //bottom row
        for(int i=0;i<m;i++){
            if(mat[n-1][i]=='D'){
                safe.push_back({n-1,i});
                // vis.insert({n-1,i});
                mat[n-1][i]='#';
            }
        }
        //left column
        for(int i=0;i<n;i++){
            if(mat[i][0]=='L'){
                safe.push_back({i,0});
                // vis.insert({i,0});
                mat[i][0]='#';
            }
        }


        //all those cells which points to safe cell is also safe
        for(int i=0;i<safe.size();i++){
            int r=safe[i].first,c=safe[i].second;
            char top=r-1>=0?mat[r-1][c]:'#';
            char right=c+1<m?mat[r][c+1]:'#';
            char bottom=r+1<n?mat[r+1][c]:'#';
            char left=c-1>=0?mat[r][c-1]:'#';
            if(top=='D'){
                safe.push_back({r-1,c});
                mat[r-1][c]='#';
            }
            if(right=='L'){
                safe.push_back({r,c+1});
                mat[r][c+1]='#';
            }
            if(bottom=='U'){
                safe.push_back({r+1,c});
                mat[r+1][c]='#';
            }
            if(left=='R'){
                safe.push_back({r,c-1});
                mat[r][c-1]='#';
            }
        }

        //now all those cells which are completely surrounded by safe cells are also safe
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]!='?')continue; //we only checking blanks
               
                bool ok=1;
                for(int x=-1;x<=1;x++){
                    for(int y=-1;y<=1;y++){
                        if(x==0 or y==0){
                            //means only 4 surrounding sides
                            //all surrounding sides should have only safe cells
                            int nr=i+x,nc=j+y;
                            if(x==0 and y==0)continue;
                            if(good(nr,nc,n,m) and mat[nr][nc]!='#'){ //surrounding is unsafe
                                
                                ok=0;
                            }
                        }
                        if(!ok)break;   
                        
                    }
                }
                if(ok){
                    // safe.push_back({i,j});
                    mat[i][j]='#';
                }
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]=='#')ans++;
            }
        }
        cout<<n*m-ans<<endl;
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
