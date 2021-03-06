#pragma once

#include <gtk/gtk.h>
#include "../Custom/List/List.hh"

namespace CGui
{
	class StyleContext
	{
	public:
		StyleContext(GtkWidget* w)
		{
			this->SetContext(w);
		}

		virtual void AddStyleClass(const char* classname)
		{
			gtk_style_context_add_class(GTK_STYLE_CONTEXT(stylecontext), classname);
		}

		virtual void RemoveStyleClass(const char* classname)
		{
			gtk_style_context_remove_class(GTK_STYLE_CONTEXT(stylecontext), classname);
		}

		virtual bool HasStyleClass(const char* classname)
		{
			return gtk_style_context_has_class(GTK_STYLE_CONTEXT(stylecontext), classname);
		}

		virtual Single::List<const char*> ListStyleClasses()
		{
			Single::List<const char*> t_list;
			auto g_list = gtk_style_context_list_classes(GTK_STYLE_CONTEXT(stylecontext));

			for (GList* l = g_list; l != NULL; l = l->next)
			{
				t_list.Insert((const char*)l->data);
			}

			g_list_free(g_list);

			return t_list;
		}

		bool IsStyleContext()
		{
			return GTK_IS_STYLE_CONTEXT(stylecontext);
		}

	protected:
		StyleContext()
		{  }

		void SetContext(GtkWidget* w)
		{
			stylecontext = gtk_widget_get_style_context(GTK_WIDGET(w));
		}

	private:
		GtkStyleContext* stylecontext;
	};
}