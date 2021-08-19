#include<bits/stdc++.h>
#include<stack>
using namespace std;
int main()
{
    int arr[4]={1,3,2,4};
    vector<int> ans;
    stack<int> st;
    for(int i=3; i>=0; i--)
    {
            if(st.size()==0)
            {
                ans.push_back(-1);
            }
            else if(st.size()>0 && st.top()>arr[i])
            {
                ans.push_back(st.top());
            }
            else if(st.size()>0 && st.top()<=arr[i])
            {
                while(st.size()>0 && st.top()<=arr[i])
                {
                    st.pop();
                }
                if(st.size()==0)
                {
                    ans.push_back(-1);
                }
                if(st.top()>arr[i])
                {
                    ans.push_back(st.top());
                }
            }
            st.push(arr[i]);
            // cout<<st.top()<<" ";
    }
    for(int i=ans.size()-1; i>=0; i--)
    {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}