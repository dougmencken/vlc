# bghudappkit

BGHUDAPPKIT_GITURL := git://github.com/binarygod/BGHUDAppKit.git

ifdef HAVE_MACOSX
PKGS += bghudappkit
endif

$(TARBALLS)/bghudappkit-git.tar.xz:
	$(call download_git,$(BGHUDAPPKIT_GITURL),,79a560d)


.sum-bghudappkit: bghudappkit-git.tar.xz
	$(warning $@ not implemented)
	touch $@


bghudappkit: bghudappkit-git.tar.xz .sum-bghudappkit
	$(UNPACK)
	$(APPLY) $(SRC)/bghudappkit/bghudappkit-xcode5.patch
	$(MOVE)

.bghudappkit: bghudappkit
	cd $< && xcodebuild $(XCODE_FLAGS) CC="$(word $(words $(CC)),$(CC))" CXX="$(word $(words $(CXX)),$(CXX))" GCC_VERSION=4.2
	install -d $(PREFIX)
	cd $< && cp -Rf build/Release/BGHUDAppKit.framework "$(PREFIX)"
	touch $@
