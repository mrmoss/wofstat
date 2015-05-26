/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM /jds/packages/BUILD/SUNWfirefox-10.0.2/firefox/dom/interfaces/events/nsIDOMPopupBlockedEvent.idl
 */

#ifndef __gen_nsIDOMPopupBlockedEvent_h__
#define __gen_nsIDOMPopupBlockedEvent_h__


#ifndef __gen_nsIDOMEvent_h__
#include "nsIDOMEvent.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIURI; /* forward declaration */


/* starting interface:    nsIDOMPopupBlockedEvent */
#define NS_IDOMPOPUPBLOCKEDEVENT_IID_STR "853828af-eda7-459a-be7f-9011c20394ae"

#define NS_IDOMPOPUPBLOCKEDEVENT_IID \
  {0x853828af, 0xeda7, 0x459a, \
    { 0xbe, 0x7f, 0x90, 0x11, 0xc2, 0x03, 0x94, 0xae }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMPopupBlockedEvent : public nsIDOMEvent {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMPOPUPBLOCKEDEVENT_IID)

  /* readonly attribute nsIDOMWindow requestingWindow; */
  NS_SCRIPTABLE NS_IMETHOD GetRequestingWindow(nsIDOMWindow * *aRequestingWindow) = 0;

  /* readonly attribute nsIURI popupWindowURI; */
  NS_SCRIPTABLE NS_IMETHOD GetPopupWindowURI(nsIURI * *aPopupWindowURI) = 0;

  /* readonly attribute DOMString popupWindowFeatures; */
  NS_SCRIPTABLE NS_IMETHOD GetPopupWindowFeatures(nsAString & aPopupWindowFeatures) = 0;

  /* readonly attribute DOMString popupWindowName; */
  NS_SCRIPTABLE NS_IMETHOD GetPopupWindowName(nsAString & aPopupWindowName) = 0;

  /* void initPopupBlockedEvent (in DOMString typeArg, in boolean canBubbleArg, in boolean cancelableArg, in nsIDOMWindow requestingWindow, in nsIURI popupWindowURI, in DOMString popupWindowName, in DOMString popupWindowFeatures); */
  NS_SCRIPTABLE NS_IMETHOD InitPopupBlockedEvent(const nsAString & typeArg, bool canBubbleArg, bool cancelableArg, nsIDOMWindow *requestingWindow, nsIURI *popupWindowURI, const nsAString & popupWindowName, const nsAString & popupWindowFeatures) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMPopupBlockedEvent, NS_IDOMPOPUPBLOCKEDEVENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMPOPUPBLOCKEDEVENT \
  NS_SCRIPTABLE NS_IMETHOD GetRequestingWindow(nsIDOMWindow * *aRequestingWindow); \
  NS_SCRIPTABLE NS_IMETHOD GetPopupWindowURI(nsIURI * *aPopupWindowURI); \
  NS_SCRIPTABLE NS_IMETHOD GetPopupWindowFeatures(nsAString & aPopupWindowFeatures); \
  NS_SCRIPTABLE NS_IMETHOD GetPopupWindowName(nsAString & aPopupWindowName); \
  NS_SCRIPTABLE NS_IMETHOD InitPopupBlockedEvent(const nsAString & typeArg, bool canBubbleArg, bool cancelableArg, nsIDOMWindow *requestingWindow, nsIURI *popupWindowURI, const nsAString & popupWindowName, const nsAString & popupWindowFeatures); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMPOPUPBLOCKEDEVENT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetRequestingWindow(nsIDOMWindow * *aRequestingWindow) { return _to GetRequestingWindow(aRequestingWindow); } \
  NS_SCRIPTABLE NS_IMETHOD GetPopupWindowURI(nsIURI * *aPopupWindowURI) { return _to GetPopupWindowURI(aPopupWindowURI); } \
  NS_SCRIPTABLE NS_IMETHOD GetPopupWindowFeatures(nsAString & aPopupWindowFeatures) { return _to GetPopupWindowFeatures(aPopupWindowFeatures); } \
  NS_SCRIPTABLE NS_IMETHOD GetPopupWindowName(nsAString & aPopupWindowName) { return _to GetPopupWindowName(aPopupWindowName); } \
  NS_SCRIPTABLE NS_IMETHOD InitPopupBlockedEvent(const nsAString & typeArg, bool canBubbleArg, bool cancelableArg, nsIDOMWindow *requestingWindow, nsIURI *popupWindowURI, const nsAString & popupWindowName, const nsAString & popupWindowFeatures) { return _to InitPopupBlockedEvent(typeArg, canBubbleArg, cancelableArg, requestingWindow, popupWindowURI, popupWindowName, popupWindowFeatures); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMPOPUPBLOCKEDEVENT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetRequestingWindow(nsIDOMWindow * *aRequestingWindow) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetRequestingWindow(aRequestingWindow); } \
  NS_SCRIPTABLE NS_IMETHOD GetPopupWindowURI(nsIURI * *aPopupWindowURI) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPopupWindowURI(aPopupWindowURI); } \
  NS_SCRIPTABLE NS_IMETHOD GetPopupWindowFeatures(nsAString & aPopupWindowFeatures) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPopupWindowFeatures(aPopupWindowFeatures); } \
  NS_SCRIPTABLE NS_IMETHOD GetPopupWindowName(nsAString & aPopupWindowName) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPopupWindowName(aPopupWindowName); } \
  NS_SCRIPTABLE NS_IMETHOD InitPopupBlockedEvent(const nsAString & typeArg, bool canBubbleArg, bool cancelableArg, nsIDOMWindow *requestingWindow, nsIURI *popupWindowURI, const nsAString & popupWindowName, const nsAString & popupWindowFeatures) { return !_to ? NS_ERROR_NULL_POINTER : _to->InitPopupBlockedEvent(typeArg, canBubbleArg, cancelableArg, requestingWindow, popupWindowURI, popupWindowName, popupWindowFeatures); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMPopupBlockedEvent : public nsIDOMPopupBlockedEvent
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMPOPUPBLOCKEDEVENT

  nsDOMPopupBlockedEvent();

private:
  ~nsDOMPopupBlockedEvent();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMPopupBlockedEvent, nsIDOMPopupBlockedEvent)

nsDOMPopupBlockedEvent::nsDOMPopupBlockedEvent()
{
  /* member initializers and constructor code */
}

nsDOMPopupBlockedEvent::~nsDOMPopupBlockedEvent()
{
  /* destructor code */
}

/* readonly attribute nsIDOMWindow requestingWindow; */
NS_IMETHODIMP nsDOMPopupBlockedEvent::GetRequestingWindow(nsIDOMWindow * *aRequestingWindow)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIURI popupWindowURI; */
NS_IMETHODIMP nsDOMPopupBlockedEvent::GetPopupWindowURI(nsIURI * *aPopupWindowURI)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute DOMString popupWindowFeatures; */
NS_IMETHODIMP nsDOMPopupBlockedEvent::GetPopupWindowFeatures(nsAString & aPopupWindowFeatures)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute DOMString popupWindowName; */
NS_IMETHODIMP nsDOMPopupBlockedEvent::GetPopupWindowName(nsAString & aPopupWindowName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void initPopupBlockedEvent (in DOMString typeArg, in boolean canBubbleArg, in boolean cancelableArg, in nsIDOMWindow requestingWindow, in nsIURI popupWindowURI, in DOMString popupWindowName, in DOMString popupWindowFeatures); */
NS_IMETHODIMP nsDOMPopupBlockedEvent::InitPopupBlockedEvent(const nsAString & typeArg, bool canBubbleArg, bool cancelableArg, nsIDOMWindow *requestingWindow, nsIURI *popupWindowURI, const nsAString & popupWindowName, const nsAString & popupWindowFeatures)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMPopupBlockedEvent_h__ */
