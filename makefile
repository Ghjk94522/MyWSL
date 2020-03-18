done:
	git add .
	git commit -m"automaticlaly commit"
	git push

test: ./advanced_pog/homework/L4/H2.cpp
	g++ ./advanced_pog/homework/L4/H2.cpp -g -o test
	./test
