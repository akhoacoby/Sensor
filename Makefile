TARGET = main

CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -I.

SRCS = main.cpp \
       time.cpp \
       unit.cpp \
       attribute.cpp \
       measurement.cpp \
       csvfile.cpp \
       GovernmentUser.cpp \
       PrivateUser.cpp \
       ProviderUser.cpp \
       User.cpp \
       Cleaner.cpp \
       Sensor.cpp \
       system.cpp \
       Admin.cpp


OBJS = $(SRCS:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)

fclean: clean

re: fclean all

.PHONY: all clean fclean re
