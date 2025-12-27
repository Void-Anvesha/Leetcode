class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        
        int m= meetings.size();
        //Sort by start time
        //O(m og n)
        sort(meetings.begin() , meetings.end());

        //lastAvailableAt[i] = Room 'i' will be last available at
        vector<long long >lastAvailableAt(n,0);

        //roomsUsedCnt[i] = Room i is used how many times
        vector<int>roomUsedCnt(n,0);

        for(vector<int>& meet : meetings){//O(m)

            int start = meet[0];
            int end = meet[1];
            int duration = end-start;
            bool found = false;
            
            long long earlyEndRoomTime = LLONG_MAX;
            int earlyEndRoom = 0;
             //find the first avl room forr my current meeting
             for(int room=0; room < n; room++ ){//O(n)
                if(lastAvailableAt[room] <= start){
                   lastAvailableAt[room] = end; 
                   roomUsedCnt[room]++;
                   found = true;
                   break;
                }
                //Which room will get empty first 
                if(lastAvailableAt[room] < earlyEndRoomTime){
                    earlyEndRoomTime = lastAvailableAt[room];
                    earlyEndRoom = room;
                }
             }

             //I couldn't find any room
             if(!found){
              //Pick that room that ends first
              lastAvailableAt[earlyEndRoom] += duration;
              roomUsedCnt[earlyEndRoom]++;
             }
        }
      int resultRoom = -1;
      int maxUse=0;

      for(int room=0; room<n; room++){
        if(roomUsedCnt[room] > maxUse){
            maxUse=roomUsedCnt[room];
            resultRoom=room;
        }
      }
      return resultRoom;




    }
};