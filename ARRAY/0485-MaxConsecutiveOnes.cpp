class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& str) {
    int st=0,end=0,zeroc=0,maxl=0;
    for(;end<str.size();end++){          
        if(str[end]==0){                 
            zeroc++;
        }
       while(zeroc){
    if(str[st] == 0){
        zeroc--;
    }
    st++;
}
        maxl=max(maxl,end-st+1);
    }
    return maxl;
    }
};