// 1.) Strategy Interface (Abstract Class)
#include <vector>
#include <algorithm>
#include <iostream>

class SortingStrategy {
public:
    virtual void sort(std::vector<int>& data) = 0;  // Abstract sort method
    virtual ~SortingStrategy() {}  // Virtual destructor
};


// 2.) Concrete Strategies (Different Sorting Algorithms)
// Here, we implement two sorting algorithms: Bubble Sort and Quick Sort.
class BubbleSort : public SortingStrategy {
public:
    void sort(std::vector<int>& data) override {
        for (size_t i = 0; i < data.size(); i++) {
            for (size_t j = 0; j < data.size() - i - 1; j++) {
                if (data[j] > data[j + 1]) {
                    std::swap(data[j], data[j + 1]);
                }
            }
        }
        std::cout << "BubbleSort completed!" << std::endl;
    }
};

class QuickSort : public SortingStrategy {
public:
    void quicksort(std::vector<int>& data, int low, int high) {
        if (low < high) {
            int pi = partition(data, low, high);
            quicksort(data, low, pi - 1);
            quicksort(data, pi + 1, high);
        }
    }

    int partition(std::vector<int>& data, int low, int high) {
        int pivot = data[high];
        int i = (low - 1);
        for (int j = low; j < high; j++) {
            if (data[j] <= pivot) {
                i++;
                std::swap(data[i], data[j]);
            }
        }
        std::swap(data[i + 1], data[high]);
        return i + 1;
    }

    void sort(std::vector<int>& data) override {
        quicksort(data, 0, data.size() - 1);
        std::cout << "QuickSort completed!" << std::endl;
    }
};


// 3. Context Class
// The context class will maintain a reference to a SortingStrategy object and allow switching between strategies at runtime.
class SortContext {
private:
    SortingStrategy* strategy;

public:
    SortContext(SortingStrategy* strategy) : strategy(strategy) {}

    // Method to change the sorting strategy at runtime
    void setStrategy(SortingStrategy* newStrategy) {
        strategy = newStrategy;
    }

    // Method to perform sorting
    void executeSort(std::vector<int>& data) {
        strategy->sort(data);
    }
};


// 4. Main Function
// Finally, the client code will create a SortContext and set the sorting strategy.
// It can also change the strategy at runtime.

int main() {
    std::vector<int> data = { 5, 2, 9, 1, 5, 6 };

    // Initializing context with BubbleSort
    SortContext context(new BubbleSort());
    context.executeSort(data);  // Will use BubbleSort

    // Output the sorted data (Bubble Sort)
    for (int num : data) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // Now changing the strategy to QuickSort
    context.setStrategy(new QuickSort());
    data = { 5, 2, 9, 1, 5, 6 };  // Resetting the data
    context.executeSort(data);   // Will use QuickSort

    // Output the sorted data (Quick Sort)
    for (int num : data) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}


// Strategy : Single Responsibility Principle
// Strategy : Open / Closed Principle
// Strategy : Dependency Inversion principle

