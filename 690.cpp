/*
// Employee info
class Employee {
public:
    // It's the unique ID of each node.
    // unique id of this employee
    int id;
    // the importance value of this employee
    int importance;
    // the id of direct subordinates
    vector<int> subordinates;
};
*/
// 690. Employee Importance
//有点像树遍历
class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        unordered_map <int, Employee*> mp;
        for(auto e : employees){
            mp[e->id] =e;
        }
        
        return count(mp, id);
    }
    
    int count(unordered_map <int, Employee*> &mp, int id){
        auto e = mp[id];
        
        int ret = e->importance;
        for(auto eid : e->subordinates){
            ret+=count(mp, eid);
        }
        
        return ret;
    }
};