#include "./StackSwitcher.hh"

namespace CGui
{
	StackSwitcher::StackSwitcher()
	{
		widget = gtk_stack_switcher_new();
		this->SetBox(GTK_BOX(widget));
	}

	void StackSwitcher::Stack(CGui::Stack& stack)
	{
		gtk_stack_switcher_set_stack(GTK_STACK_SWITCHER(widget), GTK_STACK(stack.GetWidget()));
	}

	CGui::Stack StackSwitcher::Stack()
	{
		return CGui::Stack(gtk_stack_switcher_get_stack(GTK_STACK_SWITCHER(widget)));
	}
}