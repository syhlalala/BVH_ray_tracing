#makefile

CC	=	g++
FLAGS	=	-g -pg
CV_FLAGS = `pkg-config --libs opencv --cflags opencv`
SOURCES	=	$(filter-out main.cpp, $(wildcard *.cpp))
OBJS	=	$(patsubst %.cpp, ../bin/%.o, $(SOURCES))
TARGET	=	../bin/prt

all	:	$(OBJS) $(TARGET)

$(TARGET)	:	main.cpp $(OBJS)
	$(CC) $(FLAGS) -o $(TARGET) $< $(OBJS)

../bin/%.o	:	%.cpp %.h
	$(CC) -c $(FLAGS) -o $@ $<

show	:
	echo $(OBJS)

.PHONY	:	clean run benchmark

clean	:
	rm -f ../bin/*.o
	rm -f $(TARGET)
	rm -f $(TARGET).exe

run		:
	$(TARGET)
benchmark :
	gprof $(TARGET) > benchmark
