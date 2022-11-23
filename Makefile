CFLAGS = –std=c++11
CC = g++

main: main.o profile.o network.o social3.o
	$(CC) -o main main.o profile.o network.o social3.o

tests: tests.o profile.o network.o social3.o
	$(CC) -o tests tests.o profile.o network.o social3.o

main.o: main.cpp profile.hpp network.hpp

profile.o: profile.cpp profile.hpp 

network.o: network.cpp profile.hpp network.hpp

social3.o: social3.cpp network.hpp profile.hpp

clean:
	rm -f *o
	