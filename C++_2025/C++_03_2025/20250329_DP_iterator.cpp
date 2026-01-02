// Step 1: Define the Iterator Interface
#include <iostream>
#include <vector>

// Iterator Interface
template <typename T>
class Iterator {
public:
    virtual bool hasNext() const = 0;
    virtual T next() = 0;
    virtual T current() const = 0;
    virtual void reset() = 0;
    virtual ~Iterator() = default;
};


// Step 2: Define the Concrete Iterator
template <typename T>
class ConcreteIterator : public Iterator<T> {
private:
    const std::vector<T>& collection;
    size_t index;
    
public:
    ConcreteIterator(const std::vector<T>& collection) : collection(collection), index(0) {}

    bool hasNext() const override {
        return index < collection.size();
    }

    T next() override {
        return collection[index++];
    }

    T current() const override {
        return collection[index];
    }

    void reset() override {
        index = 0;
    }
};


// Step 3: Define the Aggregate Interface
// Aggregate Interface
template <typename T>
class Aggregate {
public:
    virtual Iterator<T>* createIterator() = 0;
    virtual ~Aggregate() = default;
};


// Step 4: Define the Concrete Aggregate (Collection)
template <typename T>
class ConcreteAggregate : public Aggregate<T> {
private:
    std::vector<T> collection;
    
public:
    ConcreteAggregate(const std::initializer_list<T>& list) {
        collection = list;
    }

    Iterator<T>* createIterator() override {
        return new ConcreteIterator<T>(collection);
    }

    void addItem(const T& item) {
        collection.push_back(item);
    }

    void removeItem() {
        if (!collection.empty()) {
            collection.pop_back();
        }
    }

    size_t size() const {
        return collection.size();
    }
};


// Step 5: Client Code
int main() {
    ConcreteAggregate<int> collection = {1, 2, 3, 4, 5};

    // Create an iterator
    Iterator<int>* iterator = collection.createIterator();

    // Traverse the collection
    while (iterator->hasNext()) {
        std::cout << iterator->next() << " ";
    }
    std::cout << std::endl;

    // Reset the iterator and traverse again
    iterator->reset();
    while (iterator->hasNext()) {
        std::cout << iterator->next() << " ";
    }
    std::cout << std::endl;

    delete iterator;

    return 0;
}


/*
OUTPUT:

1 2 3 4 5
1 2 3 4 5

*/