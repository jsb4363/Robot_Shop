main:	jsb4363_cli.cpp 
	g++ -std=c++11 -o jsb4363_cli jsb4363_cli.cpp
	./jsb4363_cli

test:	jsb4363_test_parts.cpp 
	g++ -std=c++11 -o jsb4363_test_parts jsb4363_test_parts.cpp
	./jsb4363_test_parts
clean:
	-rm -f *.o jsb4363_test_parts
