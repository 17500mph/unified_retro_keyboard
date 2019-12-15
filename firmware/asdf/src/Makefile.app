ARCH ?= atmega328p
KEYMAP ?= ascii

ARCH_TOKEN = _Arch_$(ARCH)

TARGET = asdf

TEST_DIR = ../test
UNITY_DIR = $(TEST_DIR)/unity
BUILD_DIR = ../build
DEP_DIR := ./.deps

TARGET_BIN := $(BUILD_DIR)/$(TARGET).elf
TARGET_HEX := $(BUILD_DIR)/$(TARGET).hex
TARGET_MAP := $(BUILD_DIR)/$(TARGET).map

UNITY_SCRIPTS = $(UNITY_DIR)/auto
ARCH_DIR = Arch
KEYMAPS_DIR = Keymaps
VERSION =
RELEASE=
SIZE_COMMAND = avr-size

CLOCK = 8000000L

CLEAN_FILES =
CLEANALL_FILES =

CC = avr-gcc

CFLAGS = -std=c99
CFLAGS += -Wall
CFLAGS += -funsigned-char
CFLAGS += -funsigned-bitfields
CFLAGS += -ffunction-sections
CFLAGS += -fdata-sections
CFLAGS += -fpack-struct
CFLAGS += -fshort-enums
CFLAGS += -O2
CFLAGS += -Wall
CFLAGS += -Wextra
CFLAGS += -Wpointer-arith
CFLAGS += -Wcast-align
CFLAGS += -Wwrite-strings
CFLAGS += -Wswitch-default
CFLAGS += -Wunreachable-code
CFLAGS += -Winit-self
CFLAGS += -Wmissing-field-initializers
CFLAGS += -Wno-unknown-pragmas
CFLAGS += -Wstrict-prototypes
CFLAGS += -Wundef
CFLAGS += -Wold-style-definition
CFLAGS += -mmcu=$(ARCH)
CFLAGS += -DF_CPU=$(CLOCK)

LDFLAGS = -Wl,-Map=$(TARGET_MAP)
LDFLAGS += -Wl,--start-group
LDFLAGS += -Wl,-lm
LDFLAGS += -Wl,--end-group
LDFLAGS += -Wl,--gc-sections

DEPFLAGS = -MT $@ -MMD -MP -MF $(DEPDIR)/$*.d

MAKEDEPEND = $(CPP) $(DEPFLAGS) $(CPPFLAGS) $< \
             | sed -n 's,^\# *[0-9][0-9]* *"\([^"<]*\)".*,$@: \1\n\1:,p' \
             | sort -u > $*.d

SRC_FILES = main.c asdf.c asdf_modifiers.c asdf_repeat.c asdf_keymaps.c asdf_buffer.c asdf_arch.c
OBJ_FILES := $(SRC_FILES:.c=.o)
DEP_FILES := $(SRC_FILES:%.c=$(DEP_DIR)/%.d)
MAP_FILE = $(TARGET).map

CLEAN_FILES += $(MAP_FILE)

CLEAN_FILES += $(TARGET_BIN)
CLEAN_FILES += $(TARGET_MAP)
CLEANALL_FILES += $(TARGET_HEX)

MAKEFILES = Makefile
GENERATED_FILES = conventions.h machine.h
ALL_FILES = $(MAKEFILES) $(SRC_FILES) $(TXTFILES) $(GENERATED_FILES)

.SUFFIXES:
.SUFFIXES: .c .o .bin .hex


all: $(TARGET_HEX)

%.d : %.c $(DEP_DIR)/%.d | $(DEP_DIR)
	@$(MAKEDEPEND)

$(DEP_DIR): ; @mkdir -p $@

$(DEPFILES):

include $(wildcard $(DEPFILES))

%.o: %.c $(DEP_DIR)/%.d | $(DEP_DIR)
	$(CC) -c $(CPPFLAGS) $(CFLAGS) $(DEPFLAGS) $<

asdf_keymaps.h: $(KEYMAPS_DIR)/asdf_keymaps_$(KEYMAP).h $(KEYMAP_H_TOKEN)
	cp $< $@
GENERATED_FILES += asdf_keymaps.h


asdf_arch.c: $(ARCH_DIR)/asdf_arch_$(ARCH).c $(ARCH_C_TOKEN)
	cp $< $@
GENERATED_FILES += asdf_arch.c


asdf_arch.h: $(ARCH_DIR)/asdf_arch_$(ARCH).h $(ARCH_H_TOKEN)
	cp $< $@
GENERATED_FILES += asdf_arch.h

$(ARCH_H_TOKEN):
	touch $@

$(ARCH_C_TOKEN):
	touch $@

$(KEYMAP_H_TOKEN):
	touch $@

size:
	$(SIZE_COMMAND) $(TARGET_BIN)

$(TARGET_HEX): $(TARGET_BIN)
	avr-objcopy -j .text -j .data -j .fuses -O ihex $< $@

$(TARGET_BIN): $(OBJ_FILES)
	$(CC) $(CFLAGS) -o $@ $(LDFLAGS) $^
	$(SIZE_COMMAND) $(TARGET_BIN)

asdf_keymaps.o: asdf_keymaps.c asdf.h asdf_ascii.h asdf_modifiers.h asdf_arch.h asdf_keymaps.h
main.o: main.c asdf.h asdf_arch.h
asdf.o: asdf.c asdf.h asdf_arch.h asdf_keymaps.h asdf_config.h
asdf_repeat.o: asdf_repeat.c asdf_repeat.h asdf_config.h
asdf_buffer.o: asdf_buffer.c asdf.h asdf_config.h
asdf_modifiers.o: asdf_modifiers.c asdf_modifiers.h

tags:   $(SRC_FILES)
	etags $(SRC_FILES)

CLEAN_FILES += $(TEST_BUILD_FILES) _Arch_* *.o
CLEAN_FILES += ~* *\#

CLEANALL_FILES += $(GENERATED_FILES) $(TARGET_BUILD_FILES) $(TEST_BUILD_FILES)

.PHONY: clean
clean:
	rm -f $(CLEAN_FILES)

.PHONY: cleanall
cleanall:
	rm -f $(CLEAN_FILES) $(CLEANALL_FILES)

