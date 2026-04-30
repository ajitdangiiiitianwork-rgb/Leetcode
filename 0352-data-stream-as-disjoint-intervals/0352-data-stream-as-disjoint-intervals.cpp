class SummaryRanges {
public:
    vector<int> store;
    
    SummaryRanges() {
        
    }
    
    void addNum(int value) {
        store.push_back(value);
    }
    
    vector<vector<int>> getIntervals() {
        vector<vector<int>> result;
        if(store.size() == 0) return result; 
        sort(store.begin(), store.end());
        

        int l = -1;
        int r = -1;

        for(int i = 0; i < store.size(); i++){
            if(l == -1 && r == -1){
                l = store[i];
                r = store[i];
            } else if(store[i] == r + 1 || store[i] == r){
                r = store[i];
            } else {
                result.push_back({l, r});
                l = store[i];
                r = store[i];
            }
        }
        result.push_back({l, r});

        return result;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */