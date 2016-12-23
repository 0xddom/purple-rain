CXX=g++
CFLAGS=-Wall -g -I./include
LDFLAGS=-lSDL2

OBJS=obj/main.cpp.o obj/Game.cpp.o obj/Drop.cpp.o obj/utils.cpp.o
OBJS+=obj/Timer.cpp.o obj/Vector.cpp.o obj/DropNode.cpp.o
OBJS+=obj/RainScene.cpp.o

bin/rain: $(OBJS)
	$(CXX) $(CFLAGS) $(LDFLAGS) $^ -o $@

obj/%.cpp.o: src/%.cpp
	$(CXX) $(CFLAGS) -c $< -o $@

.PHONY: clean
clean:
	rm -rf obj/*
	rm -rf bin/*
