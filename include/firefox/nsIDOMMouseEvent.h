/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM /jds/packages/BUILD/SUNWfirefox-10.0.2/firefox/dom/interfaces/events/nsIDOMMouseEvent.idl
 */

#ifndef __gen_nsIDOMMouseEvent_h__
#define __gen_nsIDOMMouseEvent_h__


#ifndef __gen_nsIDOMUIEvent_h__
#include "nsIDOMUIEvent.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMMouseEvent */
#define NS_IDOMMOUSEEVENT_IID_STR "7f57aa45-6792-4d8b-ba5b-201533cf0b2f"

#define NS_IDOMMOUSEEVENT_IID \
  {0x7f57aa45, 0x6792, 0x4d8b, \
    { 0xba, 0x5b, 0x20, 0x15, 0x33, 0xcf, 0x0b, 0x2f }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMMouseEvent : public nsIDOMUIEvent {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMMOUSEEVENT_IID)

  /* readonly attribute long screenX; */
  NS_SCRIPTABLE NS_IMETHOD GetScreenX(PRInt32 *aScreenX) = 0;

  /* readonly attribute long screenY; */
  NS_SCRIPTABLE NS_IMETHOD GetScreenY(PRInt32 *aScreenY) = 0;

  /* readonly attribute long clientX; */
  NS_SCRIPTABLE NS_IMETHOD GetClientX(PRInt32 *aClientX) = 0;

  /* readonly attribute long clientY; */
  NS_SCRIPTABLE NS_IMETHOD GetClientY(PRInt32 *aClientY) = 0;

  /* readonly attribute boolean ctrlKey; */
  NS_SCRIPTABLE NS_IMETHOD GetCtrlKey(bool *aCtrlKey) = 0;

  /* readonly attribute boolean shiftKey; */
  NS_SCRIPTABLE NS_IMETHOD GetShiftKey(bool *aShiftKey) = 0;

  /* readonly attribute boolean altKey; */
  NS_SCRIPTABLE NS_IMETHOD GetAltKey(bool *aAltKey) = 0;

  /* readonly attribute boolean metaKey; */
  NS_SCRIPTABLE NS_IMETHOD GetMetaKey(bool *aMetaKey) = 0;

  /* readonly attribute unsigned short button; */
  NS_SCRIPTABLE NS_IMETHOD GetButton(PRUint16 *aButton) = 0;

  /* readonly attribute nsIDOMEventTarget relatedTarget; */
  NS_SCRIPTABLE NS_IMETHOD GetRelatedTarget(nsIDOMEventTarget * *aRelatedTarget) = 0;

  /* void initMouseEvent (in DOMString typeArg, in boolean canBubbleArg, in boolean cancelableArg, in nsIDOMWindow viewArg, in long detailArg, in long screenXArg, in long screenYArg, in long clientXArg, in long clientYArg, in boolean ctrlKeyArg, in boolean altKeyArg, in boolean shiftKeyArg, in boolean metaKeyArg, in unsigned short buttonArg, in nsIDOMEventTarget relatedTargetArg); */
  NS_SCRIPTABLE NS_IMETHOD InitMouseEvent(const nsAString & typeArg, bool canBubbleArg, bool cancelableArg, nsIDOMWindow *viewArg, PRInt32 detailArg, PRInt32 screenXArg, PRInt32 screenYArg, PRInt32 clientXArg, PRInt32 clientYArg, bool ctrlKeyArg, bool altKeyArg, bool shiftKeyArg, bool metaKeyArg, PRUint16 buttonArg, nsIDOMEventTarget *relatedTargetArg) = 0;

  /* readonly attribute float mozPressure; */
  NS_SCRIPTABLE NS_IMETHOD GetMozPressure(float *aMozPressure) = 0;

  enum { MOZ_SOURCE_UNKNOWN = 0U };

  enum { MOZ_SOURCE_MOUSE = 1U };

  enum { MOZ_SOURCE_PEN = 2U };

  enum { MOZ_SOURCE_ERASER = 3U };

  enum { MOZ_SOURCE_CURSOR = 4U };

  enum { MOZ_SOURCE_TOUCH = 5U };

  enum { MOZ_SOURCE_KEYBOARD = 6U };

  /* readonly attribute unsigned short mozInputSource; */
  NS_SCRIPTABLE NS_IMETHOD GetMozInputSource(PRUint16 *aMozInputSource) = 0;

  /* void initNSMouseEvent (in DOMString typeArg, in boolean canBubbleArg, in boolean cancelableArg, in nsIDOMWindow viewArg, in long detailArg, in long screenXArg, in long screenYArg, in long clientXArg, in long clientYArg, in boolean ctrlKeyArg, in boolean altKeyArg, in boolean shiftKeyArg, in boolean metaKeyArg, in unsigned short buttonArg, in nsIDOMEventTarget relatedTargetArg, in float pressure, in unsigned short inputSourceArg); */
  NS_SCRIPTABLE NS_IMETHOD InitNSMouseEvent(const nsAString & typeArg, bool canBubbleArg, bool cancelableArg, nsIDOMWindow *viewArg, PRInt32 detailArg, PRInt32 screenXArg, PRInt32 screenYArg, PRInt32 clientXArg, PRInt32 clientYArg, bool ctrlKeyArg, bool altKeyArg, bool shiftKeyArg, bool metaKeyArg, PRUint16 buttonArg, nsIDOMEventTarget *relatedTargetArg, float pressure, PRUint16 inputSourceArg) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMMouseEvent, NS_IDOMMOUSEEVENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMMOUSEEVENT \
  NS_SCRIPTABLE NS_IMETHOD GetScreenX(PRInt32 *aScreenX); \
  NS_SCRIPTABLE NS_IMETHOD GetScreenY(PRInt32 *aScreenY); \
  NS_SCRIPTABLE NS_IMETHOD GetClientX(PRInt32 *aClientX); \
  NS_SCRIPTABLE NS_IMETHOD GetClientY(PRInt32 *aClientY); \
  NS_SCRIPTABLE NS_IMETHOD GetCtrlKey(bool *aCtrlKey); \
  NS_SCRIPTABLE NS_IMETHOD GetShiftKey(bool *aShiftKey); \
  NS_SCRIPTABLE NS_IMETHOD GetAltKey(bool *aAltKey); \
  NS_SCRIPTABLE NS_IMETHOD GetMetaKey(bool *aMetaKey); \
  NS_SCRIPTABLE NS_IMETHOD GetButton(PRUint16 *aButton); \
  NS_SCRIPTABLE NS_IMETHOD GetRelatedTarget(nsIDOMEventTarget * *aRelatedTarget); \
  NS_SCRIPTABLE NS_IMETHOD InitMouseEvent(const nsAString & typeArg, bool canBubbleArg, bool cancelableArg, nsIDOMWindow *viewArg, PRInt32 detailArg, PRInt32 screenXArg, PRInt32 screenYArg, PRInt32 clientXArg, PRInt32 clientYArg, bool ctrlKeyArg, bool altKeyArg, bool shiftKeyArg, bool metaKeyArg, PRUint16 buttonArg, nsIDOMEventTarget *relatedTargetArg); \
  NS_SCRIPTABLE NS_IMETHOD GetMozPressure(float *aMozPressure); \
  NS_SCRIPTABLE NS_IMETHOD GetMozInputSource(PRUint16 *aMozInputSource); \
  NS_SCRIPTABLE NS_IMETHOD InitNSMouseEvent(const nsAString & typeArg, bool canBubbleArg, bool cancelableArg, nsIDOMWindow *viewArg, PRInt32 detailArg, PRInt32 screenXArg, PRInt32 screenYArg, PRInt32 clientXArg, PRInt32 clientYArg, bool ctrlKeyArg, bool altKeyArg, bool shiftKeyArg, bool metaKeyArg, PRUint16 buttonArg, nsIDOMEventTarget *relatedTargetArg, float pressure, PRUint16 inputSourceArg); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMMOUSEEVENT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetScreenX(PRInt32 *aScreenX) { return _to GetScreenX(aScreenX); } \
  NS_SCRIPTABLE NS_IMETHOD GetScreenY(PRInt32 *aScreenY) { return _to GetScreenY(aScreenY); } \
  NS_SCRIPTABLE NS_IMETHOD GetClientX(PRInt32 *aClientX) { return _to GetClientX(aClientX); } \
  NS_SCRIPTABLE NS_IMETHOD GetClientY(PRInt32 *aClientY) { return _to GetClientY(aClientY); } \
  NS_SCRIPTABLE NS_IMETHOD GetCtrlKey(bool *aCtrlKey) { return _to GetCtrlKey(aCtrlKey); } \
  NS_SCRIPTABLE NS_IMETHOD GetShiftKey(bool *aShiftKey) { return _to GetShiftKey(aShiftKey); } \
  NS_SCRIPTABLE NS_IMETHOD GetAltKey(bool *aAltKey) { return _to GetAltKey(aAltKey); } \
  NS_SCRIPTABLE NS_IMETHOD GetMetaKey(bool *aMetaKey) { return _to GetMetaKey(aMetaKey); } \
  NS_SCRIPTABLE NS_IMETHOD GetButton(PRUint16 *aButton) { return _to GetButton(aButton); } \
  NS_SCRIPTABLE NS_IMETHOD GetRelatedTarget(nsIDOMEventTarget * *aRelatedTarget) { return _to GetRelatedTarget(aRelatedTarget); } \
  NS_SCRIPTABLE NS_IMETHOD InitMouseEvent(const nsAString & typeArg, bool canBubbleArg, bool cancelableArg, nsIDOMWindow *viewArg, PRInt32 detailArg, PRInt32 screenXArg, PRInt32 screenYArg, PRInt32 clientXArg, PRInt32 clientYArg, bool ctrlKeyArg, bool altKeyArg, bool shiftKeyArg, bool metaKeyArg, PRUint16 buttonArg, nsIDOMEventTarget *relatedTargetArg) { return _to InitMouseEvent(typeArg, canBubbleArg, cancelableArg, viewArg, detailArg, screenXArg, screenYArg, clientXArg, clientYArg, ctrlKeyArg, altKeyArg, shiftKeyArg, metaKeyArg, buttonArg, relatedTargetArg); } \
  NS_SCRIPTABLE NS_IMETHOD GetMozPressure(float *aMozPressure) { return _to GetMozPressure(aMozPressure); } \
  NS_SCRIPTABLE NS_IMETHOD GetMozInputSource(PRUint16 *aMozInputSource) { return _to GetMozInputSource(aMozInputSource); } \
  NS_SCRIPTABLE NS_IMETHOD InitNSMouseEvent(const nsAString & typeArg, bool canBubbleArg, bool cancelableArg, nsIDOMWindow *viewArg, PRInt32 detailArg, PRInt32 screenXArg, PRInt32 screenYArg, PRInt32 clientXArg, PRInt32 clientYArg, bool ctrlKeyArg, bool altKeyArg, bool shiftKeyArg, bool metaKeyArg, PRUint16 buttonArg, nsIDOMEventTarget *relatedTargetArg, float pressure, PRUint16 inputSourceArg) { return _to InitNSMouseEvent(typeArg, canBubbleArg, cancelableArg, viewArg, detailArg, screenXArg, screenYArg, clientXArg, clientYArg, ctrlKeyArg, altKeyArg, shiftKeyArg, metaKeyArg, buttonArg, relatedTargetArg, pressure, inputSourceArg); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMMOUSEEVENT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetScreenX(PRInt32 *aScreenX) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetScreenX(aScreenX); } \
  NS_SCRIPTABLE NS_IMETHOD GetScreenY(PRInt32 *aScreenY) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetScreenY(aScreenY); } \
  NS_SCRIPTABLE NS_IMETHOD GetClientX(PRInt32 *aClientX) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetClientX(aClientX); } \
  NS_SCRIPTABLE NS_IMETHOD GetClientY(PRInt32 *aClientY) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetClientY(aClientY); } \
  NS_SCRIPTABLE NS_IMETHOD GetCtrlKey(bool *aCtrlKey) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCtrlKey(aCtrlKey); } \
  NS_SCRIPTABLE NS_IMETHOD GetShiftKey(bool *aShiftKey) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetShiftKey(aShiftKey); } \
  NS_SCRIPTABLE NS_IMETHOD GetAltKey(bool *aAltKey) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAltKey(aAltKey); } \
  NS_SCRIPTABLE NS_IMETHOD GetMetaKey(bool *aMetaKey) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMetaKey(aMetaKey); } \
  NS_SCRIPTABLE NS_IMETHOD GetButton(PRUint16 *aButton) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetButton(aButton); } \
  NS_SCRIPTABLE NS_IMETHOD GetRelatedTarget(nsIDOMEventTarget * *aRelatedTarget) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetRelatedTarget(aRelatedTarget); } \
  NS_SCRIPTABLE NS_IMETHOD InitMouseEvent(const nsAString & typeArg, bool canBubbleArg, bool cancelableArg, nsIDOMWindow *viewArg, PRInt32 detailArg, PRInt32 screenXArg, PRInt32 screenYArg, PRInt32 clientXArg, PRInt32 clientYArg, bool ctrlKeyArg, bool altKeyArg, bool shiftKeyArg, bool metaKeyArg, PRUint16 buttonArg, nsIDOMEventTarget *relatedTargetArg) { return !_to ? NS_ERROR_NULL_POINTER : _to->InitMouseEvent(typeArg, canBubbleArg, cancelableArg, viewArg, detailArg, screenXArg, screenYArg, clientXArg, clientYArg, ctrlKeyArg, altKeyArg, shiftKeyArg, metaKeyArg, buttonArg, relatedTargetArg); } \
  NS_SCRIPTABLE NS_IMETHOD GetMozPressure(float *aMozPressure) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMozPressure(aMozPressure); } \
  NS_SCRIPTABLE NS_IMETHOD GetMozInputSource(PRUint16 *aMozInputSource) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMozInputSource(aMozInputSource); } \
  NS_SCRIPTABLE NS_IMETHOD InitNSMouseEvent(const nsAString & typeArg, bool canBubbleArg, bool cancelableArg, nsIDOMWindow *viewArg, PRInt32 detailArg, PRInt32 screenXArg, PRInt32 screenYArg, PRInt32 clientXArg, PRInt32 clientYArg, bool ctrlKeyArg, bool altKeyArg, bool shiftKeyArg, bool metaKeyArg, PRUint16 buttonArg, nsIDOMEventTarget *relatedTargetArg, float pressure, PRUint16 inputSourceArg) { return !_to ? NS_ERROR_NULL_POINTER : _to->InitNSMouseEvent(typeArg, canBubbleArg, cancelableArg, viewArg, detailArg, screenXArg, screenYArg, clientXArg, clientYArg, ctrlKeyArg, altKeyArg, shiftKeyArg, metaKeyArg, buttonArg, relatedTargetArg, pressure, inputSourceArg); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMMouseEvent : public nsIDOMMouseEvent
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMMOUSEEVENT

  nsDOMMouseEvent();

private:
  ~nsDOMMouseEvent();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMMouseEvent, nsIDOMMouseEvent)

nsDOMMouseEvent::nsDOMMouseEvent()
{
  /* member initializers and constructor code */
}

nsDOMMouseEvent::~nsDOMMouseEvent()
{
  /* destructor code */
}

/* readonly attribute long screenX; */
NS_IMETHODIMP nsDOMMouseEvent::GetScreenX(PRInt32 *aScreenX)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long screenY; */
NS_IMETHODIMP nsDOMMouseEvent::GetScreenY(PRInt32 *aScreenY)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long clientX; */
NS_IMETHODIMP nsDOMMouseEvent::GetClientX(PRInt32 *aClientX)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long clientY; */
NS_IMETHODIMP nsDOMMouseEvent::GetClientY(PRInt32 *aClientY)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean ctrlKey; */
NS_IMETHODIMP nsDOMMouseEvent::GetCtrlKey(bool *aCtrlKey)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean shiftKey; */
NS_IMETHODIMP nsDOMMouseEvent::GetShiftKey(bool *aShiftKey)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean altKey; */
NS_IMETHODIMP nsDOMMouseEvent::GetAltKey(bool *aAltKey)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean metaKey; */
NS_IMETHODIMP nsDOMMouseEvent::GetMetaKey(bool *aMetaKey)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned short button; */
NS_IMETHODIMP nsDOMMouseEvent::GetButton(PRUint16 *aButton)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMEventTarget relatedTarget; */
NS_IMETHODIMP nsDOMMouseEvent::GetRelatedTarget(nsIDOMEventTarget * *aRelatedTarget)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void initMouseEvent (in DOMString typeArg, in boolean canBubbleArg, in boolean cancelableArg, in nsIDOMWindow viewArg, in long detailArg, in long screenXArg, in long screenYArg, in long clientXArg, in long clientYArg, in boolean ctrlKeyArg, in boolean altKeyArg, in boolean shiftKeyArg, in boolean metaKeyArg, in unsigned short buttonArg, in nsIDOMEventTarget relatedTargetArg); */
NS_IMETHODIMP nsDOMMouseEvent::InitMouseEvent(const nsAString & typeArg, bool canBubbleArg, bool cancelableArg, nsIDOMWindow *viewArg, PRInt32 detailArg, PRInt32 screenXArg, PRInt32 screenYArg, PRInt32 clientXArg, PRInt32 clientYArg, bool ctrlKeyArg, bool altKeyArg, bool shiftKeyArg, bool metaKeyArg, PRUint16 buttonArg, nsIDOMEventTarget *relatedTargetArg)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute float mozPressure; */
NS_IMETHODIMP nsDOMMouseEvent::GetMozPressure(float *aMozPressure)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned short mozInputSource; */
NS_IMETHODIMP nsDOMMouseEvent::GetMozInputSource(PRUint16 *aMozInputSource)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void initNSMouseEvent (in DOMString typeArg, in boolean canBubbleArg, in boolean cancelableArg, in nsIDOMWindow viewArg, in long detailArg, in long screenXArg, in long screenYArg, in long clientXArg, in long clientYArg, in boolean ctrlKeyArg, in boolean altKeyArg, in boolean shiftKeyArg, in boolean metaKeyArg, in unsigned short buttonArg, in nsIDOMEventTarget relatedTargetArg, in float pressure, in unsigned short inputSourceArg); */
NS_IMETHODIMP nsDOMMouseEvent::InitNSMouseEvent(const nsAString & typeArg, bool canBubbleArg, bool cancelableArg, nsIDOMWindow *viewArg, PRInt32 detailArg, PRInt32 screenXArg, PRInt32 screenYArg, PRInt32 clientXArg, PRInt32 clientYArg, bool ctrlKeyArg, bool altKeyArg, bool shiftKeyArg, bool metaKeyArg, PRUint16 buttonArg, nsIDOMEventTarget *relatedTargetArg, float pressure, PRUint16 inputSourceArg)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMMouseEvent_h__ */
