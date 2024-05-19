0(n^2) approach
find the max leftmost element of a hr index and rightmost max element of the index, find the min of both and subtract it with elelment at that index.
add that in array and finally find sum of the array formed
​
class Solution {
public:
int trap(vector<int>& height) {
int n=height.size();
vector<int>ans(n);
for(int i=0;i<n;i++){
int maxi=0;
//to find maximum at right
for(int j=i;j<n;j++){
if(maxi<height[j])maxi=height[j];}
//to find maximum at left
int maxil=0;
for(int k=i;k>=0;k--){
if(maxil<height[k])maxil=height[k];}
int s=(min(maxi,maxil))-(height[i]);
ans[i]=s;
}
int sum1=0;
for(auto g:ans){sum1+=g;}
return sum1;
}
}
;