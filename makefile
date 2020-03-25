done:
	git add .
	git commit -m"automaticlaly commit"
	git push

oj_test: ./advanced_pog/oj/E3/OJ_3_1.cpp ./advanced_pog/oj/E3/OJ_3_1.h
	g++ ./advanced_pog/oj/E3/OJ_3_1.cpp -g -o test
	./test

homework_test: ./advanced_pog/homewoek/L5/H3.cpp
	g++ ./advanced_pog/L5/H3.cpp -g -o test
	./test