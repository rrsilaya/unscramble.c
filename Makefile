dev:
	clear && gcc unscramble.c -o unscramble.exe && ./unscramble.exe

compile:
	gcc unscramble.c -o unscramble.exe

run:
	./unscramble.exe 1 1

clean:
	rm *.exe
