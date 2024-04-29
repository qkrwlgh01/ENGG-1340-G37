#include <string>
#include <fstream> // Standard library for file handling
#include <sstream> // Standard library for string stream operations

// Function to read the entire contents of a file into a string
std::string read_file_to_string(const std::string& filepath) { 
    std::ifstream file(filepath); // Open the file for reading
    std::stringstream buffer; // Create a stringstream to hold the data
    buffer << file.rdbuf(); // Read the data from the file buffer into the stringstream
    return buffer.str();  // Convert stringstream to string and return
}
