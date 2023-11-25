// Tim Fortune HW9 Part1 read_resistance.cpp
/*
  read_resistance.cpp
 
  Description:
    A C++ application to determine the resistance of the bottom resistor in a voltage divider.
    Uses the AnalogIn class to read analog values from AIN0 on a BeagleBone.
    Connects to a voltage divider circuit with a 10kΩ top resistor and calculates the resistance
    of the bottom resistor. Prints the result to the nearest Ohm.
 
  Command Line Arguments:
    None
 
  Example Invocation:
   debian@beaglebone:~$ ./read_resistance
 */



#include "AnalogIn.h"
#include <iostream>
#include <cmath>

int main() {
    // Create an instance of AnalogIn for AIN0
    AnalogIn analogIn(0);

    // Constants for the voltage divider circuit
    const double topResistor = 10000.0; // 10kΩ
    const double totalVoltage = 1.8;    // Voltage across both resistors

    // Read ADC value using AnalogIn class
    int adcValue = analogIn.readAdcSample();

    // Calculate the voltage across the bottom resistor using the voltage divider formula
    double voltageAcrossBottomResistor = totalVoltage * (static_cast<double>(adcValue) / 4095.0);

    // Calculate the resistance of the bottom resistor
    double bottomResistor = (voltageAcrossBottomResistor * topResistor) / (totalVoltage - voltageAcrossBottomResistor);

    // Print the result to the nearest Ohm
    std::cout << "Using AIN" << analogIn.getNumber() << " to read analog value." << std::endl;
    std::cout << "Measuring resistance ..." << std::endl;
    std::cout << "ADC value is: " << adcValue << std::endl;

    if (bottomResistor < 1000) {
        std::cout << "Resistance: " << std::round(bottomResistor) << " Ohms" << std::endl;
    } else {
        std::cout << "Resistance: " << std::round(bottomResistor / 1000.0) << "K Ohms" << std::endl;
    }

    return 0;
}
