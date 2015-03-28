
#include <glib.h>
#include <gio/gio.h>

#include "greeting.h"

int main(int argc, char *argv[])
{
	Greeting *proxy;
	GError *error = NULL;

	proxy = greeting_proxy_new_for_bus_sync(
			G_BUS_TYPE_SESSION,
			G_DBUS_PROXY_FLAGS_NONE,
			"net.developerstory.gdbus",
			"/net/developerstory/gdbus/greeting",
			NULL,
			&error);

	greeting_call_hello_sync(proxy, "hello world", NULL, &error);

	g_object_unref(proxy);
	return 0;
}
