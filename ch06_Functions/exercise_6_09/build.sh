#! /bin/bash

build()
{
	g++ -c factMain.cc fact.cc
	g++ factMain.o fact.o -o main
}

clean()
{
	rm -f *.o main
}

if [ "$1" = "clean" ]; then
	clean
else
	build
fi

exit 0
