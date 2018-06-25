#! /bin/bash

function gen
{
	mkdir -p proj_linux
	cd proj_linux
	cmake ..
	make
	cd ..
}

gen $@
