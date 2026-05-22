CC  ?= clang
CXX ?= clang++
LD  := $(CC)

# ============================================================
# Source files
# ============================================================

SRC_ALL := $(wildcard *.c)

MAIN_SRC := test_uov.c
KAT_SRC  := ./KAT/test_kat.c

SRC := $(filter-out $(MAIN_SRC) $(KAT_SRC),$(SRC_ALL))

# ============================================================
# Compiler flags
# ============================================================

CFLAGS := \
	-O3 \
	-std=c99 \
	-Wall \
	-Wextra \
	-Wpedantic \
	-Werror \
	-fno-omit-frame-pointer

CPPFLAGS := -I.
LDFLAGS :=
LIBS    := -lcrypto

# ============================================================
# Default target
# ============================================================

all: test

test:
	$(CC) $(CPPFLAGS) $(CFLAGS) $(SRC) $(MAIN_SRC) $(LDFLAGS) $(LIBS) -o test.exe
	@echo "Built test.exe"

kat:
	$(CC) $(CPPFLAGS) $(CFLAGS) $(SRC) $(KAT_SRC) $(LDFLAGS) $(LIBS) -o kat.exe
	@echo "Built kat.exe"

clean:
	rm -f *.exe

.PHONY: all test kat clean