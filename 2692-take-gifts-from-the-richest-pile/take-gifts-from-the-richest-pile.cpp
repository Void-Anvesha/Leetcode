class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        // Max Heap
        priority_queue<int> p;

        for(int i=0;i<gifts.size();i++)
        {
            p.push(gifts[i]);
        }
        int x=0;
        while(k!=0 && !p.empty())
        {
           x=p.top();
           p.pop();
           p.push(sqrt(x));
           k--;
        }
        long long sum=0;
        while(!p.empty())
        {
            sum+=p.top();
            p.pop();
        }
        return sum;

    }
};