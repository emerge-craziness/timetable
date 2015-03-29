all:
	g++ tt.cpp -o tt

install:
	sudo ln -sfi `pwd`/tt /usr/bin/tt

deinstall:
	sudo rm /usr/bin/tt
