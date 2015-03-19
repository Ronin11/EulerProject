JAR=jar
JARFLAGS=cvfe
JC=javac
JFLAGS=

#Application Source
SOURCE_PATH=./src
JAVA_SOURCE_FILES += Main.java
CLASS_FILES=$(JAVA_SOURCE_FILES:.java=.class)
JAVA_MAIN=Main

#Path for external includes

#Name of final executable
TARGETNAME=Problem5
TARGET=$(TARGETNAME).jar

########## RULES ##########
.PHONY: all
.PHONY: clean

all: debug clean
	
debug: classes
	cd $(SOURCE_PATH); $(JAR) $(JARFLAGS) $(TARGET) $(JAVA_MAIN) $(CLASS_FILES); mv $(TARGET) ..

classes:
	cd $(SOURCE_PATH); $(JC) $(JAVA_SOURCE_FILES)

clean:
	cd $(SOURCE_PATH); $(RM) *.class


