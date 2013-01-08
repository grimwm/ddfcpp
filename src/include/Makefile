TOPDIR?=	../..

-include ../../mk/common.mk

all: $(INC_DIR)/Exceptions.hpp $(INC_DIR)/Types.hpp $(INC_DIR)/UnitTest.hpp \
		$(INC_DIR)/Util.hpp

$(INC_DIR)/Exceptions.hpp: Exceptions.hpp
	$(CP) Exceptions.hpp $(INC_DIR)/Exceptions.hpp

$(INC_DIR)/Types.hpp: Types.hpp
	$(CP) Types.hpp $(INC_DIR)/Types.hpp

$(INC_DIR)/UnitTest.hpp: UnitTest.hpp
	$(CP) UnitTest.hpp $(INC_DIR)/UnitTest.hpp

$(INC_DIR)/Util.hpp: Util.hpp
	$(CP) Util.hpp $(INC_DIR)/Util.hpp

.PHONY: install
install: all
	$(INSTALL) -o bin Exceptions.hpp $(INC_PREFIX)/Exceptions.hpp
	$(INSTALL) -o bin Types.hpp $(INC_PREFIX)/Types.hpp
	$(INSTALL) -o bin Util.hpp $(INC_PREFIX)/Util.hpp

.PHONY: uninstall
uninstall: clean
	$(RM)	$(INC_PREFIX)/Exceptions.hpp
		$(INC_PREFIX)/Types.hpp
		$(INC_PREFIX)/Util.hpp

.PHONY: clean
clean:
	$(RM)	$(INC_DIR)/Exceptions.hpp \
		$(INC_DIR)/Types.hpp \
		$(INC_DIR)/UnitTest.hpp \
		$(INC_DIR)/Util.hpp
