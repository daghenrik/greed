greed: greed.o room.o output.o capsule.o
	c++ -o greed greed.o room.o output.o capsule.o -std=c++14 -Wall -Werror -Wextra -lncurses
greed.o: greed.cpp
	c++ -c greed.cpp -std=c++14 -Wall -Werror -Wextra
room.o: room.cpp
	c++ -c room.cpp -std=c++14 -Wall -Werror -Wextra
output.o: output.cpp
	c++ -c output.cpp -std=c++14 -Wall -Werror -Wextra
capsule.o: capsule.cpp
	c++ -c capsule.cpp -std=c++14 -Wall -Werror -Wextra
clean:
	rm -- *.o
	rm greed
