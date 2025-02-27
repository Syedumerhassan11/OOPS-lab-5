#include <iostream>
#include <ctime>
using namespace std;

class Blend {
public:
    void blend_fruits(string fruit) {
        cout << "Blending " << fruit << "..." << endl;
        time_t start = time(0);
        while (time(0) - start < 4); // Simple delay of 4 seconds
        cout << "Blending complete!\n";
    }
};

class Grind {
public:
    void grind_fruits(string fruit) {
        cout << "Grinding " << fruit << "..." << endl;
        time_t start = time(0);
        while (time(0) - start < 5); // Simple delay of 5 seconds
        cout << "Grinding complete!\n";
    }
};

class JuiceMaker {
private:
    Blend blender;
    Grind grinder;
    
public:
    void blend_juice(string fruit) {
        blender.blend_fruits(fruit);
    }

    void grind_juice(string fruit) {
        grinder.grind_fruits(fruit);
    }
};

int main(int argc, char* argv[]) {
    if (argc < 2) {
        cout << "Usage: " << argv[0] << " <fruit_name>\n";
        return 1;
    }

    string fruit = argv[1];

    JuiceMaker juicer;
    juicer.blend_juice(fruit);
    juicer.grind_juice(fruit);

    cout << "Your " << fruit << " juice is ready!\n";
    return 0;
}

