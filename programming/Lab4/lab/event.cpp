#include "event.h"

Event::Event()
{
	isValid = false;
	methodList = NULL;
}

int Event::GetCommand()
{
	return command;
}

bool Event::IsValid()
{
	return this.isValid;
}

void Event::Clear()
{
	isValid = false;
}

void Event::Add(Method *_method)
{
	MethodList *tmp = new MethodList;
	tmp->method = _method;
	tmp->next = this.methodList;
	this.methodList = tmp;
}

void Event::Get()
{

}