//Q380
#include <bits/stdc++.h>
using namespace std;
class RandomizedSet
{
private:
    vector<int> nums;
    unordered_map<int, int> valTOInd;

public:
    RandomizedSet()
    {
    }

    bool insert(int val)
    {
        if (valTOInd.find(val) != valTOInd.end())
            return false;
        nums.push_back(val);
        valTOInd[val] = nums.size() - 1;
        return true;
    }

    bool remove(int val)
    {
        if (valTOInd.find(val) == valTOInd.end())
            return false;
        int ind = valTOInd[val];
        valTOInd.erase(val);
        if (ind < nums.size() - 1)
        {
            nums[ind] = nums.back();
            valTOInd[nums[ind]] = ind;
        }
        nums.pop_back();
        return true;
    }

    int getRandom()
    {
        if (nums.empty())
            return -1;
        int randomIndex = rand() % nums.size();
        return nums[randomIndex];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */