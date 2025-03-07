# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -Iinclude -std=c++17 -Wall -Wextra

# Source files
SRCS = src/main.cpp src/CarRentalSystem.cpp src/Garage.cpp src/RentalContract.cpp \
       src/Customer.cpp src/Vehicle.cpp src/Car.cpp src/SUV.cpp src/Sedan.cpp \
       src/Van.cpp src/Service.cpp

# Output executable
TARGET = car_rental_system

# Default target
all: $(TARGET)

# Rule to build the target
$(TARGET): $(SRCS)
	$(CXX) $(CXXFLAGS) $(SRCS) -o $(TARGET)

# Clean up build files
clean:
	rm -f $(TARGET)

# Phony targets
.PHONY: all clean