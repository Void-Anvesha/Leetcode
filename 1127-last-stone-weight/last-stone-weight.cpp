class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        //Max Heap
        priority_queue<int> p;
        
        for(int i=0;i<stones.size();i++)
        {
            p.push(stones[i]);
        }
        int x=0,y=0;

        while(p.size()>1)
        {
            x=p.top();
            p.pop();
            y=p.top();
            p.pop();
            if(x==y) continue;
            else p.push(x-y);
        }
        if(p.size()==0) return 0;
        else return p.top();
    }
};