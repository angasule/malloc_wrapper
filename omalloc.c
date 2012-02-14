#define _GNU_SOURCE

#include <dlfcn.h>
#include <stdlib.h>
#include <stdio.h>

#define MALLOC_PAD 50

static void* (*orig_malloc)(size_t size) = NULL;

void* malloc(size_t size)
{
	void *allocated = NULL;

	if(!orig_malloc){
		fprintf(stderr, "malloc_guard: wrapping malloc\n");
		fflush(stderr);
		*(void**) (&orig_malloc) = dlsym(RTLD_NEXT, "malloc");
	}

	allocated = orig_malloc(size+MALLOC_PAD);

	if(!allocated){
		fprintf(stderr, "malloc_guard: --MALLOC RETURNED NULL--\n");
		fflush(stderr);
	}
	fprintf(stderr, "malloc_guard: SUCCESS!\n");
	fflush(stderr);

	return allocated;
}
