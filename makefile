all: test 
clean: 
	rm test
run: test
	'./test'

%: %.cpp
	g++ -std=c++11 test.cpp -o test