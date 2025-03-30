// Step 1: Define the Component Interface
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

// Component interface
class FileSystemComponent {
public:
    virtual void display(int depth) const = 0;  // Display the component
    virtual ~FileSystemComponent() = default;
};


// Step 2: Define the Leaf Class (File)
// Leaf class representing a file
class File : public FileSystemComponent {
private:
    std::string name;

public:
    File(const std::string& name) : name(name) {}

    void display(int depth) const override {
        std::cout << std::string(depth, '-') << "File: " << name << std::endl;
    }
};


// Step 3: Define the Composite Class (Directory)
// Composite class representing a directory
class Directory : public FileSystemComponent {
private:
    std::string name;
    std::vector<FileSystemComponent*> children;  // Children can be files or directories

public:
    Directory(const std::string& name) : name(name) {}

    void add(FileSystemComponent* component) {
        children.push_back(component);  // Add a child component (file or directory)
    }

    void remove(FileSystemComponent* component) {
        children.erase(std::remove(children.begin(), children.end(), component), children.end());
    }

    void display(int depth) const override {
        std::cout << std::string(depth, '-') << "Directory: " << name << std::endl;
        for (const auto& child : children) {
            child->display(depth + 2);  // Increase depth for nested display
        }
    }

    ~Directory() {
        for (auto* child : children) {
            delete child;  // Clean up dynamically allocated components
        }
    }
};


// Step 4: Client Code
int main() {
    // Create some files
    File* file1 = new File("File1.txt");
    File* file2 = new File("File2.txt");
    File* file3 = new File("File3.txt");

    // Create some directories
    Directory* dir1 = new Directory("Documents");
    Directory* dir2 = new Directory("Pictures");

    // Add files to directories
    dir1->add(file1);
    dir1->add(file2);
    dir2->add(file3);

    // Create a root directory and add subdirectories
    Directory* root = new Directory("Root");
    root->add(dir1);
    root->add(dir2);

    // Display the file system structure
    root->display(0);  // Depth is 0 for the root directory

    // Clean up
    delete root;

    return 0;
}


/*
OUTPUT:

Directory: Root
--Directory: Documents
----File: File1.txt
----File: File2.txt
--Directory: Pictures
----File: File3.txt

*/