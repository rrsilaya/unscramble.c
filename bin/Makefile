dev:
	clear && gcc unscramble.c -o unscramble.exe && ./unscramble.exe

compile:
	gcc unscramble.c -o unscramble.exe

build:
	gcc unscramble.c -o unscramble.exe
	mkdir -p ../server/bin
	mv unscramble.exe ../server/bin/
	cp -r dictionary/ ../server/bin/

run:
	./unscramble.exe encfsuo c_____e

clean:
	rm *.exe
