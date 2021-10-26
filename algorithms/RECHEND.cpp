#include <bits/stdc++.h>
using namespace std;
#define nline "\n"
#define TLE_ka_Chakkar ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
ll mod = 1e9+7;
ll expo(ll a, ll b, ll mod) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}
struct Cell{
    int row,col;
};
void solve(){
    int n;cin >> n;
    vector<Cell> v(n);
    for(int i = 0; i < n; i++){
        int r,c;cin >> r >> c;
        v[i].row = r;
        v[i].col = c;
    }
    sort(v.begin(),v.end(),[](Cell a, Cell b){
        return a.row < b.row;
    });
    // for(int i = 0; i < n; i++){
    //     cout << v[i].row << " " << v[i].col << nline;
    // }
    int TTL = -1, BTR = -1;
    for(int i = 1; i < n; i++){
        if(v[i].col == v[i-1].col -1)
            TTL = i;
        else
            break;
    }
    for(int i = n - 2; i >= 0; i--){
        if(v[i].col == v[i+1].col - 1)
            BTR = i;
        else
            break;
    }
    if(v[TTL].col == 1 || v[BTR].col == n)
        cout << "NO\n";
    else
        cout << "YES\n";
}
int main()
{
    TLE_ka_Chakkar
    #ifndef ONLINE_JUDGE
        cerr << "Time : " << 1000*((double)clock())/(double)CLOCKS_PER_SEC << "ms\n";
    #endif
    #ifndef ONLINE_JUDGE
        freopen("Error.txt", "w", stderr);
    #endif

    ll test;
    cin >> test;
    while(test--){
        solve();
    }
    return 0;
}
// Input 
// 2
// 3
// 1 2
// 2 3
// 3 1
// 2
// 1 2
// 2 1


// Output
// YES
// NO
