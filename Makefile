TARGET = main

CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -I.

SRCS = Main.cpp \
       Time.cpp \
       Unit.cpp \
       Attribute.cpp \
       Measurement.cpp \
       Csvfile.cpp \
       GovernmentUser.cpp \
       PrivateUser.cpp \
       ProviderUser.cpp \
       User.cpp \
       Cleaner.cpp \
       Sensor.cpp \
       System.cpp


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
