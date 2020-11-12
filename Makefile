CXXFLAGS=-std=c++2a -Wall -Wextra -Wpedantic -Werror -fsanitize=address -D_GLIBCXX_DEBUG
Simple: code.o
	$(CXX) -o $@ $^
