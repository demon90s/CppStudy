#! /bin/bash

function gen
{
	mkdir -p proj
	cd proj
	cmake ..
	make
	cd ..
}

gen $@
