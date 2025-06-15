class Solution {
    public:
        int calculate(string s) {
            vector<int> digits;
            vector<char> ops;
    
            string str = "";
            int val{0};
            int i{0};
            while(i < s.size()){
                if(s[i] == ' ') {
                    ++i;
                    continue;
                }
    
                if(isdigit(s[i])){
                    str += s[i];
                    ++i;
                } else {
                    int tmp;
                    if(str == ""){
                        tmp = digits.back();
                        digits.pop_back();
                    } else {
                        tmp = stoi(str);
                        str = "";
                    }
    
                    if(s[i] == '*'){
                        string tmp_2 = "";
    
                        while(!isdigit(s[i])) ++i;
                        while(i < s.size() && isdigit(s[i])){
                            if(s[i] == ' ') continue;
                            tmp_2 += s[i];
                            ++i;
                        }
                        val = tmp * stoi(tmp_2);
                        digits.push_back(val);
                    } else if(s[i] == '/'){
                        string tmp_2 = "";
    
                        while(!isdigit(s[i])) ++i;
                        while(i < s.size() && isdigit(s[i])){
                            if(s[i] == ' ') continue;
    
                            tmp_2 += s[i];
                            ++i;
                        }
                        val = tmp / stoi(tmp_2);
                        digits.push_back(val);                   
                    } else if(s[i] == '-'){
                        digits.push_back(tmp);
                        ops.push_back('-');
                        ++i;
                    } else if (s[i] == '+'){
                        digits.push_back(tmp);
                        ops.push_back('+');
                        ++i;
                    }
                }    
            }
    
            if(str != ""){
                digits.push_back(stoi(str));
            }
    
            if(ops.size() == 0) {
                return digits[0];
            }
    
            int ans{ digits[0] };
            for(auto i{1}; i < digits.size(); ++i){
                if(ops[i - 1] == '+'){
                    ans += digits[i];
                } else if(ops[i - 1] == '-'){
                    ans -= digits[i];
                }
            }
    
            return ans;
        }
    };