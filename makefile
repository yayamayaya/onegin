r:
<<<<<<< HEAD
	./build/src/onegin ${out} ${in}
	
rval:
	valgrind --leak-check=full --show-leak-kinds=all ./build/src/onegin ${out} ${in}
=======
	valgrind --leak-check=full --show-leak-kinds=all ./build/src/oneg ${out} ${in}
>>>>>>> ec97871f0db983db28e5b3dc8d848fbddc0baf54
