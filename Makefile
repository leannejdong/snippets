CXXFLAGS=-std=c++2a -fconcepts -Wall -Wextra -Wpedantic -Werror -fsanitize=address -D_GLIBCXX_DEBUG -IJSON  
Simple: code.o
	$(CXX) -o $@ $^
