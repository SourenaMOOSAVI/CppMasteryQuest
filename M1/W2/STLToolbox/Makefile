CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -g
INCLUDES = -Iinclude

SRC_DIR = src
TEST_DIR = tests
BUILD_DIR = build

# Find all source files in src and tests directories
SRC_FILES = $(wildcard $(SRC_DIR)/*.cpp)
TEST_FILES = $(wildcard $(TEST_DIR)/*.cpp)

# Create a list of object files based on the source files
SRC_OBJS = $(SRC_FILES:$(SRC_DIR)/%.cpp=$(BUILD_DIR)/src/%.o)
TEST_OBJS = $(TEST_FILES:$(TEST_DIR)/%.cpp=$(BUILD_DIR)/tests/%.o)

# Default target
all: test_file_io test_data_processing test_statistics test_cli data_analyzer

# Pattern rule for building object files
$(BUILD_DIR)/src/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(dir $@)  # Create the build directory if it doesn't exist
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

$(BUILD_DIR)/tests/%.o: $(TEST_DIR)/%.cpp
	@mkdir -p $(dir $@)  # Create the build directory if it doesn't exist
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

# Rule for building test_file_io
test_file_io: $(BUILD_DIR)/src/file_io.o $(BUILD_DIR)/tests/test_file_io.o
	$(CXX) $^ -o $@

# Rule for building test_data_processing
test_data_processing: $(BUILD_DIR)/src/data_processing.o $(BUILD_DIR)/tests/test_data_processing.o
	$(CXX) $^ -o $@

# Rule for building test_statistics
test_statistics: $(BUILD_DIR)/src/statistics.o $(BUILD_DIR)/tests/test_statistics.o
	$(CXX) $^ -o $@

# Rule for building test_cli
test_cli: $(BUILD_DIR)/src/cli.o $(BUILD_DIR)/tests/test_cli.o
	$(CXX) $^ -o $@

# Rule for building the main program
data_analyzer: $(SRC_OBJS)
	$(CXX) $^ -o $@

# Clean rule
clean:
	rm -rf $(BUILD_DIR) test_file_io test_data_processing test_statistics test_cli main_program
