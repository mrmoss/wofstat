/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM /jds/packages/BUILD/SUNWfirefox-10.0.2/firefox/dom/interfaces/html/nsIDOMHTMLHtmlElement.idl
 */

#ifndef __gen_nsIDOMHTMLHtmlElement_h__
#define __gen_nsIDOMHTMLHtmlElement_h__


#ifndef __gen_nsIDOMHTMLElement_h__
#include "nsIDOMHTMLElement.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMHTMLHtmlElement */
#define NS_IDOMHTMLHTMLELEMENT_IID_STR "84825a7d-d5c7-4b1a-9d2a-b3e5df055824"

#define NS_IDOMHTMLHTMLELEMENT_IID \
  {0x84825a7d, 0xd5c7, 0x4b1a, \
    { 0x9d, 0x2a, 0xb3, 0xe5, 0xdf, 0x05, 0x58, 0x24 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMHTMLHtmlElement : public nsIDOMHTMLElement {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMHTMLHTMLELEMENT_IID)

  /* attribute DOMString version; */
  NS_SCRIPTABLE NS_IMETHOD GetVersion(nsAString & aVersion) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetVersion(const nsAString & aVersion) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMHTMLHtmlElement, NS_IDOMHTMLHTMLELEMENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMHTMLHTMLELEMENT \
  NS_SCRIPTABLE NS_IMETHOD GetVersion(nsAString & aVersion); \
  NS_SCRIPTABLE NS_IMETHOD SetVersion(const nsAString & aVersion); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMHTMLHTMLELEMENT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetVersion(nsAString & aVersion) { return _to GetVersion(aVersion); } \
  NS_SCRIPTABLE NS_IMETHOD SetVersion(const nsAString & aVersion) { return _to SetVersion(aVersion); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMHTMLHTMLELEMENT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetVersion(nsAString & aVersion) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetVersion(aVersion); } \
  NS_SCRIPTABLE NS_IMETHOD SetVersion(const nsAString & aVersion) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetVersion(aVersion); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMHTMLHtmlElement : public nsIDOMHTMLHtmlElement
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMHTMLHTMLELEMENT

  nsDOMHTMLHtmlElement();

private:
  ~nsDOMHTMLHtmlElement();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMHTMLHtmlElement, nsIDOMHTMLHtmlElement)

nsDOMHTMLHtmlElement::nsDOMHTMLHtmlElement()
{
  /* member initializers and constructor code */
}

nsDOMHTMLHtmlElement::~nsDOMHTMLHtmlElement()
{
  /* destructor code */
}

/* attribute DOMString version; */
NS_IMETHODIMP nsDOMHTMLHtmlElement::GetVersion(nsAString & aVersion)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLHtmlElement::SetVersion(const nsAString & aVersion)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMHTMLHtmlElement_h__ */
