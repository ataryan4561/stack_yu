#include<bits/stdc++.h>
#include<stack>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int> arr(n,0);
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    stack<int> st;
    int ans=arr[0];
    int yo=arr[0];
    for(int i=0; i<n; i++)
    {
        st.push(arr[i]);
        if(st.size()>0 && st.top()<=arr[i])
        {
            ans=st.size()*st.top();
        }
        if(st.size()>0 && st.top()>arr[i])
        {
            if(st.size()*arr[i]>=ans)
            {
                ans=st.size()*arr[i];
            }
            else 
            {
                while(st.size()!=0)
                {
                    st.pop();
                }
            }
        }
    }
    cout<<ans<<endl;
}