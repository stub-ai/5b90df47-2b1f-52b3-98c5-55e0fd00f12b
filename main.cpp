#include <iostream>
#include <vector>
#include <fstream>
#include <string>

class FuelTank {
public:
    int id;
    double capacity;
    double currentFuel;
    bool isConnected;
    bool isValveOpen;
    bool isBroken;

    FuelTank(int id, double capacity) {
        this->id = id;
        this->capacity = capacity;
        this->currentFuel = 0;
        this->isConnected = false;
        this->isValveOpen = false;
        this->isBroken = false;
    }

    void fill(double quantity) {
        if (!isBroken && isValveOpen && currentFuel + quantity <= capacity) {
            currentFuel += quantity;
        }
    }

    double consume(double quantity) {
        if (!isBroken && isValveOpen && currentFuel - quantity >= 0) {
            currentFuel -= quantity;
            return quantity;
        }
        return 0;
    }

    // Add other methods here...
};

class Engine {
public:
    double internalTankCapacity;
    double currentFuel;
    double consumptionRate;
    bool isRunning;

    Engine(double internalTankCapacity, double consumptionRate) {
        this->internalTankCapacity = internalTankCapacity;
        this->consumptionRate = consumptionRate;
        this->currentFuel = 0;
        this->isRunning = false;
    }

    void start() {
        isRunning = true;
    }

    void stop() {
        isRunning = false;
    }

    void consumeFuel() {
        if (isRunning && currentFuel - consumptionRate >= 0) {
            currentFuel -= consumptionRate;
        }
    }

    // Add other methods here...
};

class System {
public:
    Engine engine;
    std::vector<FuelTank> tanks;

    System(Engine engine) : engine(engine) {}

    void addTank(FuelTank tank) {
        tanks.push_back(tank);
    }

    // Add other methods here...
};

int main() {
    std::ifstream inputFile("input.txt");
    std::ofstream outputFile("output.txt");

    // Initialize system and engine here...

    std::string command;
    while (std::getline(inputFile, command)) {
        if (command == "stop_simulation") {
            break;
        }

        // Process other commands here...
    }

    inputFile.close();
    outputFile.close();

    return 0;
}