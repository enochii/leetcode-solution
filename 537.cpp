// 537. Complex Number Multiplication

class Solution {
public:
    string complexNumberMultiply(string a, string b) {
        auto pa = convert(a);
        auto pb = convert(b);
        
        int fir = pa.first * pb.first - pa.second * pb.second;
        int sec = pa.first * pb.second + pa.second * pb.first;
        
        return to_string(fir)+'+'+to_string(sec)+'i';
    }
    
    pair<int, int> convert(string& s){
        int pos = 0;
        int a = atoi(s, pos);
        pos ++;// +
        int b = atoi(s, pos);
        
        // cout<<a<<' '<<b<<'\n';
        return {a,b};
    }
    
    int atoi(string& s, int &pos){
        int tag = 1;
        if(s[pos] == '-'){
            tag = -1;
            pos++;
        }
        int ret = 0;
        while(isdigit(s[pos])){
            ret = ret * 10 + s[pos++] - '0';
        }
        return ret * tag;
    }
};