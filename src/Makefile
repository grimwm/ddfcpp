TOPDIR?=	..

-include ../mk/common.mk

all:
	$(MKDIR) $(INC_DIR)/minix
	$(MAKE) -C include $@
	$(MAKE) -C IPC $@
	$(MAKE) -C Service $@
	$(MAKE) -C Mem $@
	$(MAKE) -C IO $@
	$(MAKE) -C DDM $@
	$(MAKE) -C Driver $@
	$(MAKE) -C KeyboardDriver $@
	$(MAKE) -C ListenerDriver $@

.PHONY: install
install:
	$(MKDIR) $(INC_PREFIX)/minix
	$(MAKE) -C include $@
	$(MAKE) -C IPC $@
	$(MAKE) -C Service $@
	$(MAKE) -C Mem $@
	$(MAKE) -C IO $@
	$(MAKE) -C DDM $@
	$(MAKE) -C Driver $@
	$(MAKE) -C KeyboardDriver $@
	$(MAKE) -C ListenerDriver $@

.PHONY: uninstall
uninstall:
	$(RMDIR) $(INC_PREFIX)/minix
	$(MAKE) -C include $@
	$(MAKE) -C IPC $@
	$(MAKE) -C Service $@
	$(MAKE) -C Mem $@
	$(MAKE) -C IO $@
	$(MAKE) -C DDM $@
	$(MAKE) -C Driver $@
	$(MAKE) -C KeyboardDriver $@
	$(MAKE) -C ListenerDriver $@

.PHONY: doc
doc:
	doxygen Doxyfile

.PHONY: clean
clean:
	$(MAKE) -C include $@
	$(MAKE) -C IPC $@
	$(MAKE) -C Service $@
	$(MAKE) -C Mem $@
	$(MAKE) -C IO $@
	$(MAKE) -C DDM $@
	$(MAKE) -C Driver $@
	$(MAKE) -C KeyboardDriver $@
	$(MAKE) -C ListenerDriver $@
	$(RMDIR) $(INC_DIR)/minix
	$(RMDIR) doxygen-out
