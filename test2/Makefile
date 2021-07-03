all: test.cpp
	clang++ -c test.cpp -std=c++17
	clang++ -Xclang -ast-dump -fsyntax-only test.cpp &> test.ast