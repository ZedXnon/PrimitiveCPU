# 16-bit Computer Simulator Makefile
# -----------------------------------

# Directory configuration
SRC_DIR := src
OBJ_DIR := obj
INC_DIR := include
BIN := cpu_sim

# Compiler settings
CC := gcc
CFLAGS := -Wall -Wextra -Werror -I$(INC_DIR)

# Find all source files recursively
SRC_FILES := $(shell find $(SRC_DIR) -name "*.c")
OBJ_FILES := $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRC_FILES))

# Default target
.PHONY: all
all: $(BIN)

# Create the executable
$(BIN): $(OBJ_FILES)
	@echo "Linking $@"
	@$(CC) $^ -o $@

# Compile source files to object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	@echo "Compiling $<"
	@$(CC) $(CFLAGS) -c $< -o $@

# Testing with foundational components always included
# Usage: make test FILE=components/alu/adders.c
.PHONY: test
test:
	@if [ -z "$(FILE)" ]; then \
		echo "Error: Please specify a file with FILE=path/to/file.c"; \
		exit 1; \
	fi
	@echo "Compiling $(SRC_DIR)/$(FILE) with dependencies..."
	
	# Always include core files (logic_gates.c is fundamental)
	@echo "$(SRC_DIR)/logic_gates.c" > .deps_core
	
	# Find dependencies
	@rm -f .deps_tmp .deps_final
	@echo "$(SRC_DIR)/$(FILE)" > .deps_tmp
	@while [ -s .deps_tmp ]; do \
		cat .deps_tmp >> .deps_final; \
		cat .deps_tmp | xargs $(CC) $(CFLAGS) -M | \
			sed 's/\\//g' | \
			sed 's/^.*\.o://' | \
			tr ' ' '\n' | \
			grep "^$(SRC_DIR)/.*\.c$$" | \
			sort -u > .deps_new; \
		comm -23 .deps_new .deps_final > .deps_tmp; \
	done
	
	@echo "Compiling src/main.c and all dependencies..."
	@$(CC) $(CFLAGS) src/main.c $(SRC_DIR)/logic_gates.c `cat .deps_final` -o test_binary || \
	  (echo "First attempt failed, adding all source files as fallback..." && \
	   $(CC) $(CFLAGS) src/main.c $(SRC_DIR)/logic_gates.c $(SRC_DIR)/$(FILE) -o test_binary)
	
	@rm -f .deps_tmp .deps_new .deps_final .deps_core
	@echo "Created test_binary with $(FILE) and all dependencies"

# Clean up
.PHONY: clean
clean:
	@echo "Cleaning up..."
	@rm -rf $(OBJ_DIR)
	@rm -f $(BIN) test_binary .deps_tmp .deps_new .deps_final .deps_core