# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -Iinclude -std=c++17 -Wall -Wextra

# Source files (relative to the root directory)
SRCS = src/main.cpp src/CarRentalSystem.cpp src/Garage.cpp src/RentalContract.cpp \
       src/Customer.cpp src/Vehicle.cpp src/Car.cpp src/SUV.cpp src/Sedan.cpp \
       src/Van.cpp src/Service.cpp

# Object files (automatically generated from source files)
OBJS = $(SRCS:.cpp=.o)

# Output executable
TARGET = car_rental_system

# Default target
all: $(TARGET)

# Rule to build the target
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(TARGET)

# Rule to compile .cpp files into .o files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up build files
clean:
	rm -f $(TARGET) $(OBJS)

# Phony targets
.PHONY: all clean