/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM /jds/packages/BUILD/SUNWfirefox-10.0.2/firefox/dom/interfaces/events/nsIDOMAnimationEvent.idl
 */

#ifndef __gen_nsIDOMAnimationEvent_h__
#define __gen_nsIDOMAnimationEvent_h__


#ifndef __gen_nsIDOMEvent_h__
#include "nsIDOMEvent.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMAnimationEvent */
#define NS_IDOMANIMATIONEVENT_IID_STR "cf76ec40-85fb-4623-b637-59a50af36d60"

#define NS_IDOMANIMATIONEVENT_IID \
  {0xcf76ec40, 0x85fb, 0x4623, \
    { 0xb6, 0x37, 0x59, 0xa5, 0x0a, 0xf3, 0x6d, 0x60 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMAnimationEvent : public nsIDOMEvent {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMANIMATIONEVENT_IID)

  /* readonly attribute DOMString animationName; */
  NS_SCRIPTABLE NS_IMETHOD GetAnimationName(nsAString & aAnimationName) = 0;

  /* readonly attribute float elapsedTime; */
  NS_SCRIPTABLE NS_IMETHOD GetElapsedTime(float *aElapsedTime) = 0;

  /* void initAnimationEvent (in DOMString typeArg, in boolean canBubbleArg, in boolean cancelableArg, in DOMString propertyNameArg, in float elapsedTimeArg); */
  NS_SCRIPTABLE NS_IMETHOD InitAnimationEvent(const nsAString & typeArg, bool canBubbleArg, bool cancelableArg, const nsAString & propertyNameArg, float elapsedTimeArg) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMAnimationEvent, NS_IDOMANIMATIONEVENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMANIMATIONEVENT \
  NS_SCRIPTABLE NS_IMETHOD GetAnimationName(nsAString & aAnimationName); \
  NS_SCRIPTABLE NS_IMETHOD GetElapsedTime(float *aElapsedTime); \
  NS_SCRIPTABLE NS_IMETHOD InitAnimationEvent(const nsAString & typeArg, bool canBubbleArg, bool cancelableArg, const nsAString & propertyNameArg, float elapsedTimeArg); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMANIMATIONEVENT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetAnimationName(nsAString & aAnimationName) { return _to GetAnimationName(aAnimationName); } \
  NS_SCRIPTABLE NS_IMETHOD GetElapsedTime(float *aElapsedTime) { return _to GetElapsedTime(aElapsedTime); } \
  NS_SCRIPTABLE NS_IMETHOD InitAnimationEvent(const nsAString & typeArg, bool canBubbleArg, bool cancelableArg, const nsAString & propertyNameArg, float elapsedTimeArg) { return _to InitAnimationEvent(typeArg, canBubbleArg, cancelableArg, propertyNameArg, elapsedTimeArg); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMANIMATIONEVENT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetAnimationName(nsAString & aAnimationName) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAnimationName(aAnimationName); } \
  NS_SCRIPTABLE NS_IMETHOD GetElapsedTime(float *aElapsedTime) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetElapsedTime(aElapsedTime); } \
  NS_SCRIPTABLE NS_IMETHOD InitAnimationEvent(const nsAString & typeArg, bool canBubbleArg, bool cancelableArg, const nsAString & propertyNameArg, float elapsedTimeArg) { return !_to ? NS_ERROR_NULL_POINTER : _to->InitAnimationEvent(typeArg, canBubbleArg, cancelableArg, propertyNameArg, elapsedTimeArg); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMAnimationEvent : public nsIDOMAnimationEvent
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMANIMATIONEVENT

  nsDOMAnimationEvent();

private:
  ~nsDOMAnimationEvent();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMAnimationEvent, nsIDOMAnimationEvent)

nsDOMAnimationEvent::nsDOMAnimationEvent()
{
  /* member initializers and constructor code */
}

nsDOMAnimationEvent::~nsDOMAnimationEvent()
{
  /* destructor code */
}

/* readonly attribute DOMString animationName; */
NS_IMETHODIMP nsDOMAnimationEvent::GetAnimationName(nsAString & aAnimationName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute float elapsedTime; */
NS_IMETHODIMP nsDOMAnimationEvent::GetElapsedTime(float *aElapsedTime)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void initAnimationEvent (in DOMString typeArg, in boolean canBubbleArg, in boolean cancelableArg, in DOMString propertyNameArg, in float elapsedTimeArg); */
NS_IMETHODIMP nsDOMAnimationEvent::InitAnimationEvent(const nsAString & typeArg, bool canBubbleArg, bool cancelableArg, const nsAString & propertyNameArg, float elapsedTimeArg)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMAnimationEvent_h__ */
