dev:
	clear && gcc unscramble.c -o unscramble.exe && ./unscramble.exe

compile:
	gcc unscramble.c -o unscramble.exe

build:
	gcc unscramble.c -o unscramble.exe
	mkdir -p ../server/bin
	mv unscramble.exe ../server/bin/
	cp -r dictionary/ ../server

run:
	./unscramble.exe pneumonoultramicroscopicsilicovolcanoconiosis _____________________________________________

clean:
	rm *.exe
