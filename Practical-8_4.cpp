#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

int main() {
    string filename;
    ifstream file;

    // Retry mechanism for file opening
    while(true) {
        cout << "Enter file path (or type 'exit' to quit): ";
        cin >> filename;

        if(filename == "exit") {
            cout << "Exiting program.\n";
            return 0;
        }

        file.open(filename);

        if(file.is_open()) {
            break;
        } else {
            cout << "Error: File cannot be opened. Try again.\n";
        }
    }

    string line;
    int lineNumber = 0;

    cout << "\n--- Processing File ---\n";

    // Read file line-by-line
    while(getline(file, line)) {
        lineNumber++;

        stringstream ss(line);
        double num, sum = 0;
        int count = 0;
        bool valid = true;

        // Process numbers in each line
        while(ss >> num) {
            sum += num;
            count++;
        }

        // Check for corrupted data
        if(!ss.eof()) {
            valid = false;
        }

        if(valid && count > 0) {
            double avg = sum / count;
            cout << "Line " << lineNumber 
                 << " → Sum: " << sum 
                 << ", Avg: " << avg << endl;
        } else {
            cout << "Line " << lineNumber 
                 << " → Invalid data skipped.\n";
        }
    }

    file.close();

    cout << "\nFile processing completed.\n";

    return 0;
}