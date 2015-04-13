#!/bin/sh

if [[ ! -e bin ]]; then
	mkdir bin
fi

export DYLD_LIBRARY_PATH=SFML-2.2/lib


make && ./bin/Client $*
