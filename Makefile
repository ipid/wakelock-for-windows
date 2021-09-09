CC = gcc
CPPC = g++
STRIP = strip
CPPFLAGS = -O3 -static -Wall -Wextra -Werror -Wpedantic -std=c++17

.PHONY: all clean

all: wakelock.exe

clean:
	rm -f *.exe

wakelock.exe: wakelock.cpp
	$(CPPC) $(CPPFLAGS) -o wakelock.exe wakelock.cpp
	$(STRIP) -s wakelock.exe
