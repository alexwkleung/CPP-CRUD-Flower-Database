CXX = g++
CPPFLAGS = -std=c++17 -Wall -Wextra -g 
VAR = src/main.cpp src/welcome.cpp src/select.cpp src/options.cpp
OUT = src/a.o
TEMP = src/db-temp.txt

.PHONY: build
build:
	${CXX} ${CPPFLAGS} ${VAR} -o ${OUT} && ./${OUT}

.PHONY: clean
clean:
	rm ${OUT} || rm ${OUT} && rm ${TEMP} || rm ${TEMP}