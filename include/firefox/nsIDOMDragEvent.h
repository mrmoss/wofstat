/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM /jds/packages/BUILD/SUNWfirefox-10.0.2/firefox/dom/interfaces/events/nsIDOMDragEvent.idl
 */

#ifndef __gen_nsIDOMDragEvent_h__
#define __gen_nsIDOMDragEvent_h__


#ifndef __gen_domstubs_h__
#include "domstubs.h"
#endif

#ifndef __gen_nsIDOMMouseEvent_h__
#include "nsIDOMMouseEvent.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMDataTransfer; /* forward declaration */


/* starting interface:    nsIDOMDragEvent */
#define NS_IDOMDRAGEVENT_IID_STR "74fb5f01-e473-4302-93f5-6f74bdaaddf2"

#define NS_IDOMDRAGEVENT_IID \
  {0x74fb5f01, 0xe473, 0x4302, \
    { 0x93, 0xf5, 0x6f, 0x74, 0xbd, 0xaa, 0xdd, 0xf2 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMDragEvent : public nsIDOMMouseEvent {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMDRAGEVENT_IID)

  /* readonly attribute nsIDOMDataTransfer dataTransfer; */
  NS_SCRIPTABLE NS_IMETHOD GetDataTransfer(nsIDOMDataTransfer * *aDataTransfer) = 0;

  /* void initDragEvent (in DOMString typeArg, in boolean canBubbleArg, in boolean cancelableArg, in nsIDOMWindow aView, in long aDetail, in long aScreenX, in long aScreenY, in long aClientX, in long aClientY, in boolean aCtrlKey, in boolean aAltKey, in boolean aShiftKey, in boolean aMetaKey, in unsigned short aButton, in nsIDOMEventTarget aRelatedTarget, in nsIDOMDataTransfer aDataTransfer); */
  NS_SCRIPTABLE NS_IMETHOD InitDragEvent(const nsAString & typeArg, bool canBubbleArg, bool cancelableArg, nsIDOMWindow *aView, PRInt32 aDetail, PRInt32 aScreenX, PRInt32 aScreenY, PRInt32 aClientX, PRInt32 aClientY, bool aCtrlKey, bool aAltKey, bool aShiftKey, bool aMetaKey, PRUint16 aButton, nsIDOMEventTarget *aRelatedTarget, nsIDOMDataTransfer *aDataTransfer) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMDragEvent, NS_IDOMDRAGEVENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMDRAGEVENT \
  NS_SCRIPTABLE NS_IMETHOD GetDataTransfer(nsIDOMDataTransfer * *aDataTransfer); \
  NS_SCRIPTABLE NS_IMETHOD InitDragEvent(const nsAString & typeArg, bool canBubbleArg, bool cancelableArg, nsIDOMWindow *aView, PRInt32 aDetail, PRInt32 aScreenX, PRInt32 aScreenY, PRInt32 aClientX, PRInt32 aClientY, bool aCtrlKey, bool aAltKey, bool aShiftKey, bool aMetaKey, PRUint16 aButton, nsIDOMEventTarget *aRelatedTarget, nsIDOMDataTransfer *aDataTransfer); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMDRAGEVENT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetDataTransfer(nsIDOMDataTransfer * *aDataTransfer) { return _to GetDataTransfer(aDataTransfer); } \
  NS_SCRIPTABLE NS_IMETHOD InitDragEvent(const nsAString & typeArg, bool canBubbleArg, bool cancelableArg, nsIDOMWindow *aView, PRInt32 aDetail, PRInt32 aScreenX, PRInt32 aScreenY, PRInt32 aClientX, PRInt32 aClientY, bool aCtrlKey, bool aAltKey, bool aShiftKey, bool aMetaKey, PRUint16 aButton, nsIDOMEventTarget *aRelatedTarget, nsIDOMDataTransfer *aDataTransfer) { return _to InitDragEvent(typeArg, canBubbleArg, cancelableArg, aView, aDetail, aScreenX, aScreenY, aClientX, aClientY, aCtrlKey, aAltKey, aShiftKey, aMetaKey, aButton, aRelatedTarget, aDataTransfer); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMDRAGEVENT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetDataTransfer(nsIDOMDataTransfer * *aDataTransfer) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDataTransfer(aDataTransfer); } \
  NS_SCRIPTABLE NS_IMETHOD InitDragEvent(const nsAString & typeArg, bool canBubbleArg, bool cancelableArg, nsIDOMWindow *aView, PRInt32 aDetail, PRInt32 aScreenX, PRInt32 aScreenY, PRInt32 aClientX, PRInt32 aClientY, bool aCtrlKey, bool aAltKey, bool aShiftKey, bool aMetaKey, PRUint16 aButton, nsIDOMEventTarget *aRelatedTarget, nsIDOMDataTransfer *aDataTransfer) { return !_to ? NS_ERROR_NULL_POINTER : _to->InitDragEvent(typeArg, canBubbleArg, cancelableArg, aView, aDetail, aScreenX, aScreenY, aClientX, aClientY, aCtrlKey, aAltKey, aShiftKey, aMetaKey, aButton, aRelatedTarget, aDataTransfer); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMDragEvent : public nsIDOMDragEvent
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMDRAGEVENT

  nsDOMDragEvent();

private:
  ~nsDOMDragEvent();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMDragEvent, nsIDOMDragEvent)

nsDOMDragEvent::nsDOMDragEvent()
{
  /* member initializers and constructor code */
}

nsDOMDragEvent::~nsDOMDragEvent()
{
  /* destructor code */
}

/* readonly attribute nsIDOMDataTransfer dataTransfer; */
NS_IMETHODIMP nsDOMDragEvent::GetDataTransfer(nsIDOMDataTransfer * *aDataTransfer)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void initDragEvent (in DOMString typeArg, in boolean canBubbleArg, in boolean cancelableArg, in nsIDOMWindow aView, in long aDetail, in long aScreenX, in long aScreenY, in long aClientX, in long aClientY, in boolean aCtrlKey, in boolean aAltKey, in boolean aShiftKey, in boolean aMetaKey, in unsigned short aButton, in nsIDOMEventTarget aRelatedTarget, in nsIDOMDataTransfer aDataTransfer); */
NS_IMETHODIMP nsDOMDragEvent::InitDragEvent(const nsAString & typeArg, bool canBubbleArg, bool cancelableArg, nsIDOMWindow *aView, PRInt32 aDetail, PRInt32 aScreenX, PRInt32 aScreenY, PRInt32 aClientX, PRInt32 aClientY, bool aCtrlKey, bool aAltKey, bool aShiftKey, bool aMetaKey, PRUint16 aButton, nsIDOMEventTarget *aRelatedTarget, nsIDOMDataTransfer *aDataTransfer)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMDragEvent_h__ */
