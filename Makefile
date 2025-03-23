# Compiler and flags
CXX := g++
CXXFLAGS := -O2 -Wall -MMD -MP

# Directories
SRC_DIR := .
BIN_DIR := bin
OBJ_DIR := $(BIN_DIR)/obj

# Executable file
TARGET := $(BIN_DIR)/complex_program

# Source and object files
SRC_FILES := $(SRC_DIR)/mycomplex.cpp $(SRC_DIR)/testcmp.cpp
OBJ_FILES := $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRC_FILES))
DEP_FILES := $(OBJ_FILES:.o=.d)

# Default rule
all: $(TARGET)

# Create directories
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(BIN_DIR):
	mkdir -p $(BIN_DIR)

# Compile object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	@echo "Compiling $<..."
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Link executable
$(TARGET): $(OBJ_FILES) | $(BIN_DIR)
	@echo "Linking $@..."
	$(CXX) $(CXXFLAGS) $(OBJ_FILES) -o $@

# Clean up generated files
clean:
	@echo "Cleaning up..."
	rm -rf $(BIN_DIR)

# Include dependency files
-include $(DEP_FILES)

# Phony targets
.PHONY: all clean
