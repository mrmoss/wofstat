/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM /jds/packages/BUILD/SUNWfirefox-10.0.2/firefox/dom/interfaces/events/nsIDOMDataContainerEvent.idl
 */

#ifndef __gen_nsIDOMDataContainerEvent_h__
#define __gen_nsIDOMDataContainerEvent_h__


#ifndef __gen_nsIDOMEvent_h__
#include "nsIDOMEvent.h"
#endif

#ifndef __gen_nsIVariant_h__
#include "nsIVariant.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMDataContainerEvent */
#define NS_IDOMDATACONTAINEREVENT_IID_STR "ac70e6bd-1f52-45ce-9d63-0aa650480ba1"

#define NS_IDOMDATACONTAINEREVENT_IID \
  {0xac70e6bd, 0x1f52, 0x45ce, \
    { 0x9d, 0x63, 0x0a, 0xa6, 0x50, 0x48, 0x0b, 0xa1 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMDataContainerEvent : public nsIDOMEvent {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMDATACONTAINEREVENT_IID)

  /* nsIVariant getData (in DOMString key); */
  NS_SCRIPTABLE NS_IMETHOD GetData(const nsAString & key, nsIVariant * *_retval NS_OUTPARAM) = 0;

  /* void setData (in DOMString key, in nsIVariant data); */
  NS_SCRIPTABLE NS_IMETHOD SetData(const nsAString & key, nsIVariant *data) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMDataContainerEvent, NS_IDOMDATACONTAINEREVENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMDATACONTAINEREVENT \
  NS_SCRIPTABLE NS_IMETHOD GetData(const nsAString & key, nsIVariant * *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD SetData(const nsAString & key, nsIVariant *data); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMDATACONTAINEREVENT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetData(const nsAString & key, nsIVariant * *_retval NS_OUTPARAM) { return _to GetData(key, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD SetData(const nsAString & key, nsIVariant *data) { return _to SetData(key, data); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMDATACONTAINEREVENT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetData(const nsAString & key, nsIVariant * *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetData(key, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD SetData(const nsAString & key, nsIVariant *data) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetData(key, data); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMDataContainerEvent : public nsIDOMDataContainerEvent
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMDATACONTAINEREVENT

  nsDOMDataContainerEvent();

private:
  ~nsDOMDataContainerEvent();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMDataContainerEvent, nsIDOMDataContainerEvent)

nsDOMDataContainerEvent::nsDOMDataContainerEvent()
{
  /* member initializers and constructor code */
}

nsDOMDataContainerEvent::~nsDOMDataContainerEvent()
{
  /* destructor code */
}

/* nsIVariant getData (in DOMString key); */
NS_IMETHODIMP nsDOMDataContainerEvent::GetData(const nsAString & key, nsIVariant * *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setData (in DOMString key, in nsIVariant data); */
NS_IMETHODIMP nsDOMDataContainerEvent::SetData(const nsAString & key, nsIVariant *data)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMDataContainerEvent_h__ */
