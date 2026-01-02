// Step 1: Define the Observer Interface
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

// Observer interface
class Observer {
public:
    virtual void update(float temperature) = 0;
    virtual ~Observer() = default;
};


// Step 2: Define the Subject Interface
// Subject interface
class Subject {
public:
    virtual void addObserver(Observer* observer) = 0;
    virtual void removeObserver(Observer* observer) = 0;
    virtual void notifyObservers() = 0;
    virtual ~Subject() = default;
};

// Step 3: Define the ConcreteSubject Class
// ConcreteSubject class: WeatherStation
class WeatherStation : public Subject {
private:
    float temperature;
    std::vector<Observer*> observers;

public:
    void setTemperature(float temp) {
        temperature = temp;
        notifyObservers();  // Notify observers when temperature changes
    }

    float getTemperature() const {
        return temperature;
    }

    void addObserver(Observer* observer) override {
        observers.push_back(observer);
    }

    void removeObserver(Observer* observer) override {
        observers.erase(std::remove(observers.begin(), observers.end(), observer), observers.end());
    }

    void notifyObservers() override {
        for (Observer* observer : observers) {
            observer->update(temperature);  // Notify each observer of the state change
        }
    }
};

// Step 4: Define ConcreteObserver Classes
// ConcreteObserver class: PhoneDisplay
class PhoneDisplay : public Observer {
private:
    std::string name;

public:
    PhoneDisplay(const std::string& name) : name(name) {}

    void update(float temperature) override {
        std::cout << name << " - Temperature updated to: " << temperature << "°C" << std::endl;
    }
};

// ConcreteObserver class: DesktopDisplay
class DesktopDisplay : public Observer {
private:
    std::string name;

public:
    DesktopDisplay(const std::string& name) : name(name) {}

    void update(float temperature) override {
        std::cout << name << " - Temperature updated to: " << temperature << "°C" << std::endl;
    }
};


// Step 5: Client Code
int main() {
    // Create a WeatherStation (Subject)
    WeatherStation weatherStation;

    // Create Observers
    PhoneDisplay phoneDisplay("Phone Display");
    DesktopDisplay desktopDisplay("Desktop Display");

    // Register Observers with the WeatherStation
    weatherStation.addObserver(&phoneDisplay);
    weatherStation.addObserver(&desktopDisplay);

    // Change the temperature, which should notify all observers
    weatherStation.setTemperature(25.0f);  // All observers will be notified

    weatherStation.setTemperature(30.0f);  // All observers will be notified again

    return 0;
}


/*
OUTPUT:

Phone Display - Temperature updated to: 25°C
Desktop Display - Temperature updated to: 25°C
Phone Display - Temperature updated to: 30°C
Desktop Display - Temperature updated to: 30°C

*/