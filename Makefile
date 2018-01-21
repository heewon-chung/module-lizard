CC = g++
AR = ar
RANLIB = ranlib

LIB_NAME = MLizard
LIB_FULL_NAME = lib$(LIB_NAME).a

LIB_SRCS = *.cpp
LIB_OBJS = *.o

FLAGS = -O2 -lm -std=c++11
LIB_DIRS = ~/Documents/03_Source_Code/C/module-lizard

OBJ_SRCS = Poly.cpp PolyVec.cpp sampling.cpp mlizard.cpp
TEST_SRCS = testPoly.cpp testMLizard.cpp

all : clean $(LIB_FULL_NAME) test_poly test_mlizard

$(LIB_FULL_NAME) :
	g++ -c $(OBJ_SRCS) -std=c++11
	$(AR) rcv $@ $(LIB_OBJS)
	$(RANLIB) $@

test_poly : testPoly.cpp $(LIB_FULL_NAME)
	$(CC) testPoly.cpp -o test_poly $(LIB_FULL_NAME) $(FLAGS)

test_mlizard : testMLizard.cpp $(LIB_FULl_NAME)
	$(CC) testMLizard.cpp -o test_mlizard $(LIB_FULL_NAME) $(FLAGS)

test : 
	./test_poly
	./test_mlizard

clean :
	rm -f $(LIB_FULL_NAME) $(LIB_OBJS) test_*