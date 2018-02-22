Minesweeper: init.o recursion.o output.o
	compile init.o recursion.o output.o -o Minesweeper

init.o: init.c mineesweeper.h 
	compile -c init.c

recursion.o: recursion.c mineesweeper.h
	compile -c recursion.c

output.o: output.c mineesweeper.h
	compile -c output.c

clean:
	rm *.o Minesweeper 
