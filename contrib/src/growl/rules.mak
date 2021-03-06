# growl

GROWL_VERSION := 1.2.2
GROWL_URL := http://growl.googlecode.com/files/Growl-$(GROWL_VERSION)-src.tbz

ifdef HAVE_MACOSX
PKGS += growl
endif

$(TARBALLS)/growl-$(GROWL_VERSION).tar.bz2:
	$(call download,$(GROWL_URL))

.sum-growl: growl-$(GROWL_VERSION).tar.bz2

growl: growl-$(GROWL_VERSION).tar.bz2 .sum-growl
	$(UNPACK)
	mv Growl-1.2.2-src growl-1.2.2
	$(APPLY) $(SRC)/growl/growl-xcode5.patch
	$(APPLY) $(SRC)/growl/growl-log-delegate.patch
	$(APPLY) $(SRC)/growl/growl-hg-revision.patch
	$(MOVE)

.growl: growl
	cd $< && xcodebuild $(XCODE_FLAGS) CC="$(word $(words $(CC)),$(CC))" CXX="$(word $(words $(CXX)),$(CXX))" GCC_VERSION=4.2 -target Growl.framework -configuration Release
	install -d $(PREFIX)
	cd $< && cp -Rf build/Release/Growl.framework "$(PREFIX)"
	touch $@
