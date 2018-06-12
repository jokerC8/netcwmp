CONFOPTS:=--host=mipsel-linux-uclibc --prefix=/home/joker/netcwmp/out/

ifeq ($(CROSS_COMPILE),)
CROSS_COMPILE:=/opt/buildroot-gcc463/usr/bin/mipsel-linux-
endif

all: Makefile
	make -f Makefile

Makefile:
	autoreconf -i -v
	CC=$(CROSS_COMPILE)gcc  LD=$(CROSS_COMPILE)ld STRIP=$(CROSS_COMPILE)strip ./configure $(CONFOPTS)

clean distclean:
	rm -rf Makefile Makefile.in configure configure.lineno config.h config.h.in~ libtool
	rm -rf autom4te.cache/output.3 autom4te.cache/traces.3
	rm -rf cwmpd/src/.deps/ cwmpd/src/*.o cwmpd/src/cwmpd cwmpd/src/.libs/ cwmpd/src/Makefile cwmpd/src/Makefile.in
	rm -rf libcwmp/src/.deps/ libcwmp/src/*.o libcwmp/src/libcwmp.a libcwmp/src/Makefile libcwmp/src/Makefile.in
	rm -rf libpool/src/.deps/ libpool/src/*.o libpool/src/libpool.a libpool/src/Makefile libpool/src/Makefile.in
	rm -rf libxmlet/src/.deps/ libxmlet/src/*.o libxmlet/src/libxmlet.a libxmlet/src/Makefile libxmlet/src/Makefile.in
	rm -rf tests/src/.deps/ tests/src/*.o tests/src/testall tests/src/.libs/ tests/src/Makefile tests/src/Makefile.in
	rm -rf build/ltmain.sh config.h.in config.log config.status aclocal.m4
	rm -rf autom4te.cache .sgbuilt_user

romfs:
#	$(STRIP) cwmpd
	$(ROMFSINST) cwmpd/src/cwmpd /bin/cwmpd
	$(ROMFSINST) cwmpd/src/device.xml /etc/cwmp_device.xml

# the is a proxy section --YY
all-recursive: Makefile
	make -f Makefile all-recursive

# the is a proxy section --YY
all-am: Makefile
	make -f Makefile all-am

# the is a proxy section --YY
clean-am: Makefile
	make -f Makefile clean-am



