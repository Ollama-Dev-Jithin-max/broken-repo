#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>

using namespace std;

int main() {
    srand(time(0));

    system("mkdir output >nul 2>nul");

    ofstream dataFile("output/sensor_data.txt");
    dataFile << "Sensor Data Log\n";
    dataFile << "----------------\n";
    for (int i = 0; i < 5; i++) {
        dataFile << "Reading " << i + 1 << ": "
                 << (rand() % 100) << " units\n";
    }
    dataFile.close();

    ofstream logFile("run.log", ios::app);
    logFile << "Program executed at UNIX time "
            << time(0) << endl;
    logFile.close();

    ofstream tempFile("temp.tmp");
    tempFile << "Temporary buffer value = "
             << rand() % 1000 << endl;
    tempFile.close();

    ofstream exeFile("program.exe");
    exeFile << "Fake executable artifact\n";
    exeFile.close();

    system("mkdir cache >nul 2>nul");
    ofstream cacheFile("cache/cache.data");
    cacheFile << "Cached value = "
              << rand() % 500 << endl;
    cacheFile.close();

    cout << "Sensor data generated successfully.\n";
    cout << "Check the output/ directory.\n";

    return 0;
}
