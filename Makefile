.DEFAULT: all

all: blasius-solution blasius-velocity-profile

blasius-solution: blasius-solution.cc blasius-solution.h
	$(CXX) -o $@ blasius-solution.cc

blasius-velocity-profile: blasius-velocity-profile.cc blasius-solution.h
	$(CXX) -o $@ blasius-velocity-profile.cc

