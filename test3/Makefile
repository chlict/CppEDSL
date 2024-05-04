all: test.cpp
	clang++ -c test.cpp -std=c++17
	clang++ -std=c++17 -Xclang -ast-dump -fsyntax-only test.cpp&>test.ast
pg:
	~/software/llvm-project/build/bin/clang++ -I/usr/local/opt/llvm/bin/../include/c++/v1 -fsyntax-only -std=c++17 test.cpp -fplugin=/Users/chenlong/software/llvm-project/build/lib/PrintFunctionNames.dylib -Xclang -plugin -Xclang print-fns&>log
#	~/software/llvm-project/build/bin/clang++ -cc1 -I/usr/local/Cellar/llvm/11.0.0/lib/clang/11.0.0/include -I/usr/local/opt/llvm/bin/../include/c++/v1 -fsyntax-only -std=c++17 test.cpp -load /Users/chenlong/software/llvm-project/build/lib/PrintFunctionNames.dylib -plugin print-fns
