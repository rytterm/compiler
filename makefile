CC = g++
CFLAGS = -Wall -Wextra -g -O0 -MMD -MP


SRC_DIR = src
OBJ_DIR = build

SRCS := $(shell find $(SRC_DIR) -name '*.cc')
OBJS := $(patsubst $(SRC_DIR)/%.cc,$(OBJ_DIR)/%.o,$(SRCS))
DEPS := $(OBJS:.o=.d)

TARGET = a.out

.PHONY: all clean debug

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cc
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/%.d: $(SRC_DIR)/%.cc
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -MMD -MP -MF $@ -c $<

-include $(DEPS)

clean:
	rm -rf $(OBJ_DIR) $(TARGET)

# Debug rule to print CFLAGS
debug:
	@echo "CFLAGS: $(CFLAGS)"
