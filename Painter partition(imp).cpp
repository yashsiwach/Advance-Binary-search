//link:https://www.codingninjas.com/studio/problems/painter-s-partition-problem_1089557?leftPanelTab=0
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

int check(int x,vector<int>&v,int &k)
{
    int time=x;
    int worker=1;
    int i=0;
    int maxi=INT_MIN;
    for(int i=0;i<v.size();i++)
    {
        maxi=max(v[i],maxi);
    }
    
    while(i<v.size()){
    //checking if any value is greater then total time of any worker then not possible
    if(maxi>x)
    {
        return 0;
    }

    else
    {
    //if worker needed more than required than return 0
        if(worker>k)
        {
            return 0;
        }
        // subtract the time of each wall from starting untill hours of worker overs 
        if(v[i]<=time)
        {
            time-=v[i];
            i++;
            //if reach last wall than success
            if(i==v.size()) return 1;
        }
        //if time over call the next worker and reset the time 
        else
        {
            worker++;
            time=x;
        }
    }

}

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    clock_t time_req=clock();

    int n,k,ans=0;
    cin>>n>>k;

    vector<int>v;
    while(n--)
    {
        int temp;
        cin>>temp;
        v.push_back(temp);
    }
    //To make the range of binary search max time is 1 worker paint all walls
    int sum =0;
    for(auto i:v)
    {
        sum+=i;
    }
    //checking the min number btw the 0 and max time which show the all walls successfully painted if yes //then 1 and find other smaller time ,other wise 0 no possible to paint 
    int l=0,h=sum;
    while(l<=h)
    {
        int mid=(l+h)/2;
        if(check(mid,v,k))
        {
            ans=mid;
            h=mid-1;
        }
        else
        {
            l=mid+1;
        }
    }
    cout<<ans<<endl;



#ifndef ONLINE_JUDGE
    cout<<endl<<"Time: "<<fixed<<setprecision(6)<<((double)(clock()-time_req))/CLOCKS_PER_SEC<<endl;
#endif
}

