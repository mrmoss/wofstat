/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM /jds/packages/BUILD/SUNWfirefox-10.0.2/firefox/dom/interfaces/html/nsIDOMHTMLQuoteElement.idl
 */

#ifndef __gen_nsIDOMHTMLQuoteElement_h__
#define __gen_nsIDOMHTMLQuoteElement_h__


#ifndef __gen_nsIDOMHTMLElement_h__
#include "nsIDOMHTMLElement.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMHTMLQuoteElement */
#define NS_IDOMHTMLQUOTEELEMENT_IID_STR "820ccd14-2479-4e4a-99d3-76d138caf7ec"

#define NS_IDOMHTMLQUOTEELEMENT_IID \
  {0x820ccd14, 0x2479, 0x4e4a, \
    { 0x99, 0xd3, 0x76, 0xd1, 0x38, 0xca, 0xf7, 0xec }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMHTMLQuoteElement : public nsIDOMHTMLElement {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMHTMLQUOTEELEMENT_IID)

  /* attribute DOMString cite; */
  NS_SCRIPTABLE NS_IMETHOD GetCite(nsAString & aCite) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetCite(const nsAString & aCite) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMHTMLQuoteElement, NS_IDOMHTMLQUOTEELEMENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMHTMLQUOTEELEMENT \
  NS_SCRIPTABLE NS_IMETHOD GetCite(nsAString & aCite); \
  NS_SCRIPTABLE NS_IMETHOD SetCite(const nsAString & aCite); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMHTMLQUOTEELEMENT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetCite(nsAString & aCite) { return _to GetCite(aCite); } \
  NS_SCRIPTABLE NS_IMETHOD SetCite(const nsAString & aCite) { return _to SetCite(aCite); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMHTMLQUOTEELEMENT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetCite(nsAString & aCite) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCite(aCite); } \
  NS_SCRIPTABLE NS_IMETHOD SetCite(const nsAString & aCite) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetCite(aCite); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMHTMLQuoteElement : public nsIDOMHTMLQuoteElement
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMHTMLQUOTEELEMENT

  nsDOMHTMLQuoteElement();

private:
  ~nsDOMHTMLQuoteElement();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMHTMLQuoteElement, nsIDOMHTMLQuoteElement)

nsDOMHTMLQuoteElement::nsDOMHTMLQuoteElement()
{
  /* member initializers and constructor code */
}

nsDOMHTMLQuoteElement::~nsDOMHTMLQuoteElement()
{
  /* destructor code */
}

/* attribute DOMString cite; */
NS_IMETHODIMP nsDOMHTMLQuoteElement::GetCite(nsAString & aCite)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLQuoteElement::SetCite(const nsAString & aCite)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMHTMLQuoteElement_h__ */
