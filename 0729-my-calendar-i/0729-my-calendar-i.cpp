class MyCalendar {
public:
    map<int, int> counts;

    MyCalendar() {
        
    }
    
    bool book(int startTime, int endTime) {
        counts[startTime]++;
        counts[endTime]--;

        int bookings = 0;
        for(auto const& p : counts){
            bookings += p.second;
            if(bookings > 1){
                counts[startTime]--;
                counts[endTime]++;

                if(counts[startTime] == 0) {
                    counts.erase(startTime);
                }

                if(counts[endTime] == 0){
                    counts.erase(endTime);
                }

                return false;
            }
        }

        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(startTime,endTime);
 */