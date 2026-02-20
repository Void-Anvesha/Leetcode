class Solution {
public:
    string largestNumber(vector<int>& nums) {
        
        vector<string>numbers;

        //converting int to str
        //then storing to sort 
        for(int i = 0; i < nums.size(); i++){
            numbers.push_back(to_string(nums[i]));
        }

        auto myComparator = [](string& s1 , string& s2){
             if(s1+s2 > s2+s1)return true;

             return false;
        };

        sort(numbers.begin() , numbers.end() , myComparator);

        ///Edge case
        if(numbers[0] == "0")return "0";

        string res = "";
        for(auto& s : numbers){
            res += s;
        }
    return res;
    }
};