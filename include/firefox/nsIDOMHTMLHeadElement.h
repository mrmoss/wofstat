/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM /jds/packages/BUILD/SUNWfirefox-10.0.2/firefox/dom/interfaces/html/nsIDOMHTMLHeadElement.idl
 */

#ifndef __gen_nsIDOMHTMLHeadElement_h__
#define __gen_nsIDOMHTMLHeadElement_h__


#ifndef __gen_nsIDOMHTMLElement_h__
#include "nsIDOMHTMLElement.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMHTMLHeadElement */
#define NS_IDOMHTMLHEADELEMENT_IID_STR "6d049c37-2cee-4c04-816c-270973e58ccf"

#define NS_IDOMHTMLHEADELEMENT_IID \
  {0x6d049c37, 0x2cee, 0x4c04, \
    { 0x81, 0x6c, 0x27, 0x09, 0x73, 0xe5, 0x8c, 0xcf }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMHTMLHeadElement : public nsIDOMHTMLElement {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMHTMLHEADELEMENT_IID)

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMHTMLHeadElement, NS_IDOMHTMLHEADELEMENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMHTMLHEADELEMENT \
  /* no methods! */

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMHTMLHEADELEMENT(_to) \
  /* no methods! */

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMHTMLHEADELEMENT(_to) \
  /* no methods! */

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMHTMLHeadElement : public nsIDOMHTMLHeadElement
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMHTMLHEADELEMENT

  nsDOMHTMLHeadElement();

private:
  ~nsDOMHTMLHeadElement();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMHTMLHeadElement, nsIDOMHTMLHeadElement)

nsDOMHTMLHeadElement::nsDOMHTMLHeadElement()
{
  /* member initializers and constructor code */
}

nsDOMHTMLHeadElement::~nsDOMHTMLHeadElement()
{
  /* destructor code */
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMHTMLHeadElement_h__ */
