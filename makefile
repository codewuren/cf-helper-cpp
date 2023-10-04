#This is a makefile by CodeWuRen

build:
	g++ src/*.cc --std=c++2a -O2 -o cf-helper

install:
	g++ src/*.cc --std=c++2a -O2 -o cf-helper
	install cf-helper "/usr/bin/"

uninstall:
	rm /usr/bin/cf-helper
