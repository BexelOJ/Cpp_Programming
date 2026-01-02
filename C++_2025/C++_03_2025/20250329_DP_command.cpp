// Step 1: Define the Command Interface
#include <iostream>
#include <vector>
#include <string>

// Command Interface
class Command {
public:
    virtual void execute() = 0;
    virtual void undo() = 0;
    virtual ~Command() = default;
};


// Step 2: Define the Receiver Classes
// Receiver 1: Light
class Light {
public:
    void on() {
        std::cout << "Light is ON" << std::endl;
    }

    void off() {
        std::cout << "Light is OFF" << std::endl;
    }
};

// Receiver 2: Thermostat
class Thermostat {
public:
    void setTemperature(int temperature) {
        std::cout << "Thermostat set to " << temperature << " degrees." << std::endl;
    }
};


// Step 3: Define Concrete Command Classes
// Concrete Command: LightOnCommand
class LightOnCommand : public Command {
private:
    Light* light;  // The receiver
public:
    explicit LightOnCommand(Light* l) : light(l) {}

    void execute() override {
        light->on();  // Invoke the receiver's action
    }

    void undo() override {
        light->off();  // Undo the action
    }
};

// Concrete Command: LightOffCommand
class LightOffCommand : public Command {
private:
    Light* light;
public:
    explicit LightOffCommand(Light* l) : light(l) {}

    void execute() override {
        light->off();
    }

    void undo() override {
        light->on();
    }
};

// Concrete Command: ThermostatSetCommand
class ThermostatSetCommand : public Command {
private:
    Thermostat* thermostat;
    int previousTemp;
    int targetTemp;

public:
    ThermostatSetCommand(Thermostat* t, int temp) : thermostat(t), targetTemp(temp), previousTemp(0) {}

    void execute() override {
        previousTemp = targetTemp;  // Save the previous temperature
        thermostat->setTemperature(targetTemp);
    }

    void undo() override {
        thermostat->setTemperature(previousTemp);  // Revert to previous temperature
    }
};


// Step 4: Define the Invoker Class
// Invoker: RemoteControl
class RemoteControl {
private:
    std::vector<Command*> commandHistory;  // Stores the history of executed commands

public:
    void pressButton(Command* command) {
        command->execute();  // Execute the command
        commandHistory.push_back(command);  // Optionally store the command for undo
    }

    void pressUndo() {
        if (!commandHistory.empty()) {
            Command* lastCommand = commandHistory.back();
            lastCommand->undo();  // Undo the last command
            commandHistory.pop_back();
        }
    }
};


// Step 5: Client Code
int main() {
    // Create receivers
    Light* livingRoomLight = new Light();
    Thermostat* thermostat = new Thermostat();

    // Create concrete command objects
    Command* lightOn = new LightOnCommand(livingRoomLight);
    Command* lightOff = new LightOffCommand(livingRoomLight);
    Command* setThermostat = new ThermostatSetCommand(thermostat, 22);  // Set thermostat to 22 degrees

    // Create invoker (remote control)
    RemoteControl* remote = new RemoteControl();

    // Execute some commands
    remote->pressButton(lightOn);
    remote->pressButton(setThermostat);
    remote->pressButton(lightOff);

    std::cout << "Undoing last command..." << std::endl;
    remote->pressUndo();  // Undo the last command (turn off light)

    std::cout << "Undoing last command..." << std::endl;
    remote->pressUndo();  // Undo the second last command (set thermostat)

    std::cout << "Undoing last command..." << std::endl;
    remote->pressUndo();  // Undo the first command (turn on light)

    // Clean up
    delete livingRoomLight;
    delete thermostat;
    delete lightOn;
    delete lightOff;
    delete setThermostat;
    delete remote;

    return 0;
}


/*
OUTPUT:

Light is ON
Thermostat set to 22 degrees.
Light is OFF
Undoing last command...
Light is ON
Undoing last command...
Thermostat set to 0 degrees.
Undoing last command...
Light is OFF

*/