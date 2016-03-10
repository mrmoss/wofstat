CXX=g++
OPTS=-O
CFLAGS=$(OPTS) -Wall
SRC=src
LIB=

NATSTAT_SRC=$(SRC)/natstat.cpp $(SRC)/natstat_util.cpp $(SRC)/string_util.cpp

ifeq ($(OS),Windows_NT)
	NATSTAT_SRC+=$(SRC)/natstat_windows.cpp
	LIB+=-lIPHlpApi -lWs2_32
else
	os=$(shell uname -s)
	ifeq ($(os),Linux)
		NATSTAT_SRC+=$(SRC)/natstat_linux.cpp
	endif
	ifeq ($(os),Darwin)
		NATSTAT_SRC+=$(SRC)/natstat_osx.cpp
	endif
	ifeq ($(os),SunOS)
		NATSTAT_SRC+=$(SRC)/natstat_solaris.cpp

		ifeq ($(shell if [ $(shell uname -r|cut	-d'.' -f2) -ge 11 ];then echo 'new';else echo 'old';fi),new)
			CFLAGS+=-D NEWSOLARIS
		endif
	endif
	ifeq ($(os),$(filter $(os),FreeBSD GNU/kFreeBSD NetBSD OpenBSD))
		NATSTAT_SRC+=$(SRC)/natstat_bsd.cpp
	endif
endif

all: natstat

natstat: $(NATSTAT_SRC)
	$(CXX) $(CFLAGS) $(NATSTAT_SRC) $(LIB) -o natstat

clean:
	- rm -f natstat natstat.exe
