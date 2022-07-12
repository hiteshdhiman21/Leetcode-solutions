struct hash_pair {
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2>& p) const
    {
        auto hash1 = hash<T1>{}(p.first);
        auto hash2 = hash<T2>{}(p.second);
        return (hash1*7 ^ hash2*13)/7;
    }
};

class DetectSquares {
    
    unordered_map<pair<int,int>, int, hash_pair> cntPoints;
    
public:
    
    void add(vector<int> point) {
        cntPoints[{point[0],point[1]}]++;
    }
    
    int count(vector<int> point) {
        int x1 = point[0], y1 = point[1];
        int res = 0;
        
        //Just Iterating over the possible diagnol points and using it finding other two points. 
        for(auto& [_, cnt]: cntPoints){
            int x3 = _.first, y3 = _.second;
            if(abs(x3-x1) != 0 &&  abs(x3-x1) == abs(y3-y1) && cntPoints.count({x1, y3}) && cntPoints.count({x3, y1}))
                res += cntPoints[{x3, y3}]*cntPoints[{x1, y3}]*cntPoints[{x3, y1}];
        }
        
        return res;
    }
    //T - O(n) for each count query and O(1) for each add query
    //S - O(n)
};

/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 */