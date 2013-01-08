TOPDIR?=	../..

-include ../../mk/common.mk
-include ../../mk/cpp.mk

all:		$(INC_DIR)/Memory.hpp \
		$(INC_DIR)/MemoryHeaders.hpp \
		$(INC_DIR)/minix/Memory.hpp

.PHONY: tests
tests:
	$(CXX) $(CXXFLAGS) -o $(BIN_DIR)/MemoryTests MemoryTests.cpp -lsys

.PHONY: install
install: all
	$(INSTALL) -o bin $(INC_DIR)/Memory.hpp \
		$(INC_PREFIX)/Memory.hpp
	$(INSTALL) -o bin $(INC_DIR)/MemoryHeaders.hpp \
		$(INC_PREFIX)/MemoryHeaders.hpp
	$(INSTALL) -o bin $(INC_DIR)/minix/Memory.hpp \
		$(INC_PREFIX)/minix/Memory.hpp

.PHONY: uninstall
uninstall:
	$(RM)	$(INC_PREFIX)/Memory.hpp \
		$(INC_PREFIX)/MemoryHeaders.hpp \
		$(INC_PREFIX)/minix/Memory.hpp

.PHONY: clean
clean: clean_tests
	$(RM)	$(INC_DIR)/Memory.hpp \
		$(INC_DIR)/MemoryHeaders.hpp \
		$(INC_DIR)/minix/Memory.hpp

.PHONY: clean_tests
clean_tests:
	$(RM) $(BIN_DIR)/MemoryTests

$(INC_DIR)/Memory.hpp: Memory.hpp
	$(CP) $< $@

$(INC_DIR)/MemoryHeaders.hpp: MemoryHeaders.hpp
	$(CP) $< $@

$(INC_DIR)/minix/Memory.hpp: minix/Memory.hpp
	$(CP) $< $@
