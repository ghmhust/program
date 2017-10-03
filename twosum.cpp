#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main() {
    int n = 0;
    while(cin>>n){
        int target = 0;
        cin>>target;
        vector<int> nums(n);
        for(int i = 0;i<n;++i){
            cin>>nums[i];
        }
        vector<int> temp;
        map<int,int> mp;
        for(int i = 0;i<n;++i) {
            map<int, int>::iterator it = mp.find(target - nums[i]);
            if (it != mp.end() && it->second != i && nums[it->second] + nums[i] == target) {
                if (i < it->second) {
                    temp.push_back(i);
                    temp.push_back(it->second);
                    break;
                } else {
                    temp.push_back(it->second);
                    temp.push_back(i);
                    break;
                }
            }
            mp.insert(pair<int, int>(nums[i], i));
            mp.insert(pair<int, int>(target - nums[i], i));
        }
    }
    return 0;
}