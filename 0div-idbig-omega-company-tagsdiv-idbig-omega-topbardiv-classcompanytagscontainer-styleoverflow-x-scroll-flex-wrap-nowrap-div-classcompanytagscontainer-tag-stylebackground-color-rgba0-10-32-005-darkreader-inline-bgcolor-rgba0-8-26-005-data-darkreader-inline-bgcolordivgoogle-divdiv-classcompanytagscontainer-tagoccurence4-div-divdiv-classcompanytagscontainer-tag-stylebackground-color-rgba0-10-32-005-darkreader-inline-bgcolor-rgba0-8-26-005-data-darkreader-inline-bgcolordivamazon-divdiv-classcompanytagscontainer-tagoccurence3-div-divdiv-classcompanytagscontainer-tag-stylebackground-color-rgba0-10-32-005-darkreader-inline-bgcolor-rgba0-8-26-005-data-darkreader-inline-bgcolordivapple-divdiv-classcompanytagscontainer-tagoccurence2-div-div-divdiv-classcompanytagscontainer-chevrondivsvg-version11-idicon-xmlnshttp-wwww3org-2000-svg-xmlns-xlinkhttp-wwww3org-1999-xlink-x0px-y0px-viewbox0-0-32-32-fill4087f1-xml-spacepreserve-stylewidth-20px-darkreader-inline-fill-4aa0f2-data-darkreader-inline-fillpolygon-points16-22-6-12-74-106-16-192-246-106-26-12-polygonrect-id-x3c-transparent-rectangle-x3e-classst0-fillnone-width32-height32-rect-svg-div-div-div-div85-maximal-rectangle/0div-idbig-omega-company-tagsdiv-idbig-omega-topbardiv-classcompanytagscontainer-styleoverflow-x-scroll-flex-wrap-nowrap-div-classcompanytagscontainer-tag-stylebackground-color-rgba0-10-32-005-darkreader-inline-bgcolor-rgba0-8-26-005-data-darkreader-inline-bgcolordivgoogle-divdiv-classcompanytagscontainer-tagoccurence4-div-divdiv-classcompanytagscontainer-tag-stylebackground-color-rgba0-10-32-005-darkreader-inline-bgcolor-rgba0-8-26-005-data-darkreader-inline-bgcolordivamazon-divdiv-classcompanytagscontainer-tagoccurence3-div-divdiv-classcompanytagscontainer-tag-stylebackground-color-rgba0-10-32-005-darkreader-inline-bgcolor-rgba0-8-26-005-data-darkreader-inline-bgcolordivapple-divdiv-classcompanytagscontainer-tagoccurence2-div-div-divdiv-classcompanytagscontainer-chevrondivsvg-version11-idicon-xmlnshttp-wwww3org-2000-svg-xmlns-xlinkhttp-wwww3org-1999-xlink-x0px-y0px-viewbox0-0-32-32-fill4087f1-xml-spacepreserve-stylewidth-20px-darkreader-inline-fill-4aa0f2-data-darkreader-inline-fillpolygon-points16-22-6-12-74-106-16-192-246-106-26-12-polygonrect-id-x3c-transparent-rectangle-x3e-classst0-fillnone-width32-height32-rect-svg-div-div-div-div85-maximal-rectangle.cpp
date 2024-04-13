class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        vector<int>leftSmaller(n);
        vector<int>rightSmaller(n);
        
        stack<int>st,st1;
        
        for(int i=0;i<n;i++){
            
            while(!st.empty() and heights[st.top()]>=heights[i])
                st.pop();
            
            if(st.empty())
                leftSmaller[i]=0;
            
            else if(heights[st.top()]<heights[i])
                leftSmaller[i]=st.top()+1;
            
            st.push(i);
        }
        
        
        for(int i=n-1;i>=0;i--){
            
            while(!st1.empty() and heights[st1.top()]>=heights[i])
                st1.pop();
            
            if(st1.empty())
                rightSmaller[i]=n-1;
            
            else if(heights[st1.top()]<heights[i])
                rightSmaller[i]=st1.top()-1;
                
            st1.push(i);
            
        }
        int ans=0;
        for(int i=0;i<n;i++)
            ans=max(ans, (rightSmaller[i]-leftSmaller[i]+1)*heights[i]);
        
        return ans;
    }
    
    
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<int>height(m,0);
        int ans=0;
        
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]=='1')
                    height[j]++;
                else 
                    height[j]=0;
            }
            
            int area=largestRectangleArea(height);
            
            ans=max(ans,area);
        }
        
        return ans;
    }
};