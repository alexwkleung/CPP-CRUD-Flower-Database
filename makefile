CXX = g++
CPPFLAGS = -std=c++17 -Wall -Wextra -g 
VAR = src/main.cpp src/welcome.cpp src/select.cpp src/options.cpp
OUT = src/a.o

.PHONY: build
build:
	${CXX} ${CPPFLAGS} ${VAR} -o ${OUT} && ./${OUT}

.PHONY: clean
clean:
	rm ./${OUT}