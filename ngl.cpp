#include<bits/stdc++.h>
#include<stack>
using namespace std;
int main()
{
    int arr[4]={1,3,2,4};
    stack<int> st;
    vector<int> ans;
    for(int i=0; i<4; i++)
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
            // ngl ka code hai check karo sahi hai 
            else if(st.top()>arr[i])
            {
                ans.push_back(st.top());
            }
        }
        st.push(arr[i]);
    }
    for(int i=0; i<ans.size(); i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}