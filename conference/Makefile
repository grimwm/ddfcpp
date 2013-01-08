include mk/include.mk

CLEAN_FILES	=	*.aux *.bak *.bbl *.blg .clean_graffle *.dvi *.eps \
			*.lof *.log *.lot *.out *.pdf *.ps *.toc
EPS_FILES	=	deva_layout.eps ddf_layout.eps ddf_sequence.eps \
			ddf_uml.eps ddm_layout.eps ddm_lib_uml.eps \
			ddm_sequence.eps driver_lib_uml.eps \
			endianness.eps kernel_design.eps io_lib_uml.eps \
			ipc_lib_uml.eps mem_lib_uml.eps \
			microkernel_servers.eps minix_async_msg.eps \
			multiboot_header.eps multiboot_info.eps spaces.eps \
			types_lib_uml.eps

#PROJECT		=  thesis
PROJECT		=  cdes08

all: $(PROJECT)

# Depend on DVI files, since the suffix-rules are set to build DVI files
# into PDF and PS files using original TEX files of the same prefix name.
$(PROJECT): $(PROJECT).dvi

.PHONY: $(PROJECT).tex
$(PROJECT).tex: $(EPS_FILES)

include mk/clean.mk
clean: include_clean
