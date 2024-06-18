r:
	./build/src/onegin ${out} ${in}
	
rval:
	valgrind --leak-check=full --show-leak-kinds=all ./build/src/onegin ${out} ${in}
