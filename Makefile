CXX=g++
OPTS=-O
CFLAGS=$(OPTS) -Wall
SRC=src

GENERATE_SRC=$(SRC)/generate.cpp
NETSTAT_SRC=$(SRC)/netstat_util.cpp $(SRC)/string_util.cpp
MIKESTAT_SRC=$(SRC)/mikestat.cpp
GENFW_SRC=$(SRC)/genfw.cpp

all:
	- echo "Specify an OS:\n  make linux\n  make solaris\n  make bsd\n  make osx"

linux: $(SRC)/netstat_linux.cpp $(GENERATE_SRC) $(NETSTAT_SRC) $(MIKESTAT_SRC) $(GENFW_SRC)
	$(CXX) $(CFLAGS) $(SRC)/netstat_linux.cpp $(GENERATE_SRC) $(NETSTAT_SRC) $(MIKESTAT_SRC) -o mikestat
	$(CXX) $(CFLAGS) $(SRC)/netstat_linux.cpp $(GENERATE_SRC) $(NETSTAT_SRC) $(GENFW_SRC) -o genfw

#windows: $(SRC)/netstat_windows.cpp $(GENERATE_SRC) $(NETSTAT_SRC) $(MIKESTAT_SRC) $(GENFW_SRC)
#	$(CXX) $(CFLAGS) $(SRC)/netstat_windows.cpp $(GENERATE_SRC) $(NETSTAT_SRC) $(MIKESTAT_SRC) -o mikestat
#	$(CXX) $(CFLAGS) $(SRC)/netstat_windows.cpp $(GENERATE_SRC) $(NETSTAT_SRC) $(GENFW_SRC) -o genfw

solaris: $(SRC)/netstat_solaris.cpp $(GENERATE_SRC) $(NETSTAT_SRC) $(MIKESTAT_SRC) $(GENFW_SRC)
	$(CXX) $(CFLAGS) $(SRC)/netstat_solaris.cpp $(GENERATE_SRC) $(NETSTAT_SRC) $(MIKESTAT_SRC) -o mikestat
	$(CXX) $(CFLAGS) $(SRC)/netstat_solaris.cpp $(GENERATE_SRC) $(NETSTAT_SRC) $(GENFW_SRC) -o genfw

bsd: $(SRC)/netstat_bsd.cpp $(GENERATE_SRC) $(NETSTAT_SRC) $(MIKESTAT_SRC) $(GENFW_SRC)
	$(CXX) $(CFLAGS) $(SRC)/netstat_bsd.cpp $(GENERATE_SRC) $(NETSTAT_SRC) $(MIKESTAT_SRC) -o mikestat
	$(CXX) $(CFLAGS) $(SRC)/netstat_bsd.cpp $(GENERATE_SRC) $(NETSTAT_SRC) $(GENFW_SRC) -o genfw

osx: $(SRC)/netstat_osx.cpp $(GENERATE_SRC) $(NETSTAT_SRC) $(MIKESTAT_SRC) $(GENFW_SRC)
	$(CXX) $(CFLAGS) $(SRC)/netstat_osx.cpp $(GENERATE_SRC) $(NETSTAT_SRC) $(MIKESTAT_SRC) -o mikestat
	$(CXX) $(CFLAGS) $(SRC)/netstat_osx.cpp $(GENERATE_SRC) $(NETSTAT_SRC) $(GENFW_SRC) -o genfw

clean:
	- rm -f mikestat mikestat.exe genfw genfw.exe
