// Step 1: Define the Subsystem Classes
#include <iostream>
#include <string>

// Subsystem 1: DVD Player
class DVDPlayer {
public:
    void on() {
        std::cout << "DVD Player is On" << std::endl;
    }
    void off() {
        std::cout << "DVD Player is Off" << std::endl;
    }
    void play() {
        std::cout << "DVD is Playing" << std::endl;
    }
};

// Subsystem 2: Projector
class Projector {
public:
    void on() {
        std::cout << "Projector is On" << std::endl;
    }
    void off() {
        std::cout << "Projector is Off" << std::endl;
    }
    void setInput() {
        std::cout << "Projector input set to DVD" << std::endl;
    }
};

// Subsystem 3: Sound System
class SoundSystem {
public:
    void on() {
        std::cout << "Sound System is On" << std::endl;
    }
    void off() {
        std::cout << "Sound System is Off" << std::endl;
    }
    void setVolume(int level) {
        std::cout << "Sound System volume set to " << level << std::endl;
    }
};

// Subsystem 4: Lights
class Lights {
public:
    void dim() {
        std::cout << "Lights dimmed" << std::endl;
    }
    void brighten() {
        std::cout << "Lights brightened" << std::endl;
    }
};


// Step 2: Define the Facade Class
// Facade: HomeTheaterFacade
class HomeTheaterFacade {
private:
    DVDPlayer* dvdPlayer;
    Projector* projector;
    SoundSystem* soundSystem;
    Lights* lights;

public:
    HomeTheaterFacade(DVDPlayer* dvd, Projector* proj, SoundSystem* sound, Lights* light)
        : dvdPlayer(dvd), projector(proj), soundSystem(sound), lights(light) {}

    void watchMovie() {
        std::cout << "Get ready to watch a movie..." << std::endl;
        lights->dim();  // Dimming the lights
        projector->on();  // Turning on the projector
        projector->setInput();  // Setting the projector input
        soundSystem->on();  // Turning on the sound system
        soundSystem->setVolume(10);  // Setting volume
        dvdPlayer->on();  // Turning on the DVD player
        dvdPlayer->play();  // Playing the DVD
    }

    void endMovie() {
        std::cout << "Shutting down the home theater..." << std::endl;
        lights->brighten();  // Brightening the lights
        projector->off();  // Turning off the projector
        soundSystem->off();  // Turning off the sound system
        dvdPlayer->off();  // Turning off the DVD player
    }
};


// Step 3: Client Code
int main() {
    // Create subsystem objects
    DVDPlayer* dvdPlayer = new DVDPlayer();
    Projector* projector = new Projector();
    SoundSystem* soundSystem = new SoundSystem();
    Lights* lights = new Lights();

    // Create the facade
    HomeTheaterFacade* homeTheater = new HomeTheaterFacade(dvdPlayer, projector, soundSystem, lights);

    // Use the facade to simplify the process of watching and ending a movie
    homeTheater->watchMovie();  // Start watching a movie
    std::cout << std::endl;
    homeTheater->endMovie();  // End the movie

    // Clean up
    delete homeTheater;
    delete dvdPlayer;
    delete projector;
    delete soundSystem;
    delete lights;

    return 0;
}


/*
OUTPUT:

Get ready to watch a movie...
Lights dimmed
Projector is On
Projector input set to DVD
Sound System is On
Sound System volume set to 10
DVD Player is On
DVD is Playing

Shutting down the home theater...
Lights brightened
Projector is Off
Sound System is Off
DVD Player is Off

*/