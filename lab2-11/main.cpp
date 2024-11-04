#include <iostream>
#include <map>
#include <string>

using namespace std;

// 학생 정보를 저장할 구조체
struct Student {
    int midterm;
    int final;
};

// 메인 함수
int main() {
    int n;
    cout << "학생 수를 입력하세요: ";
    cin >> n;

    // 학생 정보를 저장할 map 선언
    map<string, Student> students;

    // 학생 수 만큼 입력받아 map에 삽입
    for (int i = 0; i < n; i++) {
        string name;
        Student student;
        cout << "학생 이름: ";
        cin >> name;
        cout << "중간 점수: ";
        cin >> student.midterm;
        cout << "기말 점수: ";
        cin >> student.final;
        students[name] = student; // map에 삽입
    }

    // 학생 정보 출력 (이름 순)
    cout << "\n=== 학생 정보 출력 (이름 순) ===\n";
    for (const auto& pair : students) {
        cout << "이름: " << pair.first
             << ", 중간: " << pair.second.midterm
             << ", 기말: " << pair.second.final << endl;
    }

    // 특정 이름으로 학생 탐색
    string searchName;
    cout << "\n찾을 학생 이름을 입력하세요: ";
    cin >> searchName;

    auto found = students.find(searchName);
    if (found != students.end()) {
        cout << "이름: " << found->first
             << ", 중간: " << found->second.midterm
             << ", 기말: " << found->second.final << endl;
    } else {
        cout << "해당 이름의 학생이 없습니다." << endl;
    }

    return 0;
}
