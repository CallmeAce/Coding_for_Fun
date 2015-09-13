EXEC = leetcode
OBJS = leetcode.cpp
CXX  = g++
CXXFLAGS = -Wall -g
LIBS = -lopencv_core -lopencv_imgproc -lopencv_highgui -lpthread
LDFLAGS = -I/opt/local/include/opencv -I/opt/local/include
LDLIBS  = -L/opt/local/lib

$(EXEC): $(OBJS)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $(LDLIBS) $(OBJS) -o $@ $(LIBS)

#detecting2.o : detecting2.cpp
#	$(CXX) $(CXXFLAGS) $(LDFLAGS) -c detecting2.cpp $(LIBS)

.PHONY: clean

clean:
	rm -f $(EXEC) *~ 

