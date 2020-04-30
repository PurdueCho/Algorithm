#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

vector<pair<string, int>> mymap;
map<string, int> c; 

bool comp (pair<string, int> & s, pair<string, int> & d) {
    return s.second < d.second;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    for (int i = 0 ; i < genres.size() ; i++) {
        mymap.push_back(make_pair(genres[i], plays[i]));
        c[genres[i]] += plays[i];
    }
    //sort(c.begin(), c.end(), comp);
    
    return answer;
}

int main () {

}