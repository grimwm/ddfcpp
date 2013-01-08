TOPDIR?=	../..

-include ../../mk/common.mk
-include ../../mk/cpp.mk

all: \
		$(SBIN_DIR)/DDM \
		$(INC_DIR)/DDM.hpp \
		$(INC_DIR)/DDMMessage.hpp \
		$(INC_DIR)/DDMMinix.hpp \
		$(INC_DIR)/DeviceDriverManagerProxy.hpp \
		$(INC_DIR)/DriverInfo.hpp \
		$(INC_DIR)/DriverInfoTypes.hpp \
		$(INC_DIR)/IDeviceDriverManager.hpp \
		$(INC_DIR)/IDriverInfo.hpp \
		$(LIB_DIR)/libDDM.a

.PHONY: tests
tests: $(LIB_DIR)/libDDM.a
	$(CXX) $(CXXFLAGS) -o $(BIN_DIR)/DeviceDriverManagerTests \
			DeviceDriverManagerTests.cpp -lDDM -lIPC
	$(CXX) $(CXXFLAGS) -o $(BIN_DIR)/DeviceDriverManagerProxyTests \
			DeviceDriverManagerProxyTests.cpp -lDDM -lIPC

.PHONY: install
install: all
	$(INSTALL) -o bin $(SBIN_DIR)/DDM \
		$(SBIN_PREFIX)/DDM
	$(INSTALL) -o bin $(LIB_DIR)/libDDM.a \
		$(LIB_PREFIX)/libDDM.a
	$(INSTALL) -o bin $(INC_DIR)/DDM.hpp \
		$(INC_PREFIX)/DDM.hpp
	$(INSTALL) -o bin $(INC_DIR)/DDMMessage.hpp \
		$(INC_PREFIX)/DDMMessage.hpp
	$(INSTALL) -o bin $(INC_DIR)/DDMMinix.hpp \
		$(INC_PREFIX)/DDMMinix.hpp
	$(INSTALL) -o bin $(INC_DIR)/DriverInfo.hpp \
		$(INC_PREFIX)/DriverInfo.hpp
	$(INSTALL) -o bin $(INC_DIR)/DriverInfoTypes.hpp \
		$(INC_PREFIX)/DriverInfoTypes.hpp
	$(INSTALL) -o bin $(INC_DIR)/IDriverInfo.hpp \
		$(INC_PREFIX)/IDriverInfo.hpp

.PHONY: uninstall
uninstall:
	$(RM)	$(SBIN_PREFIX)/DDM \
		$(LIB_PREFIX)/libDDM.a \
		$(INC_PREFIX)/DDM.hpp \
		$(INC_PREFIX)/DDMMessage.hpp \
		$(INC_PREFIX)/DDMMinix.hpp \
		$(INC_PREFIX)/DriverInfo.hpp \
		$(INC_PREFIX)/DriverInfoTypes.hpp \
		$(INC_PREFIX)/IDriverInfo.hpp

.PHONY: clean
clean: clean_tests
	$(RM)	$(SBIN_DIR)/DDM \
		$(LIB_DIR)/libDDM.a \
		$(OBJ_DIR)/DDMMessage.o \
		$(OBJ_DIR)/DeviceDriverManager.o \
		$(OBJ_DIR)/DeviceDriverManagerProxy.o \
		$(OBJ_DIR)/DriverInfo.o \
		$(INC_DIR)/DDM.hpp \
		$(INC_DIR)/DDMMessage.hpp \
		$(INC_DIR)/DDMMinix.hpp \
		$(INC_DIR)/DeviceDriverManagerProxy.hpp \
		$(INC_DIR)/DriverInfo.hpp \
		$(INC_DIR)/DriverInfoTypes.hpp \
		$(INC_DIR)/IDeviceDriverManager.hpp \
		$(INC_DIR)/IDriverInfo.hpp

.PHONY: clean_tests
clean_tests:
	$(RM)	$(BIN_DIR)/DeviceDriverManagerTests \
		$(BIN_DIR)/DeviceDriverManagerProxyTests

$(SBIN_DIR)/DDM: \
		$(OBJ_DIR)/DeviceDriverManager.o \
		$(OBJ_DIR)/DriverInfo.o \
		$(LIB_DIR)/libDDM.a $(LIB_DIR)/libIPC.a
	$(CXX) $(CXXFLAGS) $< -o $@ -lsys -lDDM -lIPC

$(LIB_DIR)/libDDM.a: \
		$(OBJ_DIR)/DDMMessage.o \
		$(OBJ_DIR)/DeviceDriverManagerProxy.o \
		$(OBJ_DIR)/DriverInfo.o
	$(AR) r $@ $(OBJ_DIR)/DDMMessage.o
	$(AR) r $@ $(OBJ_DIR)/DeviceDriverManagerProxy.o
	$(AR) r $@ $(OBJ_DIR)/DriverInfo.o

$(OBJ_DIR)/DDMMessage.o: DDMMessage.cpp $(INC_DIR)/DDMMessage.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJ_DIR)/DeviceDriverManager.o: DeviceDriverManager.cpp \
		$(INC_DIR)/DDMMessage.hpp \
		$(INC_DIR)/DriverInfo.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJ_DIR)/DeviceDriverManagerProxy.o: DeviceDriverManagerProxy.cpp \
		$(INC_DIR)/DeviceDriverManagerProxy.hpp \
		$(INC_DIR)/DriverInfo.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJ_DIR)/DriverInfo.o: DriverInfo.cpp DriverInfo.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(INC_DIR)/DDM.hpp: DDM.hpp \
		$(INC_DIR)/DDMMinix.hpp
	$(CP) $< $@

$(INC_DIR)/DDMMessage.hpp: DDMMessage.hpp $(INC_DIR)/DDM.hpp
	$(CP) $< $@

$(INC_DIR)/DDMMinix.hpp: DDMMinix.hpp
	$(CP) $< $@

$(INC_DIR)/DeviceDriverManagerProxy.hpp: DeviceDriverManagerProxy.hpp \
		$(INC_DIR)/IDeviceDriverManager.hpp \
		$(INC_DIR)/IDriverInfo.hpp
	$(CP) $< $@

$(INC_DIR)/DriverInfo.hpp: DriverInfo.hpp \
		$(INC_DIR)/IDriverInfo.hpp \
		$(INC_DIR)/DDMMessage.hpp
	$(CP) $< $@

$(INC_DIR)/DriverInfoTypes.hpp: DriverInfoTypes.hpp
	$(CP) $< $@

$(INC_DIR)/IDeviceDriverManager.hpp: IDeviceDriverManager.hpp \
		$(INC_DIR)/IDriverInfo.hpp
	$(CP) $< $@

$(INC_DIR)/IDriverInfo.hpp: IDriverInfo.hpp \
		$(INC_DIR)/DriverInfoTypes.hpp
	$(CP) $< $@
