# The variable CC specifies which compiler will be used.
# (because different unix systems may use different compilers)
CXX=g++

# The variable CFLAGS specifies compiler options
#   -c :    Only compile (don't link)
#   -Wall:  Enable all warnings about lazy / dangerous C programming 
#  You can add additional options on this same line..
#  WARNING: NEVER REMOVE THE -c FLAG, it is essential to proper operation
CPPFLAGS=-Wall -g

# All of the .h header files to use as dependencies
HEADERS=City.hpp

# All of the object files to produce as intermediary work
OBJECTS=main.o

# The final program to build
EXECUTABLE=main

# --------------------------------------------

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CXX) $(OBJECTS) -o $(EXECUTABLE)

%.o: %.c $(HEADERS)
	$(CXX) $(CPPFLAGS) -o $@ $(EXECUTABLE) $<

clean:
	rm -rf *.o $(EXECUTABLE)