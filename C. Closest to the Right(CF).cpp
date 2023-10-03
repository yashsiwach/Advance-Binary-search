//https://codeforces.com/edu/course/2/lesson/6/1/practice/contest/283911/problem/C
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
#define debug(x) cerr<<x<<" ";
 
bool check(vector<ll>&v,ll mid,ll target)
{
   return v[mid]>=target;
}
 
 
//000001111111
ll mintomax(vector<ll>&v,ll target)
{
    ll ans=v.size();
    ll low=1,high=v.size()-1;
    while(low<=high)
    {
        ll mid=low+(high-low)/2;
        
        if(check(v,mid,target))
        {
            ans=mid;
            high=mid-1;
        }
        else
        {
            low=mid+1;
            
        }
    }
    return ans;
 
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,k;
    cin>>n>>k;
    vector<ll>v(n+1,0);
    for(ll i=1;i<=n;i++)
    {
        cin>>v[i];
    }
    while(k--)
    {
        ll target;
        cin>>target;
        
       cout<<mintomax(v,target)<<endl;
 
    }
    
}
 