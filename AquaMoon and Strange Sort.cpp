#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

#define int long long int
#define double double_t
#define INF 1e18
using namespace __gnu_pbds;
using namespace std;
template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int GCD(int a, int b) {
    if (b == 0) {
        return a;
    }
    return GCD(b, a % b);
}

int power(int x, int y, int MOD = INF) {
    if (y == 0) {
        return 1;
    }
    if (y % 2 == 0) {
        return power((x * x) % MOD, y / 2) % MOD;
    } else {
        return (x * power((x * x) % MOD, (y - 1) / 2) % MOD) % MOD;
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<pair<int,int>> arr(n);
        map<int,int> cnt;
        for(int i=0;i<n;i++){
            cin>>arr[i].first;
            cnt[arr[i].first]++;
            arr[i].second=i;
        }
        sort(arr.begin(),arr.end());
        vector<int> arr2(n);
        map<int,vector<int>> aux;
        for(int i=0;i<n;i++){
            aux[arr[i].first].push_back(abs(arr[i].second-i) & 1);
        }
        bool ans=true;

        for(auto p:aux){
            int count=0;
            for(auto num:p.second){
                if(num==1){
                    count++;
                }
            }
            if(count & 1){
                ans=false;
                break;
            }
        }
        if(ans){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
}