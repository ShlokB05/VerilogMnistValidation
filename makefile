SIM = obj_dir/VFunction2

all: build run

build:
	verilator -Wall --cc --exe --build Function2.sv cppMnist2_alwaysFF.cpp

run:
	./$(SIM)

clean:
	rm -rf obj_dir
