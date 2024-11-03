CC:=gcc
SRC:=.
BUILD:=../build
TARGET:=$(BUILD)/cstring
INCLUDE:=-I$(SRC)/include

SOURCES:=$(wildcard $(SRC)/*.c)
OBJECTS:=$(SOURCES:$(SRC)/%.c=$(BUILD)/%.o)

CFLAGS:=-Wall
CFLAGS+=-Wextra
CFLAGS+=-pedantic
CFLAGS+=-std=c99
CFLAGS+=-O2

DEBUG:=-g
STRIP:=strip $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(INCLUDE) $(OBJECTS) -o $@

$(BUILD)/%.o: $(SRC)/%.c
	$(shell mkdir -p $(dir $@))
	$(CC) $(INCLUDE) $(CFLAGS) -c $< -o $@

.PHONY: clean run


run:
	$(TARGET)

clean:
	rm -rf $(BUILD)
