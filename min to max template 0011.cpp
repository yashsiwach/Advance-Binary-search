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

bool check(vector<int>&v,int mid,int target)
{
   return v[mid]==target;
}


//000001111111
int mintomax(vector<int>&v,int target)
{
    int ans=-1;
    int low=0,high=v.size()-1;
    while(low<=high)
    {
        int mid=low+(high-low)/2;
        
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

    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++)
    {
        cin>>v[i];    
    }
    int target;
    cin>>target;
    cout<<mintomax(v,target);
    
}

