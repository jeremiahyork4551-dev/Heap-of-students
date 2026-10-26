CXX = g++
CXXFLAGS = -Wall -g -std=c++17
TARGET = studentDB
OBJS = main.o address.o date.o student.o

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(TARGET)

main.o: main.cpp address.h date.h student.h
	$(CXX) $(CXXFLAGS) -c main.cpp

address.o: address.cpp address.h
	$(CXX) $(CXXFLAGS) -c address.cpp

date.o: date.cpp date.h
	$(CXX) $(CXXFLAGS) -c date.cpp

student.o: student.cpp student.h address.h date.h
	$(CXX) $(CXXFLAGS) -c student.cpp

run: $(TARGET)
	./$(TARGET)

debug: $(TARGET)
	gdb ./$(TARGET)

valgrind: $(TARGET)
	valgrind --leak-check=full ./$(TARGET)

clean:
	rm -f *.o $(TARGET)

.PHONY: run debug valgrind clean
