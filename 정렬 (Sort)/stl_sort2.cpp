#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

/*
    STL sort

    // sort 의 기본 문법
    sort(메모리 주소, 메모리 범위, 비교 조건);
    sort(a, a+10, compare);

    // 데이터를 묶어서 정렬하는 방법
    실무에서는 모든 데이터들이 객체로 정리되어 내부적으로 여러개의 변수를 포함하고 있다.
    이 경우 가장 중요한 정렬 방식은 '특정한 변수를 기준으로' 정렬하는 것

    // 클래스를 이용하는 방식은 실무에 적합, 대회에서는 pair를 이용
    
    
*/
bool compare(pair<string, pair<int, int>> a, pair<string, pair<int, int>> b) {
    if (a.second.first == b.second.first) {
        return a.second.second > b.second.second;
    } else {
        return a.second.first > b.second.first;
    }
}

int main()
{
    vector<pair<string, pair<int, int>> > v;

    v.push_back(pair<string, pair<int, int>>("Young", pair<int, int>(90, 19920826)));
    v.push_back(pair<string, pair<int, int>>("Ellen", pair<int, int>(100, 19960910)));
    v.push_back(pair<string, pair<int, int>>("Sam", pair<int, int>(97, 19940226)));
    v.push_back(pair<string, pair<int, int>>("Mac", pair<int, int>(94, 19920926)));
    v.push_back(pair<string, pair<int, int>>("Kang", pair<int, int>(90, 19940826)));

    sort (v.begin(), v.end(), compare);
    for (int i = 0; i < v.size(); i++)
    {
        cout  << v[i].first << endl;
    }

    return 0;
}