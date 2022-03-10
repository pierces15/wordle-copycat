#for use with c++ files
.SUFFIXES : .cpp

SOURCES = main.cpp display.cpp gameLogic.cpp

#Compile with g++
CC = g++

#use -g for gnu debugger and -std for c++11(eleven) compiling
CXXFLAGS = -g -std=c++11

OBJS:= ${SOURCES:.cpp=.o}

######Change from target to name of output file
TARGET = play

### tabs matter ###
$(TARGET): $(OBJS)
	$(CC) -o $@ $(OBJS)

.cpp.o:
	$(CC) -c $(CXXFLAGS) $(INCDIR) $<

# in order to get rid of all .o files, at command prompt, make clean
clean:
	rm -f $(OBJS) $(TARGET) core
