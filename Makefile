CFLAG = -Wall -ansi -std=c++11
CLIB = -lpthread

CC = g++
CXX = g++
TARGET_EXEC ?= hspp

BUILD_DIR ?= ./bin
SRC_DIRS ?= ./src

SRCS := $(shell find $(SRC_DIRS) -name *.cpp)
OBJS := $(SRCS:%=$(BUILD_DIR)/%.o)
DEPS := $(OBJS:.o=.d)

INC_DIRS := $(shell find $(SRC_DIRS) -type d)
INC_FLAGS := $(addprefix -I,$(INC_DIRS))

CPPFLAGS ?= $(INC_FLAGS) -MMD -MP

$(TARGET_EXEC): $(OBJS)
	$(CC) $(OBJS) $(CFLAG) -o $@ $(LDFLAGS) $(CLIB)

# c++ source
$(BUILD_DIR)/%.cpp.o: %.cpp
	$(MKDIR_P) $(dir $@)
	$(CXX) $(CPPFLAGS) $(CFLAG) $(CXXFLAGS) -c $< -o $@ $(CLIB)

clean:
	$(RM) $(TARGET_EXEC)
	$(RM) -r $(BUILD_DIR)
	
MKDIR_P ?= mkdir -p
