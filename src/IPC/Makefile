TOPDIR?=	../..

-include ../../mk/common.mk
-include ../../mk/cpp.mk

all: \
		$(LIB_DIR)/libIPC.a \
		$(INC_DIR)/IPC.hpp \
		$(INC_DIR)/IIPCMessage.hpp \
		$(INC_DIR)/IPCMessage.hpp \
		$(INC_DIR)/IPCMinix.hpp \
		$(INC_DIR)/IPCTypes.hpp

$(LIB_DIR)/libIPC.a: $(OBJ_DIR)/IPCMessage.o
	$(AR) r $@ $(OBJ_DIR)/IPCMessage.o

$(OBJ_DIR)/IPCMessage.o: IPCMessage.cpp IPCMessageMinix.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(INC_DIR)/IPC.hpp: IPC.hpp
	$(CP) $< $@

$(INC_DIR)/IIPCMessage.hpp: IIPCMessage.hpp
	$(CP) $< $@

$(INC_DIR)/IPCMessage.hpp: IPCMessage.hpp IIPCMessage.hpp
	$(CP) $< $@

$(INC_DIR)/IPCMinix.hpp: IPCMinix.hpp
	$(CP) $< $@

$(INC_DIR)/IPCTypes.hpp: IPCTypes.hpp
	$(CP) $< $@

.PHONY: install
install: all
	$(INSTALL) -o bin IPC.hpp \
		$(INC_PREFIX)/IPC.hpp
	$(INSTALL) -o bin IIPCMessage.hpp \
		$(INC_PREFIX)/IIPCMessage.hpp
	$(INSTALL) -o bin IPCMessage.hpp \
		$(INC_PREFIX)/IPCMessage.hpp
	$(INSTALL) -o bin IPCMinix.hpp \
		$(INC_PREFIX)/IPCMinix.hpp
	$(INSTALL) -o bin IPCTypes.hpp \
		$(INC_PREFIX)/IPCTypes.hpp
	$(INSTALL) -o bin $(LIB_DIR)/libIPC.a \
		$(LIB_PREFIX)/libIPC.a

.PHONY: uninstall
uninstall: clean
	$(RM)	$(LIB_PREFIX)/libIPC.a \
		$(INC_PREFIX)/IPC.hpp \
		$(INC_PREFIX)/IIPCMessage.hpp \
		$(INC_PREFIX)/IPCMessage.hpp \
		$(INC_PREFIX)/IPCMinix.hpp \
		$(INC_PREFIX)/IPCTypes.hpp

.PHONY: clean
clean:
	$(RM)	$(LIB_DIR)/libIPC.a \
		$(OBJ_DIR)/IPCMessage.o \
		$(INC_DIR)/IPC.hpp \
		$(INC_DIR)/IIPCMessage.hpp \
		$(INC_DIR)/IPCMessage.hpp \
		$(INC_DIR)/IPCMinix.hpp \
		$(INC_DIR)/IPCTypes.hpp \
