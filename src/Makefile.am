AM_CFLAGS = $(GLIB_CFLAGS) $(GIO_CFLAGS)

BUILT_SOURCES = greeting.c greeting.h
dist_noinst = greeting_interface.xml

bin_PROGRAMS = gdbus_server gdbus_client

gdbus_server_SOURCES = gdbus_server.c \
		greeting.c greeting.h
gdbus_server_LDADD = $(GLIB_LIBS) $(GIO_LIBS)

gdbus_client_SOURCES = gdbus_client.c \
	greeting.c greeting.h
gdbus_client_LDADD = $(GLIB_LIBS) $(GIO_LIBS)

greeting.c greeing.h : greeting_interface.xml
	gdbus-codegen --interface-prefix=net.developerstory.gdbus --generate-c-code=greeting $<

MOSTLYCLEANFILES = $(BUILT_SOURCES)
