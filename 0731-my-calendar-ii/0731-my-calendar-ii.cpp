class MyCalendarTwo {
public:
    map<int,int> counts;

    MyCalendarTwo() {
    
    }
    
    bool book(int startTime, int endTime) {
        counts[startTime]++;
        counts[endTime]--;

        // LSA algo
        int bookings = 0;
        for(auto const& p : counts){
            bookings += p.second;
            if(bookings > 2){
                counts[startTime]--;
                counts[endTime]++;
                return false;
            }
        }
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(startTime,endTime);
 */