TOPDIR?=	../..

-include ../../mk/common.mk
-include ../../mk/cpp.mk

all:		$(SBIN_DIR)/KeyboardDriver

.PHONY: tests
tests:
	$(CXX) $(CXXFLAGS) -o $(BIN_DIR)/MockKeyboardDriver \
		$(OBJ_DIR)/KeyboardDriver.o MockKeyboardDriver.cpp \
		-lsys -lDDM -lDriver -lIPC
	$(CXX) $(CXXFLAGS) -o $(BIN_DIR)/KeyboardDriverTests \
		KeyboardDriverTests.cpp \
		-lsys -lDDM -lDriver -lIPC
	$(CXX) $(CXXFLAGS) -o $(BIN_DIR)/KeyboardDriverProxyTests \
		KeyboardDriverProxyTests.cpp \
		-lsys -lDDM -lDriver -lIPC

.PHONY: install
install: all
	$(INSTALL) -o bin $(SBIN_DIR)/KeyboardDriver \
		$(SBIN_PREFIX)/KeyboardDriver
	$(INSTALL) -o bin $(INC_DIR)/KeyboardDriver.hpp \
		$(INC_PREFIX)/KeyboardDriver.hpp

.PHONY: uninstall
uninstall:
	$(RM)	$(SBIN_PREFIX)/KeyboardDriver \
		$(INC_PREFIX)/KeyboardDriver.hpp

.PHONY: clean
clean: clean_tests
	$(RM)	$(SBIN_DIR)/KeyboardDriver \
		$(OBJ_DIR)/KeyboardDriver.o \
		$(OBJ_DIR)/Main.o \
		$(INC_DIR)/KeyboardDriver.hpp

.PHONY: clean_tests
clean_tests:
	$(RM)	$(BIN_DIR)/MockKeyboardDriver \
		$(BIN_DIR)/KeyboardDriverTests \
		$(BIN_DIR)/KeyboardDriverProxyTests

$(SBIN_DIR)/KeyboardDriver: $(OBJ_DIR)/KeyboardDriver.o $(OBJ_DIR)/Main.o
	$(CXX) $(CXXFLAGS) $^ -o $@ -lsys -lDDM -lDriver -lIPC

$(OBJ_DIR)/KeyboardDriver.o: KeyboardDriver.cpp \
		$(INC_DIR)/KeyboardDriver.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJ_DIR)/Main.o: Main.cpp \
		$(INC_DIR)/KeyboardDriver.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(INC_DIR)/KeyboardDriver.hpp: KeyboardDriver.hpp
	$(CP) $< $@
