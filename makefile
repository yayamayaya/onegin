r:
	valgrind --leak-check=full --show-leak-kinds=all ./build/src/oneg ${out} ${text}
