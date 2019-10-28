// 722. Remove Comments
class Solution {
    // ["a/*comment", "line", "more_comment*/b"]
public:
    vector<string> removeComments(vector<string>& source) {
        int line1 = -1,char1;
        
        for(int l = 0;l < source.size();l++){
            auto& line = source[l];
            if(line.empty())continue;
            for(int i=0;i<(int)line.size()-1;i++){
                // cout << l << ' ' << i <<'\n';
                if(line1 >= 0){//前面出现了 /*
                    if('*'==line[i] && line[i+1] == '/'){
                        auto &s1 = source[line1];
                        //同行/**/
                        if(line1 == l){
                            s1 = s1.substr(0, char1)+(i+2 == line.size()? "":s1.substr(i+2));
                            i = char1 - 1;// /**/ //
                        }else{
                            //谁告诉你多行注释/**/，去掉后要合并成一行
                            s1 = s1.substr(0, char1) + source[l].substr(i+2);
                            for(int ll=line1+1;ll<=l;ll++){
                                source[ll] = "";
                            }
                            // source[l] = source[l].substr(i+2);
                            
                            l = line1-1;//还要处理line1，因为新加了当前行的后部分
                            i = char1-1;
                        }
                        line1 = -1;//清除标记
                        
                    }
                }else if(line[i] == '/'){
                    if(line[i+1] == '/'){
                        // cout << '?';
                        line = line.substr(0, i);
                        break;
                    }else if('*' == line[i+1]){
                        line1 = l, char1 = i;
                        i++;
                    }
                }
            }
        }
        for(auto it = source.begin();it!=source.end();){
            if(it->empty()){
                it = source.erase(it);
            }else{
                it++;
            }
        }
        return source;
    }
};