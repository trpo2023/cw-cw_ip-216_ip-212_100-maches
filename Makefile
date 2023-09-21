# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++11 -Wall
LDFLAGS = -lm

# Directories
SRC_DIR = src
BIN_DIR = bin
OBJ_DIR = $(BIN_DIR)/obj
TEST_DIR = test
LIB_DIR = $(BIN_DIR)/lib

# Target names
APP_NAME = matches
LIB_NAME = libmatches
APP_TEST_NAME = matchestest

# Source files
APP_SOURCES = $(shell find $(SRC_DIR)/$(APP_NAME) -name '*.$(SRC_EXT)')
LIB_SOURCES = $(shell find $(SRC_DIR)/$(LIB_NAME) -name '*.$(SRC_EXT)')
TEST_SOURCES = $(shell find $(TEST_DIR) -name '*.$(SRC_EXT)')
MAIN_SOURCE = src/matches/main.cpp
# Object files
APP_OBJECTS = $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(APP_SOURCES))
LIB_OBJECTS = $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(LIB_SOURCES))
TEST_OBJECTS = $(patsubst $(TEST_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(TEST_SOURCES))

# Include directories
INCLUDE_DIRS = -I$(SRC_DIR)/$(APP_NAME) -I$(SRC_DIR)/$(LIB_NAME) -Ithirdparty

# Targets
APP_TARGET = $(BIN_DIR)/$(APP_NAME)
LIB_TARGET = $(LIB_DIR)/$(LIB_NAME).a
TEST_TARGET = $(BIN_DIR)/$(APP_TEST_NAME)

# Phony targets
.PHONY: all clean test run

# Default target
all: prepare $(APP_TARGET)

prepare:
	mkdir -p $(BIN_DIR) $(OBJ_DIR) $(LIB_DIR)

$(APP_TARGET): $(MAIN_SOURCE) $(APP_OBJECTS) $(LIB_TARGET)
	$(CXX) $(CXXFLAGS) $(INCLUDE_DIRS) $^ -o $@ $(LDFLAGS)

$(LIB_TARGET): $(LIB_OBJECTS)
	ar rcs $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDE_DIRS) -MMD -c $< -o $@

test: $(TEST_TARGET)

$(TEST_TARGET): $(TEST_OBJECTS) $(LIB_TARGET)
	$(CXX) $(CXXFLAGS) $(INCLUDE_DIRS) $^ -o $@ $(LDFLAGS)

clean:
	$(RM) -rf $(BIN_DIR)

run: prepare $(APP_TARGET)
	./$(APP_TARGET)
# Include dependency files
-include $(OBJ_DIR)/*.d
