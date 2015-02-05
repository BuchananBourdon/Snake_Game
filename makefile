RM = rm -f

CPPFLAGS = -g -Wall -Werror -Wno-parentheses

CPP_FILES = main.cpp Snake.cpp Game.cpp Section.cpp Food.cpp MapView.cpp Animation.cpp Smoke.cpp FloatingText.cpp Electricity.cpp

DEPENDS = $(CPP_FILES:.cpp=.d)
OBJECTS = $(CPP_FILES:.cpp=.o)

LIBS = -lSDL -lSDL_net -lSDL_gfx -lSDL_image

all: main

main: $(OBJECTS)
	g++ $(CPPFLAGS) -o $@ $^ $(LIBS)

%.d: %.cpp
	g++ -MM -MF $@ $<

%.o: %.cpp
	g++ -c $(CPPFLAGS) -o $@ $<

-include $(DEPENDS)

.PHONY:	clean

clean:
	$(RM) main
	$(RM) $(DEPENDS)
	$(RM) $(OBJECTS)
