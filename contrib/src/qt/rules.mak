# qt

QT_VERSION_SHORT = 5.5
QT_VERSION_WITH_SUB = 5.5.1
QT_URL := http://download.qt-project.org/official_releases/qt/$(QT_VERSION_SHORT)/$(QT_VERSION_WITH_SUB)/submodules/qtbase-opensource-src-$(QT_VERSION_WITH_SUB).tar.xz

ifdef HAVE_MACOSX
PKGS += qt
endif
ifdef HAVE_WIN32
PKGS += qt
endif

ifeq ($(call need_pkg,"QtCore QtGui"),)
ifeq ($(call need_pkg,"Qt5Core Qt5Gui Qt5Widgets"),)
PKGS_FOUND += qt
endif
endif

$(TARBALLS)/qt-$(QT_VERSION_WITH_SUB).tar.xz:
	$(call download,$(QT_URL))

.sum-qt: qt-$(QT_VERSION_WITH_SUB).tar.xz

qt: qt-$(QT_VERSION_WITH_SUB).tar.xz .sum-qt
	$(UNPACK)
	mv qtbase-opensource-src-$(QT_VERSION_WITH_SUB) qt-$(QT_VERSION_WITH_SUB)
	$(APPLY) $(SRC)/qt/qtbase-507b6b3e.patch
	$(APPLY) $(SRC)/qt/qtbase-printing-no-id.patch
	$(APPLY) $(SRC)/qt/qt-macosx-leopard.patch
	$(APPLY) $(SRC)/qt/qt-5.5-leopard.patch
	$(APPLY) $(SRC)/qt/qt-qcocoawindow-5.5-leopard.patch
	$(APPLY) $(SRC)/qt/qt-qstorageinfo-mac-fix.patch
	$(APPLY) $(SRC)/qt/qt-qmacstyle-leopard.patch
	$(MOVE)

QT_CONFIGURE_OPTIONS := -static -release -no-sql-sqlite -no-gif -qt-libjpeg -no-openssl -no-opengl

ifdef HAVE_MACOSX
QT_PLATFORM := -platform macx-g++42
QT_CONFIGURE_OPTIONS += -no-pch -no-securetransport
QT_PLATFORM_PLUGIN := qcocoa
endif
ifdef HAVE_WIN32
QT_PLATFORM := -xplatform win32-g++ -device-option CROSS_COMPILE=$(HOST)-
QT_PLATFORM_PLUGIN := qwindows
endif

.qt: qt
	cd $< && ./configure $(QT_PLATFORM) $(QT_CONFIGURE_OPTIONS) -opensource -confirm-license -v
	cd $< && $(MAKE) sub-src
	# INSTALLING LIBRARIES
	for lib in Widgets Gui Core; \
		do install -D -- $</lib/libQt5$${lib}.a "$(PREFIX)/lib/libQt5$${lib}.a"; \
	done
	# INSTALLING PLUGINS
	install -D -- $</plugins/platforms/lib$(QT_PLATFORM_PLUGIN).a "$(PREFIX)/lib/lib$(QT_PLATFORM_PLUGIN).a"
	install -D -- $</lib/libqtharfbuzzng.a "$(PREFIX)/lib/libqtharfbuzzng.a"
	install -D -- $</lib/libqtpcre.a "$(PREFIX)/lib/libqtpcre.a"
	# dist/changes-5.4.0
	# [QTBUG-32888] Accessibility for widgets is now included in the widget
	# library instead of being a separate plugin. For static builds this means
	# that libqtaccessiblewidgets is no longer required.
	##install -D -- $</plugins/accessible/libqtaccessiblewidgets.a "$(PREFIX)/lib/libqtaccessiblewidgets.a"
	# INSTALLING HEADERS
	for h in corelib gui widgets; \
		do (cd $</src/$${h} && find . -type f -name '*.h' -exec install -D -- "{}" "$(PREFIX)/include/qt5/src/$${h}/{}" \;) ; \
	done
	for h in Core Gui Widgets; \
		do (cd $</include/Qt$${h} && find . -maxdepth 1 -type f \( -name '*.h' -o -name 'Q*' \) -exec install -D -s --strip-program="$(abspath $(SRC)/qt/fix_header.sh)" -- "{}" "$(PREFIX)/include/qt5/Qt$${h}/{}" \;) ; \
	done
	mkdir -p "$(PREFIX)/include/qt5/qpa"
	echo "#include \"../src/gui/kernel/qplatformnativeinterface.h\"" > "$(PREFIX)/include/qt5/qpa/qplatformnativeinterface.h"
	# INSTALLING PKGCONFIG FILES
	install -d "$(PREFIX)/lib/pkgconfig"
	for i in Core Gui Widgets; \
		do cat $(SRC)/qt/Qt5$${i}.pc.in | sed -e s/@@VERSION@@/$(QT_VERSION_WITH_SUB)/ | sed -e 's|@@PREFIX@@|$(PREFIX)|' > "$(PREFIX)/lib/pkgconfig/Qt5$${i}.pc"; \
	done
	# BUILDING QT BUILD TOOLS
ifdef HAVE_CROSS_COMPILE
	cd $</include/QtCore; ln -sf $(QT_VERSION_WITH_SUB)/QtCore/private
	cd $</src/tools; $(MAKE) clean; \
		for i in bootstrap uic rcc moc; \
			do (cd $$i; echo $i && ../../../bin/qmake -spec win32-g++ ; $(MAKE) clean; $(MAKE)); \
		done
endif
	# INSTALLING QT BUILD TOOLS
	install -d "$(PREFIX)/bin/"
	for i in rcc moc uic; \
		do cp $</bin/$$i* "$(PREFIX)/bin"; \
	done
	touch $@
