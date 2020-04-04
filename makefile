done:
	git pull
	git add .
	git commit -m"automaticlaly commit"
	git push

oj_ad_test: ./advanced_pog/oj/E3/OJ_3_1.cpp ./advanced_pog/oj/E3/OJ_3_1.h
	g++ ./advanced_pog/oj/E3/OJ_3_1.cpp -g -o ./test
	./test

homework_test: ./advanced_pog/homework/L6/H2.cpp
	g++ ./advanced_pog/homework/L6/H2.cpp -std=c++14 -g -o ./test 
	./test

oj_al_test: ./algorithm/L2_2.cpp ./data.in
	g++ ./algorithm/L2_2.cpp -g -o ./test
	./test

oj_al_py: ./algorithm/L2_2.py ./data.in
	python3 ./algorithm/L2_2.py < data.in