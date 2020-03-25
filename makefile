done:
	git add .
	git commit -m"automaticlaly commit"
	git push

oj_test: ./advanced_pog/oj/E3/OJ_3_1.cpp ./advanced_pog/oj/E3/OJ_3_1.h
	g++ ./advanced_pog/oj/E3/OJ_3_1.cpp -g -o ./test
	./test

homework_test: ./advanced_pog/homework/L5/H1.cpp
	g++ ./advanced_pog/homework/L5/H1.cpp -std=c++14 -g -o ./test 
	./test