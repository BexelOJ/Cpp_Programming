// Step 1: Define the Memento Class
#include <iostream>
#include <vector>
#include <string>

// Memento class to store the state of TextEditor
class Memento {
private:
    std::string text;

public:
    Memento(const std::string& text) : text(text) {}
    std::string getText() const { return text; }
};


// Step 2: Define the Originator Class
// Originator class: TextEditor
class TextEditor {
private:
    std::string text;

public:
    void setText(const std::string& newText) {
        text = newText;
    }

    std::string getText() const {
        return text;
    }

    // Creates a Memento containing the current state
    Memento save() const {
        return Memento(text);
    }

    // Restores the state from a Memento
    void restore(const Memento& memento) {
        text = memento.getText();
    }
};


// Step 3: Define the Caretaker Class
// Caretaker class: Stores mementos
class Caretaker {
private:
    std::vector<Memento> mementos;

public:
    void addMemento(const Memento& memento) {
        mementos.push_back(memento);
    }

    Memento getMemento(int index) const {
        return mementos[index];
    }

    size_t getMementoCount() const {
        return mementos.size();
    }
};


// Step 4: Client Code
int main() {
    TextEditor editor;

    // Create a Caretaker to store Mementos
    Caretaker caretaker;

    // Modify the text and save the state
    editor.setText("Hello, world!");
    caretaker.addMemento(editor.save());

    editor.setText("Hello, Design Patterns!");
    caretaker.addMemento(editor.save());

    editor.setText("Hello, Memento Pattern!");
    caretaker.addMemento(editor.save());

    // Now let's display and restore the text to previous states
    std::cout << "Current Text: " << editor.getText() << std::endl;

    // Undo to previous states
    editor.restore(caretaker.getMemento(1));  // Restores "Hello, Design Patterns!"
    std::cout << "Restored Text: " << editor.getText() << std::endl;

    editor.restore(caretaker.getMemento(0));  // Restores "Hello, world!"
    std::cout << "Restored Text: " << editor.getText() << std::endl;

    return 0;
}


/*
OUTPUT:

Current Text: Hello, Memento Pattern!
Restored Text: Hello, Design Patterns!
Restored Text: Hello, world!

*/