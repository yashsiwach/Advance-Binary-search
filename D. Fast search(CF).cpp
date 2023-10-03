// https://codeforces.com/edu/course/2/lesson/6/1/practice/contest/283911/problem/D
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD 1000000007
#define pb push_back
#define ppb pop_back
#define ff first
#define ss second
#define PI 3.141592653589793238462
#define set_bits __builtin_popcountll
#define all(x) (x).begin(), (x).end()
#define debug(x) cerr << x << " ";
 
// bool check(vector<ll>& v, ll mid, ll target) {
//     return v[mid] >= target;
// }
 
ll f1(vector<ll>& v, ll x) {
    int n = v.size();
    int low = 0;
    int high = n - 1;
    int mid;
    int ans = v.size();
    while (low <= high) {
        mid = (low + high) / 2;
        if (v[mid] > x) {
            ans = mid;
            high = mid - 1;
        }
        else {
            low = mid + 1;
 
        }
    }
    return ans;
}
 
ll f2(vector<ll>& v, ll x) {
    int n = v.size();
    int low = 0;
    int high = n - 1;
    int mid;
    int ans = v.size();
    while (low <= high) {
        mid = (low + high) / 2;
        if (v[mid] >= x) {
            ans = mid;
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }
    return ans;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin >> n;
    vector<ll> v(n);
 
    for (ll i = 0; i < n; i++) {
        cin >> v[i];
    }
 
    sort(v.begin(), v.end());
 
    ll k;
    cin >> k;
 
    while (k--) {
        ll a, b;
        cin >> a >> b;
 
        cout << f1(v, b) - f2(v, a) << endl;
 
    }
}