// 551. Student Attendance Record I
class Solution {
public:
    bool checkRecord(string s) {
        bool a = false;
        // bool ll = false;
        
        for(int i=0;i<s.size();i++){
            switch(s[i]){
                case 'A':{
                    if(a)return false;
                    a = true;
                    break;
                }
                case 'L':{
                    if(i+2 < s.size() && s[i+1] == 'L' && s[i+2]=='L'){
                        // if(ll)return false;
                        // ll = true;
                        return false;
                    }
                    break;
                }
                default:;
            }
        }
        return true;
    }
};