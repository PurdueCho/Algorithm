#include <iostream>
#include <algorithm>

using namespace std;

/*
    STL sort

    // sort 의 기본 문법
    sort(메모리 주소, 메모리 범위, 비교 조건);
    sort(a, a+10, compare);

    // 데이터를 묶어서 정렬하는 방법
    실무에서는 모든 데이터들이 객체로 정리되어 내부적으로 여러개의 변수를 포함하고 있다.
    이 경우 가장 중요한 정렬 방식은 '특정한 변수를 기준으로' 정렬하는 것
    
    
*/



class Student {
    public:
        string name;
        int score;
        Student (string name, int score) {
            this->name = name;
            this->score = score;
        }
        // 정렬기준은 '점수가 작은 순서'
        bool operator<(Student &student) {
            return this->score < student.score;
        }
};

bool compare(Student a, Student b)
{
    return a.score > b.score;
}

int main() {

    Student students[] = {
        Student("John", 90),
        Student("Young", 100),
        Student("Ken", 93),
        Student("Ellen", 88),
        Student("Kim", 92),
        Student("max", 97)
    };

    sort(students, students + 6, compare);

    for (int i = 0 ; i < 6; i++) {
        cout << students[i].name << endl;
    }
     
    return 0;
}