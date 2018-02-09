CXX = g++

# Warnings frequently signal eventual errors:
CXXFLAGS= -g -W -Wall -std=c++11 -Weffc++ -Wextra -pedantic -O0 -I /include/

OBJS = \
  WorldGrid.o \
  Player.o \
  main.o

EXEC = dungeoncrawler

%.o: %.cpp %.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(EXEC): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS)

clean:
	rm -rf $(OBJS)
	rm -rf $(EXEC)
