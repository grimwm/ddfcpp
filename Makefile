# Makefiles in subdirectories should be careful when they set this variable
# by setting it with "TOPDIR?=<dir>".  This will ensure that when Makefile
# in the subdirectory is included, it will not overwrite the existing value
# of TOPDIR which shall be the correct value of TOPDIR for the existing build.
TOPDIR=		.

# Makefiles in subdirectories should also be careful when including files.
# Since the Makefiles themselves can be included by other Makefiles, they
# should use "-include <file>" instead.  Note that TOPDIR should not be
# used in this inclusion or we will run into the problem of the same files
# being included multiple times.
include mk/common.mk
include mk/c.mk

all build image:
	$(MAKE) -C src all

.PHONY: install
install:
	$(MAKE) -C src $@

.PHONY: uninstall
uninstall:
	$(MAKE) -C src $@

.PHONY: tests
tests:
	@echo "No tests are available for this module."

.PHONY: clean
clean:
	$(MAKE) -C src $@

include Makefile.patches
