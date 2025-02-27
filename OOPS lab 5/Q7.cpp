#include <iostream>
#include <cstdlib>
using namespace std;

class Student {
private:
    const int roll_no;

public:
    Student(int roll) : roll_no(roll) {}

    void display() const {
        cout << "Student Roll No: " << roll_no << endl;
    }
};

int main(int argc, char* argv[]) {
    if (argc < 2) {
        cout << "Usage: " << argv[0] << " <roll_no>\n";
        return 1;
    }

    int roll_no = atoi(argv[1]);

    Student s(roll_no);
    s.display();

    return 0;
}

