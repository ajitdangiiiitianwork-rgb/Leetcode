class MyCalendarThree {
public:
    map<int, int> count;

    MyCalendarThree() {
        
    }
    
    int book(int startTime, int endTime) {
        count[startTime]++;
        count[endTime]--;

        int maxBookings = 0;
        int bookings = 0;
        for(auto& p : count){
            bookings += p.second;
            maxBookings = max(bookings, maxBookings);
        }

        return maxBookings;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(startTime,endTime);
 */