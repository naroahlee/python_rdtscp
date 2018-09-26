# Makefile for python rdtscp() module

.PHONY: all clean

ALL = rdtscp_module.so

all: ${ALL}

clean:
	rm -rf ${ALL} ./build

rdtscp_module.so: rdtscp_module.c setup.py
	python setup.py build_ext --inplace
