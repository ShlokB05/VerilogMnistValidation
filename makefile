SIM = obj_dir/VFunction

all: build run

build:
	verilator -Wall --cc --exe --build Function.sv CppMnist.cpp

run:
	./$(SIM)

clean:
	rm -rf obj_dir
