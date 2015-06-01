CXX=g++
OPTS=-O
CFLAGS=$(OPTS) -Wall
SRC=src

all:
	- echo "Specify OS!"

linux: $(SRC)/netstat_linux.cpp $(SRC)/netstat_util.cpp $(SRC)/string_util.cpp
	$(CXX) $(CFLAGS) $^ -o $@

windows: $(SRC)/netstat_windows.cpp $(SRC)/netstat_util.cpp $(SRC)/string_util.cpp
	$(CXX) $(CFLAGS) $^ -o $@

solaris: $(SRC)/netstat_solaris.cpp $(SRC)/netstat_util.cpp $(SRC)/string_util.cpp
	$(CXX) $(CFLAGS) $^ -o $@

solaris_112: $(SRC)/netstat_solaris.cpp $(SRC)/netstat_util.cpp $(SRC)/string_util.cpp
	$(CXX) $(CFLAGS) -DSOLARIS_112 $^ -o $@

bsd: $(SRC)/netstat_bsd.cpp $(SRC)/netstat_util.cpp $(SRC)/string_util.cpp
	$(CXX) $(CFLAGS) $^ -o $@

clean:
	- rm -f linux windows solaris solaris_112 bsd
