#!/bin/bash

# build.sh
# Bash build file for read_resistance.cpp

# Compile the C++ application
g++ -o read_resistance read_resistance.cpp AnalogIn.cpp -std=c++11

# Check if compilation was successful
if [ $? -eq 0 ]; then
    echo "Build successful. You can now run './read_resistance'."
else
    echo "Build failed."
fi
