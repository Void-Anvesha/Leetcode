// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:

    int firstBadVersion(int n) {
        long long left=0;
        long long right=n;
        int firstBadVersion;
        while(left<=right)
        {
            int mid=(left+right)/2;
             if(isBadVersion(mid))
             {
                firstBadVersion=mid;
                right=mid-1;
             }
             else left=mid+1;
             
        }
       return firstBadVersion;
    }
};