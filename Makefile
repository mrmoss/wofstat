CXX=g++
OPTS=-O
CFLAGS=$(OPTS) -Wall
SRC=src
LIB=

WOFSTAT_SRC=$(SRC)/main.cpp $(SRC)/wofstat.cpp $(SRC)/string_util.cpp

ifeq ($(OS),Windows_NT)
	WOFSTAT_SRC+=$(SRC)/windows.cpp
	LIB+=-lIPHlpApi -lWs2_32
else
	os=$(shell uname -s)
	ifeq ($(os),Linux)
		WOFSTAT_SRC+=$(SRC)/linux.cpp
	endif
	ifeq ($(os),Darwin)
		WOFSTAT_SRC+=$(SRC)/osx.cpp
	endif
	ifeq ($(os),SunOS)
		WOFSTAT_SRC+=$(SRC)/solaris.cpp

		ifeq ($(shell if [ $(shell uname -r|cut	-d'.' -f2) -ge 11 ];then echo 'new';else echo 'old';fi),new)
			CFLAGS+=-D NEWSOLARIS
		endif
	endif
	ifeq ($(os),$(filter $(os),FreeBSD GNU/kFreeBSD NetBSD OpenBSD))
		WOFSTAT_SRC+=$(SRC)/bsd.cpp
	endif
endif

all: wofstat

wofstat: $(WOFSTAT_SRC)
	$(CXX) $(CFLAGS) $(WOFSTAT_SRC) $(LIB) -o wofstat

clean:
	- rm -f wofstat wofstat.exe
