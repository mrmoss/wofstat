/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM /jds/packages/BUILD/SUNWfirefox-10.0.2/firefox/dom/interfaces/events/nsIDOMCloseEvent.idl
 */

#ifndef __gen_nsIDOMCloseEvent_h__
#define __gen_nsIDOMCloseEvent_h__


#ifndef __gen_nsIDOMEvent_h__
#include "nsIDOMEvent.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMCloseEvent */
#define NS_IDOMCLOSEEVENT_IID_STR "07fb24d2-a102-41a2-bdaa-eb5e0d399eba"

#define NS_IDOMCLOSEEVENT_IID \
  {0x07fb24d2, 0xa102, 0x41a2, \
    { 0xbd, 0xaa, 0xeb, 0x5e, 0x0d, 0x39, 0x9e, 0xba }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMCloseEvent : public nsIDOMEvent {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMCLOSEEVENT_IID)

  /* readonly attribute boolean wasClean; */
  NS_SCRIPTABLE NS_IMETHOD GetWasClean(bool *aWasClean) = 0;

  /* readonly attribute unsigned short code; */
  NS_SCRIPTABLE NS_IMETHOD GetCode(PRUint16 *aCode) = 0;

  /* readonly attribute DOMString reason; */
  NS_SCRIPTABLE NS_IMETHOD GetReason(nsAString & aReason) = 0;

  /* void initCloseEvent (in DOMString aType, in boolean aCanBubble, in boolean aCancelable, in boolean aWasClean, in unsigned short aReasonCode, in DOMString aReason); */
  NS_SCRIPTABLE NS_IMETHOD InitCloseEvent(const nsAString & aType, bool aCanBubble, bool aCancelable, bool aWasClean, PRUint16 aReasonCode, const nsAString & aReason) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMCloseEvent, NS_IDOMCLOSEEVENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMCLOSEEVENT \
  NS_SCRIPTABLE NS_IMETHOD GetWasClean(bool *aWasClean); \
  NS_SCRIPTABLE NS_IMETHOD GetCode(PRUint16 *aCode); \
  NS_SCRIPTABLE NS_IMETHOD GetReason(nsAString & aReason); \
  NS_SCRIPTABLE NS_IMETHOD InitCloseEvent(const nsAString & aType, bool aCanBubble, bool aCancelable, bool aWasClean, PRUint16 aReasonCode, const nsAString & aReason); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMCLOSEEVENT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetWasClean(bool *aWasClean) { return _to GetWasClean(aWasClean); } \
  NS_SCRIPTABLE NS_IMETHOD GetCode(PRUint16 *aCode) { return _to GetCode(aCode); } \
  NS_SCRIPTABLE NS_IMETHOD GetReason(nsAString & aReason) { return _to GetReason(aReason); } \
  NS_SCRIPTABLE NS_IMETHOD InitCloseEvent(const nsAString & aType, bool aCanBubble, bool aCancelable, bool aWasClean, PRUint16 aReasonCode, const nsAString & aReason) { return _to InitCloseEvent(aType, aCanBubble, aCancelable, aWasClean, aReasonCode, aReason); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMCLOSEEVENT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetWasClean(bool *aWasClean) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetWasClean(aWasClean); } \
  NS_SCRIPTABLE NS_IMETHOD GetCode(PRUint16 *aCode) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCode(aCode); } \
  NS_SCRIPTABLE NS_IMETHOD GetReason(nsAString & aReason) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetReason(aReason); } \
  NS_SCRIPTABLE NS_IMETHOD InitCloseEvent(const nsAString & aType, bool aCanBubble, bool aCancelable, bool aWasClean, PRUint16 aReasonCode, const nsAString & aReason) { return !_to ? NS_ERROR_NULL_POINTER : _to->InitCloseEvent(aType, aCanBubble, aCancelable, aWasClean, aReasonCode, aReason); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMCloseEvent : public nsIDOMCloseEvent
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMCLOSEEVENT

  nsDOMCloseEvent();

private:
  ~nsDOMCloseEvent();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMCloseEvent, nsIDOMCloseEvent)

nsDOMCloseEvent::nsDOMCloseEvent()
{
  /* member initializers and constructor code */
}

nsDOMCloseEvent::~nsDOMCloseEvent()
{
  /* destructor code */
}

/* readonly attribute boolean wasClean; */
NS_IMETHODIMP nsDOMCloseEvent::GetWasClean(bool *aWasClean)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned short code; */
NS_IMETHODIMP nsDOMCloseEvent::GetCode(PRUint16 *aCode)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute DOMString reason; */
NS_IMETHODIMP nsDOMCloseEvent::GetReason(nsAString & aReason)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void initCloseEvent (in DOMString aType, in boolean aCanBubble, in boolean aCancelable, in boolean aWasClean, in unsigned short aReasonCode, in DOMString aReason); */
NS_IMETHODIMP nsDOMCloseEvent::InitCloseEvent(const nsAString & aType, bool aCanBubble, bool aCancelable, bool aWasClean, PRUint16 aReasonCode, const nsAString & aReason)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMCloseEvent_h__ */
