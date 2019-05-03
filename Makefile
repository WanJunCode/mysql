PHONY: all

all:
	g++ -std=c++11 -lmosquittopp -o main *.cpp \
	-lmysqlpp -lmysqlclient

clean:
	rm -rf main core
