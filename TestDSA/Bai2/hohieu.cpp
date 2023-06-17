#include <iostream>
#include <string>

using namespace std;

const int MAX_SIZE = 100;

struct Student {
    string id;
    string name;
    int birthYear;
    float gpa;
};

struct StudentList {
    Student students[MAX_SIZE];
    int count = 0;
};

void inputStudent(Student& student) {
    cout << "Nhap ma sinh vien: ";
    cin >> student.id;

    if (student.id == "***") {
        return;
    }

    cout << "Nhap ho ten: ";
    cin.ignore();
    getline(cin, student.name);

    cout << "Nhap nam sinh: ";
    cin >> student.birthYear;

    cout << "Nhap diem tong ket: ";
    cin >> student.gpa;
}

void displayStudent(Student student) {
    cout << student.id << "\t" << student.name << "\t" << student.birthYear << "\t" << "\t" <<student.gpa << endl;
}

void inputStudentList(StudentList& list) {
    while (list.count < MAX_SIZE) {
        Student student;
        inputStudent(student);

        if (student.id == "***") {
            break;
        }

        list.students[list.count++] = student;
    }
}

void displayStudentList(StudentList list) {
    cout << "Ma SV\tHo ten\tNam sinh\tDiem TK" << endl;
    for (int i = 0; i < list.count; i++) {
        displayStudent(list.students[i]);
    }
}

void deleteFirstStudent(StudentList& list) {
    if (list.count > 0) {
        for (int i = 0; i < list.count - 1; i++) {
            list.students[i] = list.students[i + 1];
        }

        list.count--;
    }
}

void deleteStudentById(StudentList& list, string id) {
    for (int i = 0; i < list.count; i++) {
        if (list.students[i].id == id) {
            for (int j = i; j < list.count - 1; j++) {
                list.students[j] = list.students[j + 1];
            }

            list.count--;
            break;
        }
    }
}

void insertStudent(StudentList& list, Student student, int k) {
    if (list.count == MAX_SIZE || k < 0 || k > list.count) {
        return;
    }

    for (int i = list.count - 1; i >= k; i--) {
        list.students[i + 1] = list.students[i];
    }

    list.students[k] = student;
    list.count++;
}

void listStudentsByName(StudentList list, string name) {
    cout << "Ma SV\tHo ten\tNam sinh\tDiem TK" << endl;
    for (int i = 0; i < list.count; i++) {
        if (list.students[i].name.find(name) != string::npos) {
            displayStudent(list.students[i]);
        }
    }
}

void sortStudentListByGPA(StudentList& list) {
    for (int i = 0; i < list.count - 1; i++) {
        for (int j = i + 1; j < list.count; j++) {
            if (list.students[i].gpa < list.students[j].gpa) {
                swap(list.students[i], list.students[j]);
            }
        }
    }
}

void insertStudentInOrder(StudentList& list, Student student) {
    if (list.count == MAX_SIZE) {
        return;
    }

    int i = list.count - 1;
    while (i >= 0 && list.students[i].gpa < student.gpa) {
        list.students[i + 1] = list.students[i];
        i--;
    }

    list.students[i + 1] = student;
    list.count++;
}

int main() {
    StudentList list;
    inputStudentList(list);
    cout << "Danh sach sinh vien:" << endl;

    displayStudentList(list);

    deleteFirstStudent(list);

    cout << "Danh sach sinh vien sau khi xoa sinh vien dau tien:" << endl;
    displayStudentList(list);

    deleteStudentById(list, "sv8089");
    cout << "Danh sach sinh vien sau khi xoa sinh vien co ma 'sv8089':" << endl;
    displayStudentList(list);

    Student newStudent;
    inputStudent(newStudent);
    int k;
    cout << "Nhap vi tri can them: ";
    cin >> k;
    insertStudent(list, newStudent, k);
    cout << "Danh sach sinh vien sau khi them sinh vien moi:" << endl;
    displayStudentList(list);

    cout << "Sinh vien co ten 'Doanh':" << endl;
    listStudentsByName(list, "Doanh");

    sortStudentListByGPA(list);
    cout << "Danh sach sinh vien sau khi sap xep theo diem TK giam dan:" << endl;
    displayStudentList(list);

    Student newStudent2;
    inputStudent(newStudent);
        cout << "Nhap thong tin sinh vien can them:" << endl;
    inputStudent(newStudent2);
    insertStudentInOrder(list, newStudent2);
    cout << "Danh sach sinh vien sau khi them sinh vien moi vao danh sach sao cho truc tiep sap xep khong bi thay doi:" << endl;
    displayStudentList(list);

    return 0;
}

