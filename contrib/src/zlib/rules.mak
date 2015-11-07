# ZLIB
ZLIB_VERSION := 1.2.8
ZLIB_URL := $(SF)/libpng/zlib-$(ZLIB_VERSION).tar.gz

PKGS += zlib

ifdef HAVE_SOLARIS
ZLIB_ECFLAGS = -fPIC -DPIC
endif

$(TARBALLS)/zlib-$(ZLIB_VERSION).tar.gz:
	$(call download,$(ZLIB_URL))

.sum-zlib: zlib-$(ZLIB_VERSION).tar.gz

zlib: zlib-$(ZLIB_VERSION).tar.gz .sum-zlib
	$(UNPACK)
	$(MOVE)

.zlib: zlib
	cd $< && $(HOSTVARS) $(ZLIB_CONFIG_VARS) CFLAGS="$(CFLAGS) $(ZLIB_ECFLAGS)" ./configure --prefix=$(PREFIX) --static
	cd $< && $(MAKE) install
	touch $@
