/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM /jds/packages/BUILD/SUNWfirefox-10.0.2/firefox/dom/interfaces/html/nsIDOMHTMLDListElement.idl
 */

#ifndef __gen_nsIDOMHTMLDListElement_h__
#define __gen_nsIDOMHTMLDListElement_h__


#ifndef __gen_nsIDOMHTMLElement_h__
#include "nsIDOMHTMLElement.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMHTMLDListElement */
#define NS_IDOMHTMLDLISTELEMENT_IID_STR "f3e65e2b-e079-4970-bb5d-f96ac9cd18c5"

#define NS_IDOMHTMLDLISTELEMENT_IID \
  {0xf3e65e2b, 0xe079, 0x4970, \
    { 0xbb, 0x5d, 0xf9, 0x6a, 0xc9, 0xcd, 0x18, 0xc5 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMHTMLDListElement : public nsIDOMHTMLElement {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMHTMLDLISTELEMENT_IID)

  /* attribute boolean compact; */
  NS_SCRIPTABLE NS_IMETHOD GetCompact(bool *aCompact) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetCompact(bool aCompact) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMHTMLDListElement, NS_IDOMHTMLDLISTELEMENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMHTMLDLISTELEMENT \
  NS_SCRIPTABLE NS_IMETHOD GetCompact(bool *aCompact); \
  NS_SCRIPTABLE NS_IMETHOD SetCompact(bool aCompact); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMHTMLDLISTELEMENT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetCompact(bool *aCompact) { return _to GetCompact(aCompact); } \
  NS_SCRIPTABLE NS_IMETHOD SetCompact(bool aCompact) { return _to SetCompact(aCompact); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMHTMLDLISTELEMENT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetCompact(bool *aCompact) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCompact(aCompact); } \
  NS_SCRIPTABLE NS_IMETHOD SetCompact(bool aCompact) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetCompact(aCompact); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMHTMLDListElement : public nsIDOMHTMLDListElement
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMHTMLDLISTELEMENT

  nsDOMHTMLDListElement();

private:
  ~nsDOMHTMLDListElement();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMHTMLDListElement, nsIDOMHTMLDListElement)

nsDOMHTMLDListElement::nsDOMHTMLDListElement()
{
  /* member initializers and constructor code */
}

nsDOMHTMLDListElement::~nsDOMHTMLDListElement()
{
  /* destructor code */
}

/* attribute boolean compact; */
NS_IMETHODIMP nsDOMHTMLDListElement::GetCompact(bool *aCompact)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLDListElement::SetCompact(bool aCompact)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMHTMLDListElement_h__ */
