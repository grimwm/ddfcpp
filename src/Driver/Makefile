TOPDIR?=	../..

-include ../../mk/common.mk
-include ../../mk/cpp.mk

all:		$(LIB_DIR)/libDriver.a \
		$(INC_DIR)/DeviceBaseMessage.hpp \
		$(INC_DIR)/DeviceCancelMessage.hpp \
		$(INC_DIR)/DeviceEntranceMessage.hpp \
		$(INC_DIR)/DeviceIOControlMessage.hpp \
		$(INC_DIR)/DeviceIOMessage.hpp \
		$(INC_DIR)/DeviceIOVectorMessage.hpp \
		$(INC_DIR)/DeviceInterruptMessage.hpp \
		$(INC_DIR)/DeviceMessageTypes.hpp \
		$(INC_DIR)/DeviceMessages.hpp \
		$(INC_DIR)/DeviceTimeoutMessage.hpp \
		$(INC_DIR)/Driver.hpp \
		$(INC_DIR)/DriverProxy.hpp \
		$(INC_DIR)/IDriver.hpp \
		$(INC_DIR)/minix/DeviceMessageTypes.hpp \
		$(INC_DIR)/minix/DeviceMessageTypesHeaders.hpp

.PHONY: tests
tests:
	$(CXX) $(CXXFLAGS) -o $(BIN_DIR)/DriverTests DriverTests.cpp -lDDM -lIPC

.PHONY: install
install: all
	$(INSTALL) -o bin $(LIB_DIR)/libDriver.a \
		$(LIB_PREFIX)/libDriver.a
	$(INSTALL) -o bin $(INC_DIR)/DeviceBaseMessage.hpp \
		$(INC_PREFIX)/DeviceBaseMessage.hpp
	$(INSTALL) -o bin $(INC_DIR)/DeviceCancelMessage.hpp \
		$(INC_PREFIX)/DeviceCancelMessage.hpp
	$(INSTALL) -o bin $(INC_DIR)/DeviceEntranceMessage.hpp \
		$(INC_PREFIX)/DeviceEntranceMessage.hpp
	$(INSTALL) -o bin $(INC_DIR)/DeviceIOControlMessage.hpp \
		$(INC_PREFIX)/DeviceIOControlMessage.hpp
	$(INSTALL) -o bin $(INC_DIR)/DeviceIOMessage.hpp \
		$(INC_PREFIX)/DeviceIOMessage.hpp
	$(INSTALL) -o bin $(INC_DIR)/DeviceIOVectorMessage.hpp \
		$(INC_PREFIX)/DeviceIOVectorMessage.hpp
	$(INSTALL) -o bin $(INC_DIR)/DeviceInterruptMessage.hpp \
		$(INC_PREFIX)/DeviceInterruptMessage.hpp
	$(INSTALL) -o bin $(INC_DIR)/DeviceMessageTypes.hpp \
		$(INC_PREFIX)/DeviceMessageTypes.hpp
	$(INSTALL) -o bin $(INC_DIR)/DeviceMessages.hpp \
		$(INC_PREFIX)/DeviceMessages.hpp
	$(INSTALL) -o bin $(INC_DIR)/DeviceTimeoutMessage.hpp \
		$(INC_PREFIX)/DeviceTimeoutMessage.hpp
	$(INSTALL) -o bin $(INC_DIR)/Driver.hpp \
		$(INC_PREFIX)/Driver.hpp
	$(INSTALL) -o bin $(INC_DIR)/DriverProxy.hpp \
		$(INC_PREFIX)/DriverProxy.hpp
	$(INSTALL) -o bin $(INC_DIR)/IDriver.hpp \
		$(INC_PREFIX)/IDriver.hpp
	$(INSTALL) -o bin $(INC_DIR)/minix/DeviceMessageTypes.hpp \
		$(INC_PREFIX)/minix/DeviceMessageTypes.hpp
	$(INSTALL) -o bin $(INC_DIR)/minix/DeviceMessageTypesHeaders.hpp \
		$(INC_PREFIX)/minix/DeviceMessageTypesHeaders.hpp

.PHONY: uninstall
uninstall:
	$(RM)	$(LIB_PREFIX)/libDriver.a \
		$(INC_PREFIX)/DeviceBaseMessage.hpp \
		$(INC_PREFIX)/DeviceCancelMessage.hpp \
		$(INC_PREFIX)/DeviceEntranceMessage.hpp \
		$(INC_PREFIX)/DeviceIOControlMessage.hpp \
		$(INC_PREFIX)/DeviceIOMessage.hpp \
		$(INC_PREFIX)/DeviceIOVectorMessage.hpp \
		$(INC_PREFIX)/DeviceInterruptMessage.hpp \
		$(INC_PREFIX)/DeviceMessageTypes.hpp \
		$(INC_PREFIX)/DeviceMessages.hpp \
		$(INC_PREFIX)/DeviceTimeoutMessage.hpp \
		$(INC_PREFIX)/Driver.hpp \
		$(INC_PREFIX)/DriverProxy.hpp \
		$(INC_PREFIX)/IDriver.hpp \
		$(INC_PREFIX)/minix/DeviceMessageTypes.hpp \
		$(INC_PREFIX)/minix/DeviceMessageTypesHeaders.hpp

.PHONY: clean
clean: clean_tests
	$(RM)	$(LIB_DIR)/libDriver.a \
		$(OBJ_DIR)/DeviceBaseMessage.o \
		$(OBJ_DIR)/DeviceCancelMessage.o \
		$(OBJ_DIR)/DeviceEntranceMessage.o \
		$(OBJ_DIR)/DeviceIOControlMessage.o \
		$(OBJ_DIR)/DeviceIOMessage.o \
		$(OBJ_DIR)/DeviceIOVectorMessage.o \
		$(OBJ_DIR)/DeviceInterruptMessage.o \
		$(OBJ_DIR)/DeviceTimeoutMessage.o \
		$(OBJ_DIR)/Driver.o \
		$(OBJ_DIR)/DriverProxy.o \
		$(INC_DIR)/DeviceBaseMessage.hpp \
		$(INC_DIR)/DeviceCancelMessage.hpp \
		$(INC_DIR)/DeviceEntranceMessage.hpp \
		$(INC_DIR)/DeviceIOControlMessage.hpp \
		$(INC_DIR)/DeviceIOMessage.hpp \
		$(INC_DIR)/DeviceIOVectorMessage.hpp \
		$(INC_DIR)/DeviceInterruptMessage.hpp \
		$(INC_DIR)/DeviceMessageTypes.hpp \
		$(INC_DIR)/DeviceMessages.hpp \
		$(INC_DIR)/DeviceTimeoutMessage.hpp \
		$(INC_DIR)/Driver.hpp \
		$(INC_DIR)/DriverProxy.hpp \
		$(INC_DIR)/IDriver.hpp \
		$(INC_DIR)/minix/DeviceMessageTypes.hpp \
		$(INC_DIR)/minix/DeviceMessageTypesHeaders.hpp

.PHONY: clean_tests
clean_tests:
	$(RM) $(BIN_DIR)/DriverTests

$(LIB_DIR)/libDriver.a: \
		$(OBJ_DIR)/DeviceBaseMessage.o \
		$(OBJ_DIR)/DeviceCancelMessage.o \
		$(OBJ_DIR)/DeviceEntranceMessage.o \
		$(OBJ_DIR)/DeviceIOControlMessage.o \
		$(OBJ_DIR)/DeviceIOMessage.o \
		$(OBJ_DIR)/DeviceIOVectorMessage.o \
		$(OBJ_DIR)/DeviceInterruptMessage.o \
		$(OBJ_DIR)/DeviceTimeoutMessage.o \
		$(OBJ_DIR)/Driver.o \
		$(OBJ_DIR)/DriverProxy.o
	$(AR) r $@ $(OBJ_DIR)/DeviceBaseMessage.o
	$(AR) r $@ $(OBJ_DIR)/DeviceCancelMessage.o
	$(AR) r $@ $(OBJ_DIR)/DeviceEntranceMessage.o
	$(AR) r $@ $(OBJ_DIR)/DeviceIOControlMessage.o
	$(AR) r $@ $(OBJ_DIR)/DeviceIOMessage.o
	$(AR) r $@ $(OBJ_DIR)/DeviceIOVectorMessage.o
	$(AR) r $@ $(OBJ_DIR)/DeviceInterruptMessage.o
	$(AR) r $@ $(OBJ_DIR)/DeviceTimeoutMessage.o
	$(AR) r $@ $(OBJ_DIR)/Driver.o
	$(AR) r $@ $(OBJ_DIR)/DriverProxy.o

$(OBJ_DIR)/DeviceBaseMessage.o: DeviceBaseMessage.cpp \
		$(INC_DIR)/DeviceBaseMessage.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJ_DIR)/DeviceCancelMessage.o: DeviceCancelMessage.cpp \
		$(INC_DIR)/DeviceCancelMessage.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJ_DIR)/DeviceEntranceMessage.o: DeviceEntranceMessage.cpp \
		$(INC_DIR)/DeviceEntranceMessage.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJ_DIR)/DeviceIOControlMessage.o: DeviceIOControlMessage.cpp \
		$(INC_DIR)/DeviceIOControlMessage.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJ_DIR)/DeviceIOMessage.o: DeviceIOMessage.cpp \
		$(INC_DIR)/DeviceIOMessage.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJ_DIR)/DeviceIOVectorMessage.o: DeviceIOVectorMessage.cpp \
		$(INC_DIR)/DeviceIOVectorMessage.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJ_DIR)/DeviceInterruptMessage.o: DeviceInterruptMessage.cpp \
		$(INC_DIR)/DeviceInterruptMessage.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJ_DIR)/DeviceTimeoutMessage.o: DeviceTimeoutMessage.cpp \
		$(INC_DIR)/DeviceTimeoutMessage.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJ_DIR)/Driver.o: Driver.cpp \
		$(INC_DIR)/Driver.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJ_DIR)/DriverProxy.o: DriverProxy.cpp \
		$(INC_DIR)/DriverProxy.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(INC_DIR)/DeviceBaseMessage.hpp: DeviceBaseMessage.hpp
	$(CP) $< $@

$(INC_DIR)/DeviceCancelMessage.hpp: DeviceCancelMessage.hpp
	$(CP) $< $@

$(INC_DIR)/DeviceEntranceMessage.hpp: DeviceEntranceMessage.hpp
	$(CP) $< $@

$(INC_DIR)/DeviceIOControlMessage.hpp: DeviceIOControlMessage.hpp
	$(CP) $< $@

$(INC_DIR)/DeviceIOMessage.hpp: DeviceIOMessage.hpp
	$(CP) $< $@

$(INC_DIR)/DeviceIOVectorMessage.hpp: DeviceIOVectorMessage.hpp
	$(CP) $< $@

$(INC_DIR)/DeviceInterruptMessage.hpp: DeviceInterruptMessage.hpp
	$(CP) $< $@

$(INC_DIR)/DeviceTimeoutMessage.hpp: DeviceTimeoutMessage.hpp
	$(CP) $< $@

$(INC_DIR)/DeviceMessageTypes.hpp: DeviceMessageTypes.hpp
	$(CP) $< $@

$(INC_DIR)/minix/DeviceMessageTypes.hpp: minix/DeviceMessageTypes.hpp
	$(CP) $< $@

$(INC_DIR)/minix/DeviceMessageTypesHeaders.hpp: \
		minix/DeviceMessageTypesHeaders.hpp
	$(CP) $< $@

$(INC_DIR)/DeviceMessages.hpp: \
		DeviceMessages.hpp \
		$(INC_DIR)/DeviceCancelMessage.hpp \
		$(INC_DIR)/DeviceEntranceMessage.hpp \
		$(INC_DIR)/DeviceIOControlMessage.hpp \
		$(INC_DIR)/DeviceIOMessage.hpp \
		$(INC_DIR)/DeviceIOVectorMessage.hpp \
		$(INC_DIR)/DeviceInterruptMessage.hpp \
		$(INC_DIR)/DeviceTimeoutMessage.hpp \
		$(INC_DIR)/DeviceMessageTypes.hpp
	$(CP) $< $@

$(INC_DIR)/Driver.hpp: Driver.hpp $(INC_DIR)/DeviceMessages.hpp
	$(CP) $< $@

$(INC_DIR)/DriverProxy.hpp: DriverProxy.hpp \
		$(INC_DIR)/IDriver.hpp \
		$(INC_DIR)/DeviceMessages.hpp
	$(CP) $< $@

$(INC_DIR)/IDriver.hpp: IDriver.hpp
	$(CP) $< $@
