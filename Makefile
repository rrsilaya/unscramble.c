dev:
	clear && gcc unscramble.c -o unscramble.exe && ./unscramble.exe

compile:
	gcc unscramble.c -o unscramble.exe

run:
	./unscramble.exe abc ___

clean:
	rm *.exe
