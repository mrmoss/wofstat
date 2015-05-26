/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM /jds/packages/BUILD/SUNWfirefox-10.0.2/firefox/dom/interfaces/html/nsIDOMHTMLMenuItemElement.idl
 */

#ifndef __gen_nsIDOMHTMLMenuItemElement_h__
#define __gen_nsIDOMHTMLMenuItemElement_h__


#ifndef __gen_nsIDOMHTMLCommandElement_h__
#include "nsIDOMHTMLCommandElement.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMHTMLMenuItemElement */
#define NS_IDOMHTMLMENUITEMELEMENT_IID_STR "e0469d92-a137-4329-9d4b-9f2ba5ce8e77"

#define NS_IDOMHTMLMENUITEMELEMENT_IID \
  {0xe0469d92, 0xa137, 0x4329, \
    { 0x9d, 0x4b, 0x9f, 0x2b, 0xa5, 0xce, 0x8e, 0x77 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMHTMLMenuItemElement : public nsIDOMHTMLCommandElement {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMHTMLMENUITEMELEMENT_IID)

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMHTMLMenuItemElement, NS_IDOMHTMLMENUITEMELEMENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMHTMLMENUITEMELEMENT \
  /* no methods! */

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMHTMLMENUITEMELEMENT(_to) \
  /* no methods! */

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMHTMLMENUITEMELEMENT(_to) \
  /* no methods! */

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMHTMLMenuItemElement : public nsIDOMHTMLMenuItemElement
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMHTMLMENUITEMELEMENT

  nsDOMHTMLMenuItemElement();

private:
  ~nsDOMHTMLMenuItemElement();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMHTMLMenuItemElement, nsIDOMHTMLMenuItemElement)

nsDOMHTMLMenuItemElement::nsDOMHTMLMenuItemElement()
{
  /* member initializers and constructor code */
}

nsDOMHTMLMenuItemElement::~nsDOMHTMLMenuItemElement()
{
  /* destructor code */
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMHTMLMenuItemElement_h__ */
