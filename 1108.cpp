// 1108. Defanging an IP Address
class Solution {
public:
    string defangIPaddr(string address) {
        string ret;
        
        for(char c:address)
        {
            if(c != '.')
            {
                ret+=c;
            }
            else{
                ret.append("[.]");
            }
        }
        
        return ret;
    }
};