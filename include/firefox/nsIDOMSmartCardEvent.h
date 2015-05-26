/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM /jds/packages/BUILD/SUNWfirefox-10.0.2/firefox/dom/interfaces/events/nsIDOMSmartCardEvent.idl
 */

#ifndef __gen_nsIDOMSmartCardEvent_h__
#define __gen_nsIDOMSmartCardEvent_h__


#ifndef __gen_nsIDOMEvent_h__
#include "nsIDOMEvent.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMSmartCardEvent */
#define NS_IDOMSMARTCARDEVENT_IID_STR "57e2dd86-3c70-4d9c-81d0-856d42e6bc7d"

#define NS_IDOMSMARTCARDEVENT_IID \
  {0x57e2dd86, 0x3c70, 0x4d9c, \
    { 0x81, 0xd0, 0x85, 0x6d, 0x42, 0xe6, 0xbc, 0x7d }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMSmartCardEvent : public nsIDOMEvent {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMSMARTCARDEVENT_IID)

  /* readonly attribute DOMString tokenName; */
  NS_SCRIPTABLE NS_IMETHOD GetTokenName(nsAString & aTokenName) = 0;

  /* [noscript] void Init (in nsIDOMEvent event); */
  NS_IMETHOD Init(nsIDOMEvent *event) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMSmartCardEvent, NS_IDOMSMARTCARDEVENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMSMARTCARDEVENT \
  NS_SCRIPTABLE NS_IMETHOD GetTokenName(nsAString & aTokenName); \
  NS_IMETHOD Init(nsIDOMEvent *event); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMSMARTCARDEVENT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetTokenName(nsAString & aTokenName) { return _to GetTokenName(aTokenName); } \
  NS_IMETHOD Init(nsIDOMEvent *event) { return _to Init(event); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMSMARTCARDEVENT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetTokenName(nsAString & aTokenName) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTokenName(aTokenName); } \
  NS_IMETHOD Init(nsIDOMEvent *event) { return !_to ? NS_ERROR_NULL_POINTER : _to->Init(event); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMSmartCardEvent : public nsIDOMSmartCardEvent
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMSMARTCARDEVENT

  nsDOMSmartCardEvent();

private:
  ~nsDOMSmartCardEvent();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMSmartCardEvent, nsIDOMSmartCardEvent)

nsDOMSmartCardEvent::nsDOMSmartCardEvent()
{
  /* member initializers and constructor code */
}

nsDOMSmartCardEvent::~nsDOMSmartCardEvent()
{
  /* destructor code */
}

/* readonly attribute DOMString tokenName; */
NS_IMETHODIMP nsDOMSmartCardEvent::GetTokenName(nsAString & aTokenName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void Init (in nsIDOMEvent event); */
NS_IMETHODIMP nsDOMSmartCardEvent::Init(nsIDOMEvent *event)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMSmartCardEvent_h__ */
