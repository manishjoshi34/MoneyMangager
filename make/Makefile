GCC=g++
FLAGS= -std=c++17 -g -lpthread
SRC_PATH = ../src
BUILD_PATH = build
BIN_PATH = $(BUILD_PATH)/bin
NAME = mysoft
SRC_EXT = cpp
INCLUDES = -I ../includes -I ../includes/ThreadPool -I ../includes/Logger -I ../includes/Commands

SOURCES = $(shell find $(SRC_PATH) -name "*.$(SRC_EXT)"| sort -k 1nr | cut -f2-)
OBJECTS = $(SOURCES:$(SRC_PATH)/%.$(SRC_EXT)=$(BUILD_PATH)/%.o)
Default: $(NAME)
	@echo "Done"

.PHONEY: $(NAME)
$(NAME): dirs
	@$(MAKE) all
.PHONEY: dirs
dirs: 
	@echo "Creating dir..."
	@echo $(SOURCES)
	@echo $(OBJECTS)
	@mkdir -p $(BUILD_PATH)
	@mkdir -p $(BIN_PATH)
	@mkdir -p $(BUILD_PATH)/Commands

.PHONEY: all
all: $(OBJECTS)
	@echo "Linking....$@"
	$(GCC) $(OBJECTS) $(FLAGS) -o $(BIN_PATH)/$(NAME) 

$(BUILD_PATH)/%.o: $(SRC_PATH)/%.$(SRC_EXT)
	@echo "Compiling: $< -> $@"
	$(GCC)  -c $< $(FLAGS) -o $@ $(INCLUDES)

.PHONEY: clean
clean :
	@echo "Deleting $(BIN_NAME) symlink"
	@$(RM) $(NAME)
	@echo "Deleting directories"
	@$(RM) -rf $(BUILD_PATH)
	@$(RM) -rf $(BIN_PATH)


