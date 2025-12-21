CXX ?= g++
CXXFLAGS = -std=gnu++14 -I../ -I../third_party/googletest/include -I../third_party/googletest/include/gtest -I../third_party/googletest/googletest/include -I../third_party/googletest/googletest
LDFLAGS = -pthread

# BASE    = arm-none-linux-gnueabihf
# CXX      = $(BASE)-gcc

GTEST_SRCS = \
	../third_party/googletest/googletest/src/gtest-all.cc \
	../third_party/googletest/googletest/src/gtest_main.cc

TEST_SRCS = \
	test_str_util.cpp \
	../str_util.cpp \
	test_bootcore_utils.cpp \
	../bootcore_utils.cpp

OBJS = $(GTEST_SRCS:.cc=.o) $(TEST_SRCS:.cpp=.o)

run_tests: $(OBJS)
	$(CXX) -o $@ $(OBJS) $(LDFLAGS)

%.o: %.cc
	$(CXX) $(CXXFLAGS) -c $< -o $@

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) run_tests
