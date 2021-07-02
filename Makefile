COMPILER = gcc

COMPILER_FLAGS = `guile-config compile`

LINKER_FLAGS = `guile-config link`

SOURCE = main.c

EXECUTABLE = main

all: $(SOURCE)
	$(COMPILER) $(SOURCE) -o $(EXECUTABLE) $(COMPILER_FLAGS) $(LINKER_FLAGS)
