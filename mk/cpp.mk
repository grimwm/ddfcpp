CXX		= g++

CXXFLAGS	= $(FLAGS) -std=c++98 -Woverloaded-virtual -fno-exceptions

LDFLAGS		+= -lstdc++

%.o: %.cc
	$(CXX) $(CXXFLAGS) -c $<

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $<
