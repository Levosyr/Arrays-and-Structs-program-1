#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

const int NUM_RUNNERS = 5;
const int NUM_DAYS = 7;

// Function prototypes
void readData(string names[], int miles[][NUM_DAYS]);
void calculateStats(const string names[], const int miles[][NUM_DAYS], int totals[], double averages[]);
void outputResults(const string names[], const int miles[][NUM_DAYS], const int totals[], const double averages[]);

int main() {
    string names[NUM_RUNNERS];
    int miles[NUM_RUNNERS][NUM_DAYS];
    int totals[NUM_RUNNERS];
    double averages[NUM_RUNNERS];

    // Read data from file
    readData(names, miles);

    // Calculate total miles and average miles
    calculateStats(names, miles, totals, averages);

    // Output results
    outputResults(names, miles, totals, averages);

    return 0;
}

// Function to read and store the runners' names and the numbers of miles run each day
void readData(string names[], int miles[][NUM_DAYS]) {
    ifstream inputFile("Marathon runners.txt");
    if (!inputFile) {
        cerr << "Error: Unable to open input file." << endl;
        exit(1);
    }

    for (int i = 0; i < NUM_RUNNERS; ++i) {
        inputFile >> names[i];
        for (int j = 0; j < NUM_DAYS; ++j) {
            inputFile >> miles[i][j];
        }
    }

    inputFile.close();
}

// Function to find the total miles run by each runner and the average number of miles run each day
void calculateStats(const string names[], const int miles[][NUM_DAYS], int totals[], double averages[]) {
    for (int i = 0; i < NUM_RUNNERS; ++i) {
        int totalMiles = 0;
        for (int j = 0; j < NUM_DAYS; ++j) {
            totalMiles += miles[i][j];
        }
        totals[i] = totalMiles;
        averages[i] = static_cast<double>(totalMiles) / NUM_DAYS;
    }
}

// Function to output the results
void outputResults(const string names[], const int miles[][NUM_DAYS], const int totals[], const double averages[]) {
    // Output header
    cout << setw(15) << left << "Runner";
    for (int day = 1; day <= NUM_DAYS; ++day) {
        cout << setw(10) << left << "Day " << day;
    }
    cout << setw(15) << left << "Total Miles" << setw(15) << left << "Average Miles" << endl;

    // Output data for each runner
    for (int i = 0; i < NUM_RUNNERS; ++i) {
        cout << setw(15) << left << names[i];
        for (int j = 0; j < NUM_DAYS; ++j) {
            cout << setw(10) << left << miles[i][j];
        }
        cout << setw(15) << left << totals[i] << setw(15) << left << averages[i] << endl;
    }
}
