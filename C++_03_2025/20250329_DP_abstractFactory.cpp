// Step 1: Define Abstract Products
#include <iostream>
#include <string>

// Abstract product - Button
class Button {
public:
    virtual void render() = 0;
    virtual ~Button() = default;
};

// Abstract product - Checkbox
class Checkbox {
public:
    virtual void render() = 0;
    virtual ~Checkbox() = default;
};


// Step 2: Define Concrete Products
// Concrete product - DarkThemeButton
class DarkThemeButton : public Button {
public:
    void render() override {
        std::cout << "Rendering Dark Theme Button" << std::endl;
    }
};

// Concrete product - LightThemeButton
class LightThemeButton : public Button {
public:
    void render() override {
        std::cout << "Rendering Light Theme Button" << std::endl;
    }
};

// Concrete product - DarkThemeCheckbox
class DarkThemeCheckbox : public Checkbox {
public:
    void render() override {
        std::cout << "Rendering Dark Theme Checkbox" << std::endl;
    }
};

// Concrete product - LightThemeCheckbox
class LightThemeCheckbox : public Checkbox {
public:
    void render() override {
        std::cout << "Rendering Light Theme Checkbox" << std::endl;
    }
};


// Step 3: Define the Abstract Factory
// Abstract factory
class GUIFactory {
public:
    virtual Button* createButton() = 0;
    virtual Checkbox* createCheckbox() = 0;
    virtual ~GUIFactory() = default;
};


// Step 4: Define Concrete Factories
// Concrete factory - DarkThemeFactory
class DarkThemeFactory : public GUIFactory {
public:
    Button* createButton() override {
        return new DarkThemeButton(); // Create Dark Theme Button
    }

    Checkbox* createCheckbox() override {
        return new DarkThemeCheckbox(); // Create Dark Theme Checkbox
    }
};

// Concrete factory - LightThemeFactory
class LightThemeFactory : public GUIFactory {
public:
    Button* createButton() override {
        return new LightThemeButton(); // Create Light Theme Button
    }

    Checkbox* createCheckbox() override {
        return new LightThemeCheckbox(); // Create Light Theme Checkbox
    }
};


// Step 5: Client Code
int main() {
    // Client can choose the theme factory it needs
    GUIFactory* factory = new DarkThemeFactory(); // Dark Theme
    Button* button = factory->createButton();
    Checkbox* checkbox = factory->createCheckbox();
    
    // Render the components
    button->render();     // Output: Rendering Dark Theme Button
    checkbox->render();   // Output: Rendering Dark Theme Checkbox

    // Switch to Light Theme
    delete factory; // Clean up previous factory
    factory = new LightThemeFactory(); // Light Theme
    button = factory->createButton();
    checkbox = factory->createCheckbox();
    
    // Render the components
    button->render();     // Output: Rendering Light Theme Button
    checkbox->render();   // Output: Rendering Light Theme Checkbox

    // Cleanup
    delete button;
    delete checkbox;
    delete factory;

    return 0;
}


/*
OUTPUT:

Rendering Dark Theme Button
Rendering Dark Theme Checkbox
Rendering Light Theme Button
Rendering Light Theme Checkbox

*/


