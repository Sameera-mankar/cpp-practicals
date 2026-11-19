#include <iostream>
#include <string>
using namespace std;

class Bike {
    private:
        string Bike_color, Bike_model;
        int Bike_year;
        bool Start;
        int moving;

        void bikeStart() {
            Start = 1;
            cout << Bike_model << "'s engine starts.\n";
        }

        void bikeStop() {
            Start = 0;
            cout << Bike_model << "'s engine has been turned off.\n\n";
        }

        void moveForward() {
            if (Start) {
                if (moving == 0) {
                    cout << Bike_model << " moves forward.\n";
                    moving = 1;
                }
                else if (moving == 1) {
                    cout << Bike_model << " moves faster.\n";
                    moving = 2;
                }
                else if (moving == 2) {
                    cout << Bike_model << " is already at maximum speed.\n";
                }
            }
            else {
                cout << Bike_model << " stays still. Start the bike!\n";
            }
        }

        void brake() {
            if (Start) {
                if (moving == 1) {
                    cout << Bike_model << " slows to a halt.\n";
                    moving = 0;
                }
                else if (moving == 2) {
                    cout << Bike_model << " moves slower.\n";
                    moving = 1;
                }
                else {
                    cout << Bike_model << " stays still. Bike wasn't moving.\n";
                }
            }
            else {
                cout << Bike_model << " stays still. Bike wasn't moving.\n";
            }
        }

    public:
        Bike(string color, string model, int year) {
            Bike_color = color;
            Bike_model = model;
            Bike_year = year;

            cout << "The bike created is " << year << " "
                 << color << " " << model << "\n";

            Start = 0;
            moving = 0;
        }

        void turnKey() {
            if (!Start) {
                bikeStart();
            }
            else if (Start && !moving) {
                bikeStop();
            }
            else {
                cout << "Stop the bike before turning the key!\n";
            }
        }

        void accelerate() {
            moveForward();
        }

        void decelerate() {
            brake();
        }

        void display() {
            cout << "Your bike is: " << Bike_year << " "
                 << Bike_color << " " << Bike_model << "\n\n";
        }
};

int main() {
    cout << "Student name: SAMEERA MANKAR\n";
    cout << "URN: E25B000297\n\n";

    Bike Honda("Red", "HONDA", 2024);
    Bike Yamaha("Blue", "YAMAHA", 2024);

    Honda.display();
    Honda.turnKey();
    Honda.accelerate();
    Honda.decelerate();
    Honda.turnKey();

    Yamaha.display();
    Yamaha.accelerate();
    Yamaha.turnKey();
    Yamaha.accelerate();
    Yamaha.decelerate();
    Yamaha.turnKey();

    return 0;
}
