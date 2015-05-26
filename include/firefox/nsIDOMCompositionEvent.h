/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM /jds/packages/BUILD/SUNWfirefox-10.0.2/firefox/dom/interfaces/events/nsIDOMCompositionEvent.idl
 */

#ifndef __gen_nsIDOMCompositionEvent_h__
#define __gen_nsIDOMCompositionEvent_h__


#ifndef __gen_nsIDOMUIEvent_h__
#include "nsIDOMUIEvent.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMCompositionEvent */
#define NS_IDOMCOMPOSITIONEVENT_IID_STR "9244a692-2827-4f98-8335-fff958d046fc"

#define NS_IDOMCOMPOSITIONEVENT_IID \
  {0x9244a692, 0x2827, 0x4f98, \
    { 0x83, 0x35, 0xff, 0xf9, 0x58, 0xd0, 0x46, 0xfc }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMCompositionEvent : public nsIDOMUIEvent {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMCOMPOSITIONEVENT_IID)

  /* readonly attribute DOMString data; */
  NS_SCRIPTABLE NS_IMETHOD GetData(nsAString & aData) = 0;

  /* readonly attribute DOMString locale; */
  NS_SCRIPTABLE NS_IMETHOD GetLocale(nsAString & aLocale) = 0;

  /* void initCompositionEvent (in DOMString typeArg, in boolean canBubbleArg, in boolean cancelableArg, in nsIDOMWindow viewArg, in DOMString dataArg, in DOMString localeArg); */
  NS_SCRIPTABLE NS_IMETHOD InitCompositionEvent(const nsAString & typeArg, bool canBubbleArg, bool cancelableArg, nsIDOMWindow *viewArg, const nsAString & dataArg, const nsAString & localeArg) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMCompositionEvent, NS_IDOMCOMPOSITIONEVENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMCOMPOSITIONEVENT \
  NS_SCRIPTABLE NS_IMETHOD GetData(nsAString & aData); \
  NS_SCRIPTABLE NS_IMETHOD GetLocale(nsAString & aLocale); \
  NS_SCRIPTABLE NS_IMETHOD InitCompositionEvent(const nsAString & typeArg, bool canBubbleArg, bool cancelableArg, nsIDOMWindow *viewArg, const nsAString & dataArg, const nsAString & localeArg); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMCOMPOSITIONEVENT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetData(nsAString & aData) { return _to GetData(aData); } \
  NS_SCRIPTABLE NS_IMETHOD GetLocale(nsAString & aLocale) { return _to GetLocale(aLocale); } \
  NS_SCRIPTABLE NS_IMETHOD InitCompositionEvent(const nsAString & typeArg, bool canBubbleArg, bool cancelableArg, nsIDOMWindow *viewArg, const nsAString & dataArg, const nsAString & localeArg) { return _to InitCompositionEvent(typeArg, canBubbleArg, cancelableArg, viewArg, dataArg, localeArg); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMCOMPOSITIONEVENT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetData(nsAString & aData) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetData(aData); } \
  NS_SCRIPTABLE NS_IMETHOD GetLocale(nsAString & aLocale) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLocale(aLocale); } \
  NS_SCRIPTABLE NS_IMETHOD InitCompositionEvent(const nsAString & typeArg, bool canBubbleArg, bool cancelableArg, nsIDOMWindow *viewArg, const nsAString & dataArg, const nsAString & localeArg) { return !_to ? NS_ERROR_NULL_POINTER : _to->InitCompositionEvent(typeArg, canBubbleArg, cancelableArg, viewArg, dataArg, localeArg); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMCompositionEvent : public nsIDOMCompositionEvent
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMCOMPOSITIONEVENT

  nsDOMCompositionEvent();

private:
  ~nsDOMCompositionEvent();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMCompositionEvent, nsIDOMCompositionEvent)

nsDOMCompositionEvent::nsDOMCompositionEvent()
{
  /* member initializers and constructor code */
}

nsDOMCompositionEvent::~nsDOMCompositionEvent()
{
  /* destructor code */
}

/* readonly attribute DOMString data; */
NS_IMETHODIMP nsDOMCompositionEvent::GetData(nsAString & aData)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute DOMString locale; */
NS_IMETHODIMP nsDOMCompositionEvent::GetLocale(nsAString & aLocale)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void initCompositionEvent (in DOMString typeArg, in boolean canBubbleArg, in boolean cancelableArg, in nsIDOMWindow viewArg, in DOMString dataArg, in DOMString localeArg); */
NS_IMETHODIMP nsDOMCompositionEvent::InitCompositionEvent(const nsAString & typeArg, bool canBubbleArg, bool cancelableArg, nsIDOMWindow *viewArg, const nsAString & dataArg, const nsAString & localeArg)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMCompositionEvent_h__ */
