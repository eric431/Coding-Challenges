#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

void search(const vector<int>& v1, int el, map<int, int>& pq_map)
{
    auto lb1 = lower_bound(v1.begin(), v1.end(), el);
    if(lb1 == v1.end()) return;
    
    int pos_i{lb1 - v1.begin()};
    pq_map[el] = pos_i;
}

// Complete the triplets function below.
long triplets(vector<int> a, vector<int> b, vector<int> c) {
    // sort all vectors with time complexity O(nlogn)
    set<int> set_a(a.begin(), a.end());
    a.assign(set_a.begin(), set_a.end());
    
    set<int> set_b(b.begin(), b.end());
    b.assign(set_b.begin(), set_b.end());
    
    set<int> set_c(c.begin(), c.end());
    c.assign(set_c.begin(), set_c.end());
    
    map<int, int> pq_map{};
    for(auto i = 0; i < a.size(); ++i)
    {
        search(b, a[i], pq_map);
    }
    
    map<int, long> qr_map{};
    int q_end {pq_map.begin()->second};
    long suffix_sum {0};
    for(int j = b.size() - 1; j >= q_end; --j)
    {
        auto lb2 = lower_bound(c.begin(), c.end(), b[j]);
        
        if(*lb2 > b[j] && lb2 != c.begin())
        {
            suffix_sum += (lb2 - c.begin());
        }
        else if(*lb2 == b[j])
        {
            suffix_sum += (lb2 - c.begin()) + 1;
        }
        qr_map[b[j]] = suffix_sum;
    }
    
    // for(auto el : qr_map)
    // {
    //     cout << el.first << " " << el.second << endl;
    // }
    
    long cnt {0};
    for(auto& kv : pq_map)
    {
        cout << kv.first << " " << b[kv.second] << " " << qr_map[b[kv.second]] << endl;
        cnt += qr_map[b[kv.second]];
    }

    return cnt;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string lenaLenbLenc_temp;
    getline(cin, lenaLenbLenc_temp);

    vector<string> lenaLenbLenc = split_string(lenaLenbLenc_temp);

    int lena = stoi(lenaLenbLenc[0]);

    int lenb = stoi(lenaLenbLenc[1]);

    int lenc = stoi(lenaLenbLenc[2]);

    string arra_temp_temp;
    getline(cin, arra_temp_temp);

    vector<string> arra_temp = split_string(arra_temp_temp);

    vector<int> arra(lena);

    for (int i = 0; i < lena; i++) {
        int arra_item = stoi(arra_temp[i]);

        arra[i] = arra_item;
    }

    string arrb_temp_temp;
    getline(cin, arrb_temp_temp);

    vector<string> arrb_temp = split_string(arrb_temp_temp);

    vector<int> arrb(lenb);

    for (int i = 0; i < lenb; i++) {
        int arrb_item = stoi(arrb_temp[i]);

        arrb[i] = arrb_item;
    }

    string arrc_temp_temp;
    getline(cin, arrc_temp_temp);

    vector<string> arrc_temp = split_string(arrc_temp_temp);

    vector<int> arrc(lenc);

    for (int i = 0; i < lenc; i++) {
        int arrc_item = stoi(arrc_temp[i]);

        arrc[i] = arrc_item;
    }

    long ans = triplets(arra, arrb, arrc);

    fout << ans << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
