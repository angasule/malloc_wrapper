No requirements other than the GNU toolchain.

Use make to build, then use like this:

LD_PRELOAD=./omalloc.so COMMAND

For example:

LD_PRELOAD=./omalloc.so ls

will list the current directory.
