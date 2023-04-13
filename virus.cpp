#include "virus.h"
#include "animal.h"
#include <vector>
#include <map>
#include <iostream>
using namespace std;
string largestSubstrN(vector<string> strings)
{
    string large = "";
    int nlengths = 0;
    multimap<int, string> results;
    if (strings.size() == 0)
        return large;
    //_____________find shortestString
    auto shortest_i = strings.end();
    int min_len = -1;
    for (auto i = strings.begin(); i != strings.end(); i++) {
        if (i->size() < min_len) {
            shortest_i = i;
            min_len = i->size();
        }
    }
    string shortest = *shortest_i;
    strings.erase(shortest_i);
    int start = 0;
    while(start < shortest.size()) {
        int skip = 1;
        for (int len = shortest.size(); len > 0; len--) {
            string subStr = shortest.substr(start, len);

            bool isSub = true;
            for (int i = 0; i < strings.size();i++) 
                if (strings[i].find(subStr) == -1)
                    isSub = false;
            if (isSub==false) 
                continue;
            auto i = results.lower_bound(subStr.size());
            while (i != results.end() && i->second.find(subStr) == string::npos)
                ++i;
            if (i != results.end()) 
                continue;
            for (i = results.begin();  i != results.end() && i->first < subStr.size(); ) {
                if (subStr.find(i->second) != string::npos) 
                    i = results.erase(i);
                else 
                    ++i;
            }
            auto hint = results.lower_bound(subStr.size());
            bool new_len=false;
            if (hint == results.end() || hint->first != subStr.size())
                new_len = true;
            if (new_len && nlengths == strings.size()) {
                int min_len = results.begin()->first;
                if (min_len > subStr.size()) 
                    continue;
                results.erase(min_len);
                --nlengths;
            }
            nlengths += new_len;
            results.emplace_hint(hint, subStr.size(), subStr);
            len = 1;
            skip = subStr.size();
        }
        start += skip;
    }
    /*for (auto const& val : results)   cout << "length: " << val.first << ", substring: " << val.second << endl;*/ int l = -1;   
    for (auto const& val : results)
        if (val.first > l)
            large = val.second;
    return large;
}

bool virus::CheckHarmfulVirus(vector <string> strings) {
    
    string large = largestSubstrN(strings);
    cout << "\tlargest genese substring: " <<large;
    vector <string> s;
    s.push_back(large);
    s.push_back(RNA);
    string common=largestSubstrN(s);
    //____________________create complement of RNA
    string complement = large;
    for (unsigned int i = 0; i < large.size(); i++)
    {
        if (large[i] == 'T')
            complement[i] = 'A';
        else if (large[i] == 'A')
            complement[i] = 'T';
        else if (large[i] == 'C')
            complement[i] = 'G';
        else if (large[i] == 'G')
            complement[i] = 'C';
    }
    cout << "\n\tgenes largest substring complement is: " << complement;
    //_____________________
    vector <string> s2;
    s2.push_back(complement);
    s2.push_back(RNA);
    string common2 = largestSubstrN(s2);
    
    if (common.size() > 0)
    {
        cout << "\n\tlargest common virus and genes substring: " << common;
        return true;
    }
    else if ( common2.size() > 0)
    {
        cout << "\n\tlargest common virus and genes substring complement :" << common2;
        return true;
    }
    else
    {
        cout << "\n\tno common substring found..";
        return false;
    }
}
void virus::print() {
	cout << "\n\tRNA: " << RNA;
}
virus::virus()
{
	cout << "\n\tenter virus RNA: ";
	cin >> RNA;
}
