class Solution {
public:
    int largestRectangleArea(vector<int>& arr) {
        stack<int>st;
        
        int n=arr.size();
        vector<int>leftSmaller(n);
        vector<int>rightSmaller(n);
        
        for(int i=0;i<n;i++){
            while(!st.empty() and arr[st.top()]>=arr[i])st.pop();
            if(st.empty())leftSmaller[i]=0;
            else leftSmaller[i]=st.top()+1;
            
            st.push(i);
            
        }
        while(!st.empty())
            st.pop();
        
        for(int i=n-1;i>=0;i--){
            while(!st.empty() and arr[st.top()]>=arr[i])st.pop();
            if(st.empty())rightSmaller[i]=n-1;
            else rightSmaller[i]=st.top()-1;
            
            st.push(i);
            
        }
        
        int ans=0;
        
        for(int i=0;i<n;i++){
            ans=max(ans,(rightSmaller[i]-leftSmaller[i]+1)*arr[i]);
        }
        return ans;        
        
    }
};