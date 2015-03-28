#include <glib.h>
#include <gio/gio.h>

#include "greeting.h"

static gboolean on_handle_hello(Greeting *skeleton,
		GDBusMethodInvocation *invocation,
		const gchar *greeting,
		gpointer user_data)
{
	g_print("Method call: %s\n", greeting);

	greeting_complete_hello(skeleton, invocation);

	return TRUE;
}

static void on_bus_acquired(GDBusConnection *connection,
		const gchar *name,
		gpointer user_data)
{
	Greeting *skeleton;
	GError *error = NULL;

	skeleton = greeting_skeleton_new();


	g_signal_connect(skeleton, "handle-hello",
			G_CALLBACK(on_handle_hello),
			NULL);

	g_dbus_interface_skeleton_export(skeleton, connection, "/net/developerstory/gdbus/greeting", &error);
}

static void on_name_acquired(GDBusConnection *connection,
		const gchar *name,
		gpointer user_data)
{
}

static void on_name_lost(GDBusConnection *connection,
		const gchar *name,
		gpointer user_data)
{
}

int main(int argc, char *argv[])
{
	GMainLoop *loop = NULL;
	guint owner_id;

	owner_id = g_bus_own_name(G_BUS_TYPE_SESSION,
			"net.developerstory.gdbus",
			G_BUS_NAME_OWNER_FLAGS_NONE,
			on_bus_acquired,
			on_name_acquired,
			on_name_lost,
			NULL,
			NULL);

	loop = g_main_loop_new(NULL, FALSE);
	g_main_loop_run(loop);

	g_bus_unown_name(owner_id);

	return 0;
}
