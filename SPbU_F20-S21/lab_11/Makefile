CXX     = g++
MKDIR   = mkdir
DELETE  = rm

INCLUDE = include
SOURCE  = src
BUILD   = obj

CXXFLAGS  = -I$(INCLUDE) -std=c++11 # -g # -Werror

OBJECTS = $(patsubst $(SOURCE)/%.cpp, $(BUILD)/%.o, $(wildcard $(SOURCE)/*.cpp))
TARGET  = lab_11

.PHONY: all build clean $(TARGET)

all: build

build: $(TARGET)

setup:
	@ $(MKDIR) -p $(BUILD)

$(TARGET): setup $(OBJECTS)
	@ $(CXX) $(OBJECTS) -o $(TARGET)

clean:
	@ $(DELETE) -rf $(OBJECTS) $(BUILD) $(TARGET)

$(BUILD)/%.o: $(SOURCE)/%.cpp
	@ $(CXX) $(CXXFLAGS) -c $< -o $@
