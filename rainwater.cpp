#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> arr;
    int n;
    cin>>n;
    for(int i=0; i<n; i++)
    {
        int x;
        cin>>x;
        arr.push_back(x);
    }
    vector<int>max_r(n,0);
    vector<int> max_l(n,0);
    max_l[0]=arr[0];
    max_r[n-1]=arr[n-1];
    for(int i=1; i<n; i++)
    {
        max_l[i]=max(max_l[i-1],arr[i]);
    }
    for(int i=n-2; i>=0; i--)
    {
        max_r[i]=max(max_r[i+1],arr[i]);
    }
    int ans=0;
    for(int i=0; i<n; i++)
    {
        ans=ans+(min(max_r[i],max_l[i])-arr[i]);
    }
    cout<<ans<<endl;
}