CXX=g++
OPTS=-O
CFLAGS=$(OPTS) -Wall
SRC=src

all:
	- echo "Specify an OS:\n  make linux\n  make windows\n  make solaris\n  make solaris_112\n  make bsd"

linux: $(SRC)/main.cpp $(SRC)/netstat_linux.cpp $(SRC)/netstat_util.cpp $(SRC)/string_util.cpp
	$(CXX) $(CFLAGS) $^ -o $@

windows: $(SRC)/main.cpp $(SRC)/netstat_windows.cpp $(SRC)/netstat_util.cpp $(SRC)/string_util.cpp
	$(CXX) $(CFLAGS) $^ -lIPHlpApi -lWs2_32 -o $@

solaris: $(SRC)/main.cpp $(SRC)/netstat_solaris.cpp $(SRC)/netstat_util.cpp $(SRC)/string_util.cpp
	$(CXX) $(CFLAGS) $^ -o $@

solaris_112: $(SRC)/main.cpp $(SRC)/netstat_solaris.cpp $(SRC)/netstat_util.cpp $(SRC)/string_util.cpp
	$(CXX) $(CFLAGS) -DSOLARIS_112 $^ -o $@

bsd: $(SRC)/main.cpp $(SRC)/netstat_bsd.cpp $(SRC)/netstat_util.cpp $(SRC)/string_util.cpp
	$(CXX) $(CFLAGS) $^ -o $@

clean:
	- rm -f linux windows solaris solaris_112 bsd
