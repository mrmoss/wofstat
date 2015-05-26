/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM /jds/packages/BUILD/SUNWfirefox-10.0.2/firefox/dom/interfaces/storage/nsIDOMStorageEvent.idl
 */

#ifndef __gen_nsIDOMStorageEvent_h__
#define __gen_nsIDOMStorageEvent_h__


#ifndef __gen_domstubs_h__
#include "domstubs.h"
#endif

#ifndef __gen_nsIDOMEvent_h__
#include "nsIDOMEvent.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMStorage; /* forward declaration */


/* starting interface:    nsIDOMStorageEvent */
#define NS_IDOMSTORAGEEVENT_IID_STR "501d7dc8-5b8b-4cce-99ad-16ed1046030a"

#define NS_IDOMSTORAGEEVENT_IID \
  {0x501d7dc8, 0x5b8b, 0x4cce, \
    { 0x99, 0xad, 0x16, 0xed, 0x10, 0x46, 0x03, 0x0a }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMStorageEvent : public nsIDOMEvent {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMSTORAGEEVENT_IID)

  /* readonly attribute DOMString key; */
  NS_SCRIPTABLE NS_IMETHOD GetKey(nsAString & aKey) = 0;

  /* readonly attribute DOMString oldValue; */
  NS_SCRIPTABLE NS_IMETHOD GetOldValue(nsAString & aOldValue) = 0;

  /* readonly attribute DOMString newValue; */
  NS_SCRIPTABLE NS_IMETHOD GetNewValue(nsAString & aNewValue) = 0;

  /* readonly attribute DOMString url; */
  NS_SCRIPTABLE NS_IMETHOD GetUrl(nsAString & aUrl) = 0;

  /* readonly attribute nsIDOMStorage storageArea; */
  NS_SCRIPTABLE NS_IMETHOD GetStorageArea(nsIDOMStorage * *aStorageArea) = 0;

  /* void initStorageEvent (in DOMString typeArg, in boolean canBubbleArg, in boolean cancelableArg, in DOMString keyArg, in DOMString oldValueArg, in DOMString newValueArg, in DOMString urlArg, in nsIDOMStorage storageAreaArg); */
  NS_SCRIPTABLE NS_IMETHOD InitStorageEvent(const nsAString & typeArg, bool canBubbleArg, bool cancelableArg, const nsAString & keyArg, const nsAString & oldValueArg, const nsAString & newValueArg, const nsAString & urlArg, nsIDOMStorage *storageAreaArg) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMStorageEvent, NS_IDOMSTORAGEEVENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMSTORAGEEVENT \
  NS_SCRIPTABLE NS_IMETHOD GetKey(nsAString & aKey); \
  NS_SCRIPTABLE NS_IMETHOD GetOldValue(nsAString & aOldValue); \
  NS_SCRIPTABLE NS_IMETHOD GetNewValue(nsAString & aNewValue); \
  NS_SCRIPTABLE NS_IMETHOD GetUrl(nsAString & aUrl); \
  NS_SCRIPTABLE NS_IMETHOD GetStorageArea(nsIDOMStorage * *aStorageArea); \
  NS_SCRIPTABLE NS_IMETHOD InitStorageEvent(const nsAString & typeArg, bool canBubbleArg, bool cancelableArg, const nsAString & keyArg, const nsAString & oldValueArg, const nsAString & newValueArg, const nsAString & urlArg, nsIDOMStorage *storageAreaArg); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMSTORAGEEVENT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetKey(nsAString & aKey) { return _to GetKey(aKey); } \
  NS_SCRIPTABLE NS_IMETHOD GetOldValue(nsAString & aOldValue) { return _to GetOldValue(aOldValue); } \
  NS_SCRIPTABLE NS_IMETHOD GetNewValue(nsAString & aNewValue) { return _to GetNewValue(aNewValue); } \
  NS_SCRIPTABLE NS_IMETHOD GetUrl(nsAString & aUrl) { return _to GetUrl(aUrl); } \
  NS_SCRIPTABLE NS_IMETHOD GetStorageArea(nsIDOMStorage * *aStorageArea) { return _to GetStorageArea(aStorageArea); } \
  NS_SCRIPTABLE NS_IMETHOD InitStorageEvent(const nsAString & typeArg, bool canBubbleArg, bool cancelableArg, const nsAString & keyArg, const nsAString & oldValueArg, const nsAString & newValueArg, const nsAString & urlArg, nsIDOMStorage *storageAreaArg) { return _to InitStorageEvent(typeArg, canBubbleArg, cancelableArg, keyArg, oldValueArg, newValueArg, urlArg, storageAreaArg); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMSTORAGEEVENT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetKey(nsAString & aKey) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetKey(aKey); } \
  NS_SCRIPTABLE NS_IMETHOD GetOldValue(nsAString & aOldValue) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOldValue(aOldValue); } \
  NS_SCRIPTABLE NS_IMETHOD GetNewValue(nsAString & aNewValue) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetNewValue(aNewValue); } \
  NS_SCRIPTABLE NS_IMETHOD GetUrl(nsAString & aUrl) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetUrl(aUrl); } \
  NS_SCRIPTABLE NS_IMETHOD GetStorageArea(nsIDOMStorage * *aStorageArea) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetStorageArea(aStorageArea); } \
  NS_SCRIPTABLE NS_IMETHOD InitStorageEvent(const nsAString & typeArg, bool canBubbleArg, bool cancelableArg, const nsAString & keyArg, const nsAString & oldValueArg, const nsAString & newValueArg, const nsAString & urlArg, nsIDOMStorage *storageAreaArg) { return !_to ? NS_ERROR_NULL_POINTER : _to->InitStorageEvent(typeArg, canBubbleArg, cancelableArg, keyArg, oldValueArg, newValueArg, urlArg, storageAreaArg); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMStorageEvent : public nsIDOMStorageEvent
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMSTORAGEEVENT

  nsDOMStorageEvent();

private:
  ~nsDOMStorageEvent();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMStorageEvent, nsIDOMStorageEvent)

nsDOMStorageEvent::nsDOMStorageEvent()
{
  /* member initializers and constructor code */
}

nsDOMStorageEvent::~nsDOMStorageEvent()
{
  /* destructor code */
}

/* readonly attribute DOMString key; */
NS_IMETHODIMP nsDOMStorageEvent::GetKey(nsAString & aKey)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute DOMString oldValue; */
NS_IMETHODIMP nsDOMStorageEvent::GetOldValue(nsAString & aOldValue)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute DOMString newValue; */
NS_IMETHODIMP nsDOMStorageEvent::GetNewValue(nsAString & aNewValue)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute DOMString url; */
NS_IMETHODIMP nsDOMStorageEvent::GetUrl(nsAString & aUrl)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMStorage storageArea; */
NS_IMETHODIMP nsDOMStorageEvent::GetStorageArea(nsIDOMStorage * *aStorageArea)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void initStorageEvent (in DOMString typeArg, in boolean canBubbleArg, in boolean cancelableArg, in DOMString keyArg, in DOMString oldValueArg, in DOMString newValueArg, in DOMString urlArg, in nsIDOMStorage storageAreaArg); */
NS_IMETHODIMP nsDOMStorageEvent::InitStorageEvent(const nsAString & typeArg, bool canBubbleArg, bool cancelableArg, const nsAString & keyArg, const nsAString & oldValueArg, const nsAString & newValueArg, const nsAString & urlArg, nsIDOMStorage *storageAreaArg)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMStorageEvent_h__ */
