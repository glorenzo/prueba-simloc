# Este es el Makefile del proyecto.
# No necesitas modificar nada aquí para realizar la prueba.

SOURCES = $(wildcard *.cpp)
BUILDDIR=build
CPPFLAGS?=-std=c++11
OBJS = $(addprefix $(BUILDDIR)/,$(addsuffix .o,$(basename $(SOURCES))))

all: prueba

prueba: $(OBJS) lib/Simulator.o
	$(CXX) $(CPPFLAGS) $^ -lncurses -o $@
	
$(BUILDDIR)/%.o: %.cpp
	test -d $(BUILDDIR) || mkdir $(BUILDDIR)
	$(CXX) $(CPPFLAGS) -c $< -o $@

clean:
	rm $(BUILDDIR)/*.o prueba
