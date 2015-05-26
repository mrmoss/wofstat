/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM /jds/packages/BUILD/SUNWfirefox-10.0.2/firefox/dom/interfaces/events/nsIDOMProgressEvent.idl
 */

#ifndef __gen_nsIDOMProgressEvent_h__
#define __gen_nsIDOMProgressEvent_h__


#ifndef __gen_nsIDOMEvent_h__
#include "nsIDOMEvent.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMProgressEvent */
#define NS_IDOMPROGRESSEVENT_IID_STR "2377d8a6-9e27-4eb2-a377-9910772b33d3"

#define NS_IDOMPROGRESSEVENT_IID \
  {0x2377d8a6, 0x9e27, 0x4eb2, \
    { 0xa3, 0x77, 0x99, 0x10, 0x77, 0x2b, 0x33, 0xd3 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMProgressEvent : public nsIDOMEvent {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMPROGRESSEVENT_IID)

  /* readonly attribute boolean lengthComputable; */
  NS_SCRIPTABLE NS_IMETHOD GetLengthComputable(bool *aLengthComputable) = 0;

  /* readonly attribute unsigned long long loaded; */
  NS_SCRIPTABLE NS_IMETHOD GetLoaded(PRUint64 *aLoaded) = 0;

  /* readonly attribute unsigned long long total; */
  NS_SCRIPTABLE NS_IMETHOD GetTotal(PRUint64 *aTotal) = 0;

  /* void initProgressEvent (in DOMString typeArg, in boolean canBubbleArg, in boolean cancelableArg, in boolean lengthComputableArg, in unsigned long long loadedArg, in unsigned long long totalArg); */
  NS_SCRIPTABLE NS_IMETHOD InitProgressEvent(const nsAString & typeArg, bool canBubbleArg, bool cancelableArg, bool lengthComputableArg, PRUint64 loadedArg, PRUint64 totalArg) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMProgressEvent, NS_IDOMPROGRESSEVENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMPROGRESSEVENT \
  NS_SCRIPTABLE NS_IMETHOD GetLengthComputable(bool *aLengthComputable); \
  NS_SCRIPTABLE NS_IMETHOD GetLoaded(PRUint64 *aLoaded); \
  NS_SCRIPTABLE NS_IMETHOD GetTotal(PRUint64 *aTotal); \
  NS_SCRIPTABLE NS_IMETHOD InitProgressEvent(const nsAString & typeArg, bool canBubbleArg, bool cancelableArg, bool lengthComputableArg, PRUint64 loadedArg, PRUint64 totalArg); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMPROGRESSEVENT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetLengthComputable(bool *aLengthComputable) { return _to GetLengthComputable(aLengthComputable); } \
  NS_SCRIPTABLE NS_IMETHOD GetLoaded(PRUint64 *aLoaded) { return _to GetLoaded(aLoaded); } \
  NS_SCRIPTABLE NS_IMETHOD GetTotal(PRUint64 *aTotal) { return _to GetTotal(aTotal); } \
  NS_SCRIPTABLE NS_IMETHOD InitProgressEvent(const nsAString & typeArg, bool canBubbleArg, bool cancelableArg, bool lengthComputableArg, PRUint64 loadedArg, PRUint64 totalArg) { return _to InitProgressEvent(typeArg, canBubbleArg, cancelableArg, lengthComputableArg, loadedArg, totalArg); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMPROGRESSEVENT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetLengthComputable(bool *aLengthComputable) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLengthComputable(aLengthComputable); } \
  NS_SCRIPTABLE NS_IMETHOD GetLoaded(PRUint64 *aLoaded) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLoaded(aLoaded); } \
  NS_SCRIPTABLE NS_IMETHOD GetTotal(PRUint64 *aTotal) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTotal(aTotal); } \
  NS_SCRIPTABLE NS_IMETHOD InitProgressEvent(const nsAString & typeArg, bool canBubbleArg, bool cancelableArg, bool lengthComputableArg, PRUint64 loadedArg, PRUint64 totalArg) { return !_to ? NS_ERROR_NULL_POINTER : _to->InitProgressEvent(typeArg, canBubbleArg, cancelableArg, lengthComputableArg, loadedArg, totalArg); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMProgressEvent : public nsIDOMProgressEvent
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMPROGRESSEVENT

  nsDOMProgressEvent();

private:
  ~nsDOMProgressEvent();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMProgressEvent, nsIDOMProgressEvent)

nsDOMProgressEvent::nsDOMProgressEvent()
{
  /* member initializers and constructor code */
}

nsDOMProgressEvent::~nsDOMProgressEvent()
{
  /* destructor code */
}

/* readonly attribute boolean lengthComputable; */
NS_IMETHODIMP nsDOMProgressEvent::GetLengthComputable(bool *aLengthComputable)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned long long loaded; */
NS_IMETHODIMP nsDOMProgressEvent::GetLoaded(PRUint64 *aLoaded)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned long long total; */
NS_IMETHODIMP nsDOMProgressEvent::GetTotal(PRUint64 *aTotal)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void initProgressEvent (in DOMString typeArg, in boolean canBubbleArg, in boolean cancelableArg, in boolean lengthComputableArg, in unsigned long long loadedArg, in unsigned long long totalArg); */
NS_IMETHODIMP nsDOMProgressEvent::InitProgressEvent(const nsAString & typeArg, bool canBubbleArg, bool cancelableArg, bool lengthComputableArg, PRUint64 loadedArg, PRUint64 totalArg)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMProgressEvent_h__ */
