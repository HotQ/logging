cmake . 
make
g++ test.cpp -o test.out  -std=c++11  -L./shared/ -llogging -I./include
./test.out