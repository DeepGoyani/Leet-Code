class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int minrecolor=INT_MAX;
        int white=0;
        int start=0;
        int end=k-1;
        for (int i=0;i<k;i++){
            if(blocks[i]=='W') white++;
        }
        minrecolor=min(minrecolor,white);
        while(end+1<blocks.size()){
            end++;
            if(blocks[end]=='W') white++;

            if(blocks[start]=='W')white--;
            start++;

            minrecolor=min(minrecolor,white);
        }
        return minrecolor;
    }
};