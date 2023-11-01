#
#      Makefile
#      MetroSim
#      Comp 15 Proj 1
#      Federico Sorcini
#

# Metrosim rule
MetroSim: main.o MetroSim.o PassengerQueue.o Passenger.o
	$(CXX) $(LDFLAGS) $^ -o $@

# Rules for .o files
main.o: main.cpp MetroSim.h PassengerQueue.h Passenger.h
	$(CXX) $(CXXFLAGS) -c main.cpp

MetroSim.o: MetroSim.cpp MetroSim.h PassengerQueue.h Passenger.h
	$(CXX) $(CXXFLAGS) -c MetroSim.cpp

PassengerQueue.o: PassengerQueue.cpp PassengerQueue.h Passenger.h 
	$(CXX) $(CXXFLAGS) -c PassengerQueue.cpp

Passenger.o: Passenger.cpp Passenger.h
	$(CXX) $(CXXFLAGS) -c Passenger.cpp

# Rule for unit tests
unit_tests: unit_tests.o MetroSim.o PassengerQueue.o Passenger.o
	$(CXX) $(LDFLAGS) $^ -o $@

unit_tests.o: unit_tests.cpp MetroSim.h PassengerQueue.h Passenger.h
	$(CXX) $(CXXFLAGS) -c unit_tests.cpp

# Rule to remove executables, object code, and temporary files from the current folder
clean: 
	rm -f *.o *~ MetroSim unit_tests