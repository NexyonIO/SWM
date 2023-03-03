name = sde
exec = $(name)
flags = -O3 -g -Wall -lm -ldl -fPIC -rdynamic

CPP = g++

source_files := $(shell find src/ -name *.cpp)
objects_files := $(patsubst src/%.cpp, build/%.o, $(source_files))

$(objects_files): build/%.o : src/%.cpp
	mkdir -p $(dir $@) && \
	$(CPP) -I src -c $(patsubst build/%.o, src/%.cpp, $@) -o $@ $(flags)

clean:
	-rm -rf build $(exec) && \
	mkdir build

all: clean build

build: $(objects_files)
	$(CPP) -fPIC -o $(exec) $(objects_files)
