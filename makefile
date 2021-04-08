all : hw1_naive hw1_kmp

hw1_naive : hw1_naive.cpp
	g++ -W -o $@ $<
hw1_kmp : hw1_kmp.cpp
	g++ -W -o $@ $<

clean :
	rm *.o hw1_naive hw1_kmp
