#include <iostream>
#include <vector>
#include <functional>

class Car {
private:
    std::string name;
    int id;

public:
    Car(std::string carName, int carId) : name(carName), id(carId) {}
    std::string getName() const { return name; }
    int getId() const { return id; }
};

class Garage {
private:
    std::vector<std::reference_wrapper<Car>> cars;

public:
    void parkCar(Car& car) {
        cars.push_back(car);
    }
    void listCars() {
        for (const auto& car : cars) {
            std::cout << "Car ID: " << car.get().getId() << ", Name: " << car.get().getName() << std::endl;
        }
    }
};

int main() {
    Car car1("Toyota", 1);
    Car car2("Honda", 2);
    Car car3("Ford", 3);

    Garage garage;
    garage.parkCar(car1);
    garage.parkCar(car2);
    garage.parkCar(car3);

    garage.listCars();
    
    return 0;
}
