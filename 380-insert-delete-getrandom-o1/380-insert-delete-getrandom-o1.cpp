class RandomizedSet {
    vector<int> nums;
    unordered_map<int, int> valInd;
public:
    RandomizedSet() {
    }
    
    bool insert(int val) {
        if(valInd.count(val)) return false;
        nums.push_back(val);
        valInd[val] = nums.size()-1;
        return true;
    }
    
    bool remove(int val) {
        if(valInd.count(val) == 0) return false;
        int indOfVal = valInd[val];
        valInd[nums.back()] = indOfVal;
        swap(nums.back(), nums[indOfVal]);
        nums.pop_back();
        valInd.erase(val);
        return true;
    }
    
    int getRandom() {
        int ind = rand()%(nums.size());
        return nums[ind];
    }
    //T - O(1) for each operation
    //S - O(n)
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */