/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM /jds/packages/BUILD/SUNWfirefox-10.0.2/firefox/dom/interfaces/xul/nsIDOMXULCommandEvent.idl
 */

#ifndef __gen_nsIDOMXULCommandEvent_h__
#define __gen_nsIDOMXULCommandEvent_h__


#ifndef __gen_nsIDOMUIEvent_h__
#include "nsIDOMUIEvent.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMXULCommandEvent */
#define NS_IDOMXULCOMMANDEVENT_IID_STR "980999ae-7702-4c8f-944d-77db4e99583c"

#define NS_IDOMXULCOMMANDEVENT_IID \
  {0x980999ae, 0x7702, 0x4c8f, \
    { 0x94, 0x4d, 0x77, 0xdb, 0x4e, 0x99, 0x58, 0x3c }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMXULCommandEvent : public nsIDOMUIEvent {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMXULCOMMANDEVENT_IID)

  /* readonly attribute boolean ctrlKey; */
  NS_SCRIPTABLE NS_IMETHOD GetCtrlKey(bool *aCtrlKey) = 0;

  /* readonly attribute boolean shiftKey; */
  NS_SCRIPTABLE NS_IMETHOD GetShiftKey(bool *aShiftKey) = 0;

  /* readonly attribute boolean altKey; */
  NS_SCRIPTABLE NS_IMETHOD GetAltKey(bool *aAltKey) = 0;

  /* readonly attribute boolean metaKey; */
  NS_SCRIPTABLE NS_IMETHOD GetMetaKey(bool *aMetaKey) = 0;

  /* readonly attribute nsIDOMEvent sourceEvent; */
  NS_SCRIPTABLE NS_IMETHOD GetSourceEvent(nsIDOMEvent * *aSourceEvent) = 0;

  /* void initCommandEvent (in DOMString typeArg, in boolean canBubbleArg, in boolean cancelableArg, in nsIDOMWindow viewArg, in long detailArg, in boolean ctrlKeyArg, in boolean altKeyArg, in boolean shiftKeyArg, in boolean metaKeyArg, in nsIDOMEvent sourceEvent); */
  NS_SCRIPTABLE NS_IMETHOD InitCommandEvent(const nsAString & typeArg, bool canBubbleArg, bool cancelableArg, nsIDOMWindow *viewArg, PRInt32 detailArg, bool ctrlKeyArg, bool altKeyArg, bool shiftKeyArg, bool metaKeyArg, nsIDOMEvent *sourceEvent) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMXULCommandEvent, NS_IDOMXULCOMMANDEVENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMXULCOMMANDEVENT \
  NS_SCRIPTABLE NS_IMETHOD GetCtrlKey(bool *aCtrlKey); \
  NS_SCRIPTABLE NS_IMETHOD GetShiftKey(bool *aShiftKey); \
  NS_SCRIPTABLE NS_IMETHOD GetAltKey(bool *aAltKey); \
  NS_SCRIPTABLE NS_IMETHOD GetMetaKey(bool *aMetaKey); \
  NS_SCRIPTABLE NS_IMETHOD GetSourceEvent(nsIDOMEvent * *aSourceEvent); \
  NS_SCRIPTABLE NS_IMETHOD InitCommandEvent(const nsAString & typeArg, bool canBubbleArg, bool cancelableArg, nsIDOMWindow *viewArg, PRInt32 detailArg, bool ctrlKeyArg, bool altKeyArg, bool shiftKeyArg, bool metaKeyArg, nsIDOMEvent *sourceEvent); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMXULCOMMANDEVENT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetCtrlKey(bool *aCtrlKey) { return _to GetCtrlKey(aCtrlKey); } \
  NS_SCRIPTABLE NS_IMETHOD GetShiftKey(bool *aShiftKey) { return _to GetShiftKey(aShiftKey); } \
  NS_SCRIPTABLE NS_IMETHOD GetAltKey(bool *aAltKey) { return _to GetAltKey(aAltKey); } \
  NS_SCRIPTABLE NS_IMETHOD GetMetaKey(bool *aMetaKey) { return _to GetMetaKey(aMetaKey); } \
  NS_SCRIPTABLE NS_IMETHOD GetSourceEvent(nsIDOMEvent * *aSourceEvent) { return _to GetSourceEvent(aSourceEvent); } \
  NS_SCRIPTABLE NS_IMETHOD InitCommandEvent(const nsAString & typeArg, bool canBubbleArg, bool cancelableArg, nsIDOMWindow *viewArg, PRInt32 detailArg, bool ctrlKeyArg, bool altKeyArg, bool shiftKeyArg, bool metaKeyArg, nsIDOMEvent *sourceEvent) { return _to InitCommandEvent(typeArg, canBubbleArg, cancelableArg, viewArg, detailArg, ctrlKeyArg, altKeyArg, shiftKeyArg, metaKeyArg, sourceEvent); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMXULCOMMANDEVENT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetCtrlKey(bool *aCtrlKey) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCtrlKey(aCtrlKey); } \
  NS_SCRIPTABLE NS_IMETHOD GetShiftKey(bool *aShiftKey) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetShiftKey(aShiftKey); } \
  NS_SCRIPTABLE NS_IMETHOD GetAltKey(bool *aAltKey) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAltKey(aAltKey); } \
  NS_SCRIPTABLE NS_IMETHOD GetMetaKey(bool *aMetaKey) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMetaKey(aMetaKey); } \
  NS_SCRIPTABLE NS_IMETHOD GetSourceEvent(nsIDOMEvent * *aSourceEvent) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSourceEvent(aSourceEvent); } \
  NS_SCRIPTABLE NS_IMETHOD InitCommandEvent(const nsAString & typeArg, bool canBubbleArg, bool cancelableArg, nsIDOMWindow *viewArg, PRInt32 detailArg, bool ctrlKeyArg, bool altKeyArg, bool shiftKeyArg, bool metaKeyArg, nsIDOMEvent *sourceEvent) { return !_to ? NS_ERROR_NULL_POINTER : _to->InitCommandEvent(typeArg, canBubbleArg, cancelableArg, viewArg, detailArg, ctrlKeyArg, altKeyArg, shiftKeyArg, metaKeyArg, sourceEvent); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMXULCommandEvent : public nsIDOMXULCommandEvent
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMXULCOMMANDEVENT

  nsDOMXULCommandEvent();

private:
  ~nsDOMXULCommandEvent();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMXULCommandEvent, nsIDOMXULCommandEvent)

nsDOMXULCommandEvent::nsDOMXULCommandEvent()
{
  /* member initializers and constructor code */
}

nsDOMXULCommandEvent::~nsDOMXULCommandEvent()
{
  /* destructor code */
}

/* readonly attribute boolean ctrlKey; */
NS_IMETHODIMP nsDOMXULCommandEvent::GetCtrlKey(bool *aCtrlKey)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean shiftKey; */
NS_IMETHODIMP nsDOMXULCommandEvent::GetShiftKey(bool *aShiftKey)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean altKey; */
NS_IMETHODIMP nsDOMXULCommandEvent::GetAltKey(bool *aAltKey)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean metaKey; */
NS_IMETHODIMP nsDOMXULCommandEvent::GetMetaKey(bool *aMetaKey)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMEvent sourceEvent; */
NS_IMETHODIMP nsDOMXULCommandEvent::GetSourceEvent(nsIDOMEvent * *aSourceEvent)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void initCommandEvent (in DOMString typeArg, in boolean canBubbleArg, in boolean cancelableArg, in nsIDOMWindow viewArg, in long detailArg, in boolean ctrlKeyArg, in boolean altKeyArg, in boolean shiftKeyArg, in boolean metaKeyArg, in nsIDOMEvent sourceEvent); */
NS_IMETHODIMP nsDOMXULCommandEvent::InitCommandEvent(const nsAString & typeArg, bool canBubbleArg, bool cancelableArg, nsIDOMWindow *viewArg, PRInt32 detailArg, bool ctrlKeyArg, bool altKeyArg, bool shiftKeyArg, bool metaKeyArg, nsIDOMEvent *sourceEvent)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMXULCommandEvent_h__ */
