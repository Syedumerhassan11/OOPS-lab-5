#include <iostream>
#include <cstdlib>
using namespace std;

class Car {
public:
    int engine_horsepower;
    int seating_capacity;
    int no_of_speakers;

    Car(int hp, int seats, int speakers) {
        engine_horsepower = hp;
        seating_capacity = seats;
        no_of_speakers = speakers;
    }

    void display() const {
        cout << "Engine Horsepower: " << engine_horsepower << endl;
        cout << "Seating Capacity: " << seating_capacity << endl;
        cout << "Number of Speakers: " << no_of_speakers << endl;
    }

    void modifyCar(int hp, int seats, int speakers) {
        engine_horsepower = hp;
        seating_capacity = seats;
        no_of_speakers = speakers;
    }
};

int main(int argc, char* argv[]) {
    if (argc < 4) {
        cout << "Usage: " << argv[0] << " <horsepower> <seating_capacity> <no_of_speakers>\n";
        return 1;
    }

    int horsepower = atoi(argv[1]);
    int seats = atoi(argv[2]);
    int speakers = atoi(argv[3]);

    Car myCar(horsepower, seats, speakers);

    cout << "Before modification:\n";
    myCar.display();
    myCar.modifyCar(horsepower + 50, seats - 1, speakers + 2);

    cout << "\nAfter modification:\n";
    myCar.display();

    return 0;
}

