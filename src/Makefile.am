AM_CFLAGS = $(GLIB_CFLAGS) $(GIO_CFLAGS)

bin_PROGRAMS = gdbus_server gdbus_client

gdbus_server_SOURCES = gdbus_server.c
gdbus_server_LDADD = $(GLIB_LIBS) $(GIO_LIBS)

gdbus_client_SOURCES = gdbus_client.c
gdbus_client_LDADD = $(GLIB_LIBS) $(GIO_LIBS)

