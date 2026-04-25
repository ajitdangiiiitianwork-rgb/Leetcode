class MyCalendarTwo {
public:
    vector<vector<int>> bookings;
    vector<vector<int>> overlapBookings;

    MyCalendarTwo() {
    
    }
    
    bool book(int startTime, int endTime) {
        if(bookings.size() == 0){
            bookings.push_back({startTime, endTime - 1});
            return true;
        }

        // check if the interval is overlapping witn any interval in overlappingBookings -> three overlap intervals
        for(int i = 0; i < overlapBookings.size(); i++){
            if(endTime - 1 >= overlapBookings[i][0] && overlapBookings[i][1] >= startTime){
                // intersection is there -> three overlapping intervals
                return false;
            }
        }

        for(int i = 0; i < bookings.size(); i++){
            if(endTime - 1 >= bookings[i][0] && bookings[i][1] >= startTime){
                // intersection with interval in bookings
                // add in overlapBookings
                int s = max(startTime, bookings[i][0]);
                int e = min(endTime-1, bookings[i][1]);
                overlapBookings.push_back({s,e});
            }
        }

        bookings.push_back({startTime, endTime-1});
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(startTime,endTime);
 */