CXX=g++
OPTS=-O
CFLAGS=$(OPTS) -Wall
SRC=src

all:
	- echo "Specify an OS:\n  make linux\n  make solaris\n  make solaris_112\n  make bsd\n  make osx"

linux: $(SRC)/main.cpp $(SRC)/netstat_linux.cpp $(SRC)/netstat_util.cpp $(SRC)/string_util.cpp
	$(CXX) $(CFLAGS) $^ -o $@

#windows: $(SRC)/main.cpp $(SRC)/netstat_windows.cpp $(SRC)/netstat_util.cpp $(SRC)/string_util.cpp
#	$(CXX) $(CFLAGS) $^ -lIPHlpApi -lWs2_32 -o $@

solaris: $(SRC)/main.cpp $(SRC)/netstat_solaris.cpp $(SRC)/netstat_util.cpp $(SRC)/string_util.cpp
	$(CXX) $(CFLAGS) $^ -o $@

bsd: $(SRC)/main.cpp $(SRC)/netstat_bsd.cpp $(SRC)/netstat_util.cpp $(SRC)/string_util.cpp
	$(CXX) $(CFLAGS) $^ -o $@

osx: $(SRC)/main.cpp $(SRC)/netstat_osx.cpp $(SRC)/netstat_util.cpp $(SRC)/string_util.cpp
	$(CXX) $(CFLAGS) $^ -o $@

clean:
	- rm -f linux windows solaris solaris_112 bsd osx
