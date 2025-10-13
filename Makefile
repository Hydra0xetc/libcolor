CC = gcc
CFLAGS = -fPIC -Wall -Wextra -std=c11 \
         -O2 -D_FORTIFY_SOURCE=2 \
         -fstack-protector-strong

LDFLAGS = -shared

SRC = color.c
HEADER = color.h
TARGET = libcolor.so

PREFIX ?= $(HOME)/.local
INSTALL_DIR_LIB = $(PREFIX)/lib
INSTALL_DIR_INCLUDE = $(PREFIX)/include
INSTALL_DIR_PKGCONFIG = $(INSTALL_DIR_LIB)/pkgconfig

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $<

install: all
	@echo "Installing library to $(INSTALL_DIR_LIB)..."
	@mkdir -p $(INSTALL_DIR_LIB)
	@cp $(TARGET) $(INSTALL_DIR_LIB)/
	@echo "Installing header to $(INSTALL_DIR_INCLUDE)..."
	@mkdir -p $(INSTALL_DIR_INCLUDE)
	@cp $(HEADER) $(INSTALL_DIR_INCLUDE)/
	@echo "Installing pkg-config file to $(INSTALL_DIR_PKGCONFIG)..."
	@mkdir -p $(INSTALL_DIR_PKGCONFIG)
	@cp libcolor.pc $(INSTALL_DIR_PKGCONFIG)/
	@echo "Installation complete."

uninstall:
	@echo "Uninstalling library..."
	@rm -f $(INSTALL_DIR_LIB)/$(TARGET)
	@echo "Uninstalling header..."
	@rm -f $(INSTALL_DIR_INCLUDE)/$(HEADER)
	@echo "Uninstalling pkg-config file..."
	@rm -f $(INSTALL_DIR_PKGCONFIG)/libcolor.pc
	@echo "Uninstallation complete."

clean:
	@echo "Cleaning up..."
	@rm -f $(TARGET)
	@echo "Cleanup complete."

.PHONY: all install uninstall clean
