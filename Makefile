CXX=g++
OPTS=-O
CFLAGS=$(OPTS) -Wall
SRC=src

all:
	- echo "Specify OS!"

linux: $(SRC)/netstat_linux.cpp
	$(CXX) $(CFLAGS) $^ -o $@

windows: $(SRC)/netstat_windows.cpp
	$(CXX) $(CFLAGS) $^ -o $@

solaris: $(SRC)/netstat_solaris.cpp
	$(CXX) $(CFLAGS) $^ -o $@

clean:
	- rm -f linux windows solaris
