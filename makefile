CXX = g++
CXXFLAGS = -Wall -g
main: Exercise.o Workout.o Manager.o main.cpp
	$(CXX) $(CXXFLAGS) Exercise.o Workout.o Manager.o main.cpp -o main

Manager.o: Exercise.o Workout.o Manager.cpp Manager.h
	$(CXX) $(CXXFLAGS) -c Manager.cpp

Workout.o: Exercise.o Workout.cpp Workout.h
	$(CXX) $(CXXFLAGS) -c Workout.cpp

Exercise.o: Exercise.cpp Exercise.h
	$(CXX) $(CXXFLAGS) -c Exercise.cpp

clean:
	rm *.o*
	rm *~ 

run:
	./main

run1:
	./main inputs_workout1.txt

run2:
	./main inputs_workout2.txt

run3:
	./main inputs_workout3.txt

val1:
	valgrind ./main inputs_workout1.txt

val2:
	valgrind ./main inputs_workout2.txt

val3:
	valgrind ./main inputs_workout3.txt