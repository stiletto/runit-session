hangit: hangit.c
	gcc -Os -static -o $@ $^
	strip $@
