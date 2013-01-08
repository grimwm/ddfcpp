TOPDIR?=	../..

-include ../../mk/common.mk
-include ../../mk/cpp.mk

all:		$(INC_DIR)/Service.hpp \
		$(INC_DIR)/ServiceHeaders.hpp \
		$(INC_DIR)/minix/Service.hpp

.PHONY: install
install: all
	$(INSTALL) -o bin $(INC_DIR)/Service.hpp \
		$(INC_PREFIX)/Service.hpp
	$(INSTALL) -o bin $(INC_DIR)/ServiceHeaders.hpp \
		$(INC_PREFIX)/ServiceHeaders.hpp
	$(INSTALL) -o bin $(INC_DIR)/minix/Service.hpp \
		$(INC_PREFIX)/minix/Service.hpp

.PHONY: uninstall
uninstall:
	$(RM)	$(INC_PREFIX)/Service.hpp \
		$(INC_PREFIX)/ServiceHeaders.hpp \
		$(INC_PREFIX)/minix/Service.hpp

.PHONY: clean
clean:
	$(RM)	$(INC_DIR)/Service.hpp \
		$(INC_DIR)/ServiceHeaders.hpp \
		$(INC_DIR)/minix/Service.hpp

$(INC_DIR)/Service.hpp: Service.hpp
	$(CP) $< $@

$(INC_DIR)/ServiceHeaders.hpp: ServiceHeaders.hpp
	$(CP) $< $@

$(INC_DIR)/minix/Service.hpp: minix/Service.hpp
	$(CP) $< $@
