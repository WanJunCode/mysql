PHONY: all

all:
	g++ -std=c++11 *.cpp -o main -lmysqlpp -lmysqlclient -g

clean:
	rm -rf main core
