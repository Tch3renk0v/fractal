PROJECT_ROOT = $(dir $(abspath $(lastword $(MAKEFILE_LIST))))

CC   = gcc
CXX  = g++
EXEC = madelbrot.exec
SRC  = $(PROJECT_ROOT)main.cpp $(PROJECT_ROOT)Window.cpp $(PROJECT_ROOT)Fractale.cpp
OBJS = $(SRC:.cpp=.o)
#OBJS += $(SRC:.c=.o)

LDFLAGS += -lSDL2 -fopenmp

ifeq ($(BUILD_MODE),debug)
	CFLAGS += -g 
else ifeq ($(BUILD_MODE),run)
	CFLAGS += -O2  -fopenmp
#else
#	$(error Build mode $(BUILD_MODE) not supported by this Makefile)
endif

all: $(EXEC)

$(EXEC):	$(OBJS)
	$(CXX) $(LDFLAGS) -o $@ $^

%.o:	$(PROJECT_ROOT)%.cpp
	$(CXX) -c $(CFLAGS) $(CXXFLAGS) $(CPPFLAGS) -o $@ $<

%.o:	$(PROJECT_ROOT)%.c
	$(CC) -c $(CFLAGS) $(CPPFLAGS) -o $@ $<

clean:
	rm -rf $(EXEC) $(OBJS)
