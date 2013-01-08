TOPDIR?=	../..

-include ../../mk/common.mk
-include ../../mk/cpp.mk

all:		$(INC_DIR)/IO.hpp \
		$(INC_DIR)/IOHeaders.hpp \
		$(INC_DIR)/minix/IO.hpp

.PHONY: install
install: all
	$(INSTALL) -o bin $(INC_DIR)/IO.hpp \
		$(INC_PREFIX)/IO.hpp
	$(INSTALL) -o bin $(INC_DIR)/IOHeaders.hpp \
		$(INC_PREFIX)/IOHeaders.hpp

.PHONY: uninstall
uninstall:
	$(RM)	$(INC_PREFIX)/IO.hpp \
		$(INC_PREFIX)/IOHeaders.hpp \
		$(INC_PREFIX)/minix/IO.hpp

.PHONY: clean
clean:
	$(RM)	$(INC_DIR)/IO.hpp \
		$(INC_DIR)/IOHeaders.hpp \
		$(INC_DIR)/minix/IO.hpp

$(INC_DIR)/IO.hpp: IO.hpp
	$(CP) $< $@

$(INC_DIR)/IOHeaders.hpp: IOHeaders.hpp
	$(CP) $< $@

$(INC_DIR)/minix/IO.hpp: minix/IO.hpp
	$(CP) $< $@
