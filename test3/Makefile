all: test.cpp
	clang++ -c test.cpp -std=c++17
	clang++ -std=c++17 -Xclang -ast-dump -fsyntax-only test.cpp&>test.ast