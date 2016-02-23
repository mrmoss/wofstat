CXX=g++
OPTS=-O
CFLAGS=$(OPTS) -Wall
SRC=src

NETSTAT_SRC=$(SRC)/netstat_util.cpp $(SRC)/string_util.cpp
MIKESTAT_SRC=$(SRC)/mikestat.cpp

all:
	- echo "Specify an OS:\n  make linux\n  make solaris\n  make bsd\n  make osx"

linux: $(SRC)/netstat_linux.cpp $(NETSTAT_SRC) $(MIKESTAT_SRC)
	$(CXX) $(CFLAGS) $(SRC)/netstat_linux.cpp $(NETSTAT_SRC) $(MIKESTAT_SRC) -o mikestat

windows: $(SRC)/netstat_windows.cpp $(NETSTAT_SRC) $(MIKESTAT_SRC)
	$(CXX) $(CFLAGS) $(SRC)/netstat_windows.cpp $(NETSTAT_SRC) $(MIKESTAT_SRC) -lIPHlpApi -lWs2_32 -o mikestat

solaris: $(SRC)/netstat_solaris.cpp $(NETSTAT_SRC) $(MIKESTAT_SRC)
	$(CXX) $(CFLAGS) $(SRC)/netstat_solaris.cpp $(NETSTAT_SRC) $(MIKESTAT_SRC) -o mikestat

bsd: $(SRC)/netstat_bsd.cppp $(NETSTAT_SRC) $(MIKESTAT_SRC)
	$(CXX) $(CFLAGS) $(SRC)/netstat_bsd.cpp $(NETSTAT_SRC) $(MIKESTAT_SRC) -o mikestat

osx: $(SRC)/netstat_osx.cpp $(NETSTAT_SRC) $(MIKESTAT_SRC)
	$(CXX) $(CFLAGS) $(SRC)/netstat_osx.cpp $(NETSTAT_SRC) $(MIKESTAT_SRC) -o mikestat

clean:
	- rm -f mikestat mikestat.exe
