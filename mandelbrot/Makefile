PROJECT_ROOT = $(dir $(abspath $(lastword $(MAKEFILE_LIST))))

CC   = gcc
CXX  = g++
EXEC = madelbrot.exec
SRC  = $(PROJECT_ROOT)main.cpp $(PROJECT_ROOT)Window.cpp $(PROJECT_ROOT)Fractale.cpp
OBJS = $(SRC:.cpp=.o)
#OBJS += $(SRC:.c=.o)

LDFLAGS += -lSDL2 -fopenmp
CFLAGS += -fopenmp -O2
CXXFLAGS += -fopenmp -O2
ifeq ($(BUILD_MODE),debug)
	CFLAGS += -g 
else ifeq ($(BUILD_MODE),run)
	CFLAGS += -O2  -fopenmp
#else
#	$(error Build mode $(BUILD_MODE) not supported by this Makefile)
endif

all: $(EXEC)

$(EXEC):	$(OBJS)
	$(CXX)  $(LDFLAGS) -o $@ $^

%.o:	$(PROJECT_ROOT)%.cpp
	$(CXX) -fopenmp -c $(CFLAGS) $(CXXFLAGS) $(CPPFLAGS) -o $@ $<

%.o:	$(PROJECT_ROOT)%.c
	$(CC) -fopenmp -c $(CFLAGS) $(CPPFLAGS) -o $@ $<

clean:
	rm -rf $(EXEC) $(OBJS)
