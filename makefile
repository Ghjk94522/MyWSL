done:
	git pull
	git add .
	git commit -m"automaticlaly commit"
	git push

oj_ad_test: ./advanced_pog/oj/E3/OJ_3_1.cpp ./advanced_pog/oj/E3/OJ_3_1.h
	g++ ./advanced_pog/oj/E3/OJ_3_1.cpp -g -o ./test
	./test 

homework_test: ./advanced_pog/homework/Lc/H2.cpp ./g++result.txt
	g++ ./advanced_pog/homework/Lc/H2.cpp -g -o ./test 2> g++result.txt
	./test 

oj_al_test: ./algorithm/L4_2.cpp ./data.in
	g++ ./algorithm/L5_1.cpp -g -o ./test 2> g++result.txt
	./test < data.in > data.out

oj_al_py: ./algorithm/L2_2.py ./data.in
	python3 ./algorithm/L2_2.py < data.in

google_test: ./Code_Jam/Parent.cpp ./data.in 
	g++ ./Code_Jam/Parent.cpp -g -o ./test 
	./test < ./data.in

kick_start: ./Kick_Start/Allocation.cpp ./data.in
	g++ ./Kick_Start/Allocation.cpp -std=c++14 -g -o ./test
	./test < ./data.in 

luogu_test: ./Oj_luogu/P1803.cpp
	g++ ./Oj_luogu/P1803.cpp -g -o ./test 2> g++result.txt
	./test < data.in > data.out