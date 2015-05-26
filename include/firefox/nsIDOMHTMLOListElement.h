/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM /jds/packages/BUILD/SUNWfirefox-10.0.2/firefox/dom/interfaces/html/nsIDOMHTMLOListElement.idl
 */

#ifndef __gen_nsIDOMHTMLOListElement_h__
#define __gen_nsIDOMHTMLOListElement_h__


#ifndef __gen_nsIDOMHTMLElement_h__
#include "nsIDOMHTMLElement.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMHTMLOListElement */
#define NS_IDOMHTMLOLISTELEMENT_IID_STR "11e66686-b1ef-47be-9025-ffc20b875e4a"

#define NS_IDOMHTMLOLISTELEMENT_IID \
  {0x11e66686, 0xb1ef, 0x47be, \
    { 0x90, 0x25, 0xff, 0xc2, 0x0b, 0x87, 0x5e, 0x4a }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMHTMLOListElement : public nsIDOMHTMLElement {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMHTMLOLISTELEMENT_IID)

  /* attribute boolean compact; */
  NS_SCRIPTABLE NS_IMETHOD GetCompact(bool *aCompact) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetCompact(bool aCompact) = 0;

  /* attribute long start; */
  NS_SCRIPTABLE NS_IMETHOD GetStart(PRInt32 *aStart) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetStart(PRInt32 aStart) = 0;

  /* attribute DOMString type; */
  NS_SCRIPTABLE NS_IMETHOD GetType(nsAString & aType) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetType(const nsAString & aType) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMHTMLOListElement, NS_IDOMHTMLOLISTELEMENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMHTMLOLISTELEMENT \
  NS_SCRIPTABLE NS_IMETHOD GetCompact(bool *aCompact); \
  NS_SCRIPTABLE NS_IMETHOD SetCompact(bool aCompact); \
  NS_SCRIPTABLE NS_IMETHOD GetStart(PRInt32 *aStart); \
  NS_SCRIPTABLE NS_IMETHOD SetStart(PRInt32 aStart); \
  NS_SCRIPTABLE NS_IMETHOD GetType(nsAString & aType); \
  NS_SCRIPTABLE NS_IMETHOD SetType(const nsAString & aType); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMHTMLOLISTELEMENT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetCompact(bool *aCompact) { return _to GetCompact(aCompact); } \
  NS_SCRIPTABLE NS_IMETHOD SetCompact(bool aCompact) { return _to SetCompact(aCompact); } \
  NS_SCRIPTABLE NS_IMETHOD GetStart(PRInt32 *aStart) { return _to GetStart(aStart); } \
  NS_SCRIPTABLE NS_IMETHOD SetStart(PRInt32 aStart) { return _to SetStart(aStart); } \
  NS_SCRIPTABLE NS_IMETHOD GetType(nsAString & aType) { return _to GetType(aType); } \
  NS_SCRIPTABLE NS_IMETHOD SetType(const nsAString & aType) { return _to SetType(aType); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMHTMLOLISTELEMENT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetCompact(bool *aCompact) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCompact(aCompact); } \
  NS_SCRIPTABLE NS_IMETHOD SetCompact(bool aCompact) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetCompact(aCompact); } \
  NS_SCRIPTABLE NS_IMETHOD GetStart(PRInt32 *aStart) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetStart(aStart); } \
  NS_SCRIPTABLE NS_IMETHOD SetStart(PRInt32 aStart) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetStart(aStart); } \
  NS_SCRIPTABLE NS_IMETHOD GetType(nsAString & aType) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetType(aType); } \
  NS_SCRIPTABLE NS_IMETHOD SetType(const nsAString & aType) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetType(aType); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMHTMLOListElement : public nsIDOMHTMLOListElement
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMHTMLOLISTELEMENT

  nsDOMHTMLOListElement();

private:
  ~nsDOMHTMLOListElement();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMHTMLOListElement, nsIDOMHTMLOListElement)

nsDOMHTMLOListElement::nsDOMHTMLOListElement()
{
  /* member initializers and constructor code */
}

nsDOMHTMLOListElement::~nsDOMHTMLOListElement()
{
  /* destructor code */
}

/* attribute boolean compact; */
NS_IMETHODIMP nsDOMHTMLOListElement::GetCompact(bool *aCompact)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLOListElement::SetCompact(bool aCompact)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute long start; */
NS_IMETHODIMP nsDOMHTMLOListElement::GetStart(PRInt32 *aStart)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLOListElement::SetStart(PRInt32 aStart)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString type; */
NS_IMETHODIMP nsDOMHTMLOListElement::GetType(nsAString & aType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLOListElement::SetType(const nsAString & aType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMHTMLOListElement_h__ */
