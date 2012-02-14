omalloc: omalloc.c
	gcc -fPIC -shared $@.c -o $@.so
