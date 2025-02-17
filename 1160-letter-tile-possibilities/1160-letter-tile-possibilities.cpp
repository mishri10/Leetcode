class Solution {
public:
    int ans=0;
    void helper(int ind, string tiles){
    ans++;
    for(int i=ind; i<tiles.size(); i++){
        if(i!=ind and tiles[i]==tiles[ind])
            continue;
        swap(tiles[i],tiles[ind]);
        helper(ind+1,tiles);
        //swap(tiles[i],tiles[ind]);


    }return;}
    int numTilePossibilities(string tiles) {
        sort(tiles.begin(),tiles.end());
        helper(0,tiles);
        return ans-1;
    }
};