export BOARD = stm32f429discovery
ROOTDIR = $(CURDIR)/uC-sdk

ifeq ($(wildcard $(ROOTDIR)/uC-sdk.root),)
ifneq ($(wildcard ../../../uC-sdk.root),)
ROOTDIR = ../../..
endif
endif

TARGET = task.bin
TARGET_SRCS = task.c

LIBDEPS = \
$(ROOTDIR)/FreeRTOS/libFreeRTOS.a \
$(ROOTDIR)/arch/libarch.a \
$(ROOTDIR)/os/libos.a \
$(ROOTDIR)/libc/libc.a \
$(ROOTDIR)/libm/libm.a \
$(ROOTDIR)/acorn/libacorn.a \
$(ROOTDIR)/hardware/libhardware.a \

LIBS = -Wl,--start-group $(LIBDEPS) -Wl,--end-group
TARGET_INCLUDES = include

include $(ROOTDIR)/common.mk

all: uC-sdk $(TARGET)

clean: clean-generic
	$(Q)$(MAKE) $(MAKE_OPTS) -C $(ROOTDIR) clean

.PHONY: uC-sdk

$(ROOTDIR)/FreeRTOS/libFreeRTOS.a: uC-sdk
$(ROOTDIR)/arch/libarch.a: uC-sdk
$(ROOTDIR)/os/libos.a: uC-sdk
$(ROOTDIR)/libc/libc.a: uC-sdk
$(ROOTDIR)/libm/libm.a: uC-sdk
$(ROOTDIR)/acorn/libacorn.a: uC-sdk
$(ROOTDIR)/hardware/libhardware.a: uC-sdk

uC-sdk:
	$(E) "[MAKE]   Entering uC-sdk"
	$(Q)$(MAKE) $(MAKE_OPTS) -C $(ROOTDIR)

deps: ldeps
	$(E) "[DEPS]   Creating dependency tree for uC-sdk"
	$(Q)$(MAKE) $(MAKE_OPTS) -C $(ROOTDIR) ldeps

include $(ROOTDIR)/FreeRTOS/config.mk
include $(ROOTDIR)/arch/config.mk
include $(ROOTDIR)/os/config.mk
include $(ROOTDIR)/libc/config.mk
include $(ROOTDIR)/libm/config.mk
include $(ROOTDIR)/acorn/config.mk
include $(ROOTDIR)/hardware/config.mk
include $(ROOTDIR)/target-rules.mk

