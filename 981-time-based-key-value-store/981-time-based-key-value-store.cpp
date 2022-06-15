#include <unordered_map>

class TimeMap {

    unordered_map<string, map<int, string>> m;
    
public:
    TimeMap() {
        m.clear();
    }
    
    void set(string key, string value, int timestamp){
        m[key][timestamp] = value;
    }
    
    string get(string key, int timestamp){
        if(m.size()==0 || m.count(key) == 0 || (m[key].upper_bound(timestamp)) == m[key].begin())
            return "";
        else{
            return (*(--m[key].upper_bound(timestamp))).second;
        }
    }
    //T - O(nlogn)
    //S - O(n)
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */