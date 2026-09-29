class Node{
public:
    int data;
    int row;
    int col;
    Node(int d,int r,int c){
        data=d;
        row=r;
        col=c;
    }
};
class compare{
public:
    bool operator()(Node* a,Node* b){
        return a->data>b->data;
    }
};
class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        priority_queue<Node*,vector<Node*>,compare> pq;
        int maxi=INT_MIN;
        for(int i=0;i<nums.size();i++){
            pq.push(new Node(nums[i][0],i,0));
            maxi=max(maxi,nums[i][0]);
        }
        int start=0,end=INT_MAX;
        while(!pq.empty()){
            Node* temp=pq.top();
            pq.pop();
            int mini=temp->data;
            if(maxi-mini<end-start){
                start=mini;
                end=maxi;
            }
            int r=temp->row;
            int c=temp->col;
            if(c+1<nums[r].size()){
                pq.push(new Node(nums[r][c+1],r,c+1));
                maxi=max(maxi,nums[r][c+1]);
            }
            else{
                break;
            }
        }
        return {start,end};
    }
};