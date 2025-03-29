#include <iostream>
#include <filesystem>
#include <string>

namespace fs = std::filesystem;

int main() {
    std::string directoryPath = "."; // Current directory, you can change it to your specific directory path
    int dpCount = 0;

    // Iterate over files in the directory
    for (const auto& entry : fs::directory_iterator(directoryPath)) {
        if (entry.is_regular_file()) {
            // Check if "DP" is in the filename
            if (entry.path().filename().string().find("DP") != std::string::npos) {
                dpCount++;
            }
        }
    }

    std::cout << "Number of files with 'DP' in their name: " << dpCount << std::endl;

    return 0;
}

