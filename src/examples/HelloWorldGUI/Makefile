#
# Makefile to create HelloWorld GUI
# Swing toolkit application executable.
#

SRC=sw_template.cpp
INCLUDE=sw_xplatform.h
TARGET=hwgui

make:
	@echo Building HelloWorld GUI...
	@cp ../../$(SRC) .
	@cp ../../$(INCLUDE) .
	g++ $(SRC) -o $(TARGET)
	@rm -f $(SRC)
	@rm -f $(INCLUDE)
	@echo Done.
