/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM /jds/packages/BUILD/SUNWfirefox-10.0.2/firefox/dom/interfaces/events/nsIDOMCustomEvent.idl
 */

#ifndef __gen_nsIDOMCustomEvent_h__
#define __gen_nsIDOMCustomEvent_h__


#ifndef __gen_nsIDOMEvent_h__
#include "nsIDOMEvent.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIVariant; /* forward declaration */


/* starting interface:    nsIDOMCustomEvent */
#define NS_IDOMCUSTOMEVENT_IID_STR "eee65f98-bb6f-489c-b7e3-40e5f0c90645"

#define NS_IDOMCUSTOMEVENT_IID \
  {0xeee65f98, 0xbb6f, 0x489c, \
    { 0xb7, 0xe3, 0x40, 0xe5, 0xf0, 0xc9, 0x06, 0x45 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMCustomEvent : public nsIDOMEvent {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMCUSTOMEVENT_IID)

  /* readonly attribute nsIVariant detail; */
  NS_SCRIPTABLE NS_IMETHOD GetDetail(nsIVariant * *aDetail) = 0;

  /* void initCustomEvent (in DOMString typeArg, in boolean canBubbleArg, in boolean cancelableArg, in nsIVariant detailArg); */
  NS_SCRIPTABLE NS_IMETHOD InitCustomEvent(const nsAString & typeArg, bool canBubbleArg, bool cancelableArg, nsIVariant *detailArg) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMCustomEvent, NS_IDOMCUSTOMEVENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMCUSTOMEVENT \
  NS_SCRIPTABLE NS_IMETHOD GetDetail(nsIVariant * *aDetail); \
  NS_SCRIPTABLE NS_IMETHOD InitCustomEvent(const nsAString & typeArg, bool canBubbleArg, bool cancelableArg, nsIVariant *detailArg); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMCUSTOMEVENT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetDetail(nsIVariant * *aDetail) { return _to GetDetail(aDetail); } \
  NS_SCRIPTABLE NS_IMETHOD InitCustomEvent(const nsAString & typeArg, bool canBubbleArg, bool cancelableArg, nsIVariant *detailArg) { return _to InitCustomEvent(typeArg, canBubbleArg, cancelableArg, detailArg); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMCUSTOMEVENT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetDetail(nsIVariant * *aDetail) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDetail(aDetail); } \
  NS_SCRIPTABLE NS_IMETHOD InitCustomEvent(const nsAString & typeArg, bool canBubbleArg, bool cancelableArg, nsIVariant *detailArg) { return !_to ? NS_ERROR_NULL_POINTER : _to->InitCustomEvent(typeArg, canBubbleArg, cancelableArg, detailArg); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMCustomEvent : public nsIDOMCustomEvent
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMCUSTOMEVENT

  nsDOMCustomEvent();

private:
  ~nsDOMCustomEvent();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMCustomEvent, nsIDOMCustomEvent)

nsDOMCustomEvent::nsDOMCustomEvent()
{
  /* member initializers and constructor code */
}

nsDOMCustomEvent::~nsDOMCustomEvent()
{
  /* destructor code */
}

/* readonly attribute nsIVariant detail; */
NS_IMETHODIMP nsDOMCustomEvent::GetDetail(nsIVariant * *aDetail)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void initCustomEvent (in DOMString typeArg, in boolean canBubbleArg, in boolean cancelableArg, in nsIVariant detailArg); */
NS_IMETHODIMP nsDOMCustomEvent::InitCustomEvent(const nsAString & typeArg, bool canBubbleArg, bool cancelableArg, nsIVariant *detailArg)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMCustomEvent_h__ */
