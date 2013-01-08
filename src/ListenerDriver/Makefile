TOPDIR?=	../..

-include ../../mk/common.mk
-include ../../mk/cpp.mk

all:		$(SBIN_DIR)/ListenerDriver

.PHONY: install
install: all
	$(INSTALL) -o bin $(SBIN_DIR)/ListenerDriver \
		$(SBIN_PREFIX)/ListenerDriver

.PHONY: uninstall
uninstall:
	$(RM)	$(SBIN_PREFIX)/ListenerDriver

.PHONY: clean
clean:
	$(RM)	$(SBIN_DIR)/ListenerDriver \
		$(OBJ_DIR)/ListenerMain.o

$(SBIN_DIR)/ListenerDriver: $(OBJ_DIR)/ListenerMain.o
	$(CXX) $(CXXFLAGS) $^ -o $@ -lDDM -lDriver -lIPC -lsys

$(OBJ_DIR)/ListenerMain.o: ListenerMain.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@
