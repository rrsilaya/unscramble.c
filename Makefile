dev:
	clear && gcc unscramble.c -o unscramble.exe && ./unscramble.exe

compile:
	gcc unscramble.c -o unscramble.exe

run:
	./unscramble.exe encfsuo _______

clean:
	rm *.exe
