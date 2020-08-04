build:
	g++ -std=c++14 main.cpp

run:
	./a.out > tmp.ppm
	convert tmp.ppm render.png
	
clean:
	rm a.out tmp.ppm