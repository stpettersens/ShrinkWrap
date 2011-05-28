#
# Makefile to create HelloWorld application executable.
#

JAVA_SRC=HelloWorld.java
JAVA_JAR=HelloWorld.jar
JAVA_MANIFEST=Manifest.mf
CPP_SRC=sw_template.cpp
CPP_INCLUDE=sw_xplatform.h
CPP_TARGET=hw

make:
	@echo Building HelloWorld...
	cp ../../$(CPP_SRC) .
	cp ../../$(CPP_INCLUDE) .
	javac -cp . $(JAVA_SRC) 
	echo 'Main-Class: HelloWorld\n' >> $(JAVA_MANIFEST)
	jar cvfm $(JAVA_JAR) Manifest.mf HelloWorld.class
	g++ $(CPP_SRC) -o $(CPP_TARGET)
	strip $(CPP_TARGET)
	rm -f $(CPP_SRC)
	rm -f $(CPP_INCLUDE)
	rm -f $(JAVA_MANIFEST)
	rm -f HelloWorld.class
	@echo Done.
