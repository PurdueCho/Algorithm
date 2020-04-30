#include <string>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    
//     sort(participant.begin(), participant.end());
//     sort(completion.begin(), completion.end());
    
//     for (int i = 0 ; i < completion.size() ; i++) {
//         if (participant[i] != completion[i]) {
//             answer = participant[i];
//             return answer;
//         }
//     }
    
//     answer = participant[participant.size()-1];
    
    unordered_multiset<string> mymap;

    for(int i = 0; i < participant.size(); i++)
    {
        mymap.insert(participant[i]);
    }

    for(int i = 0; i < completion.size(); i++)
    {
        auto it = mymap.find(completion[i]);
        mymap.erase(it);
    }
    
    return *mymap.begin();
}

int main () {

    return 0;
}