main:
	g++ -g *.cpp -std=c++98 -pedantic -o main

clean:
	rm -f *.o *.tar.gz *.info *.gcda *.gcno *.gcov main
	reset
	clear

run:
	valgrind --leak-check=full ./main

tar:
	tar -cvz *.* -f Code.tar.gz

untar:
	tar -zxvf *.tar.gz

test:
	g++ --coverage *.cpp -o main
	gcov -f -m -r -j term polynomial univariate bivariate linear quadratic circle ellipse
	./main
	lcov -c -d . -o coverage.info
	genhtml coverage.info -o coverage_report