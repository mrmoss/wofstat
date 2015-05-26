/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM /jds/packages/BUILD/SUNWfirefox-10.0.2/firefox/dom/interfaces/svg/nsIDOMSVGSymbolElement.idl
 */

#ifndef __gen_nsIDOMSVGSymbolElement_h__
#define __gen_nsIDOMSVGSymbolElement_h__


#ifndef __gen_nsIDOMSVGElement_h__
#include "nsIDOMSVGElement.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMSVGSymbolElement */
#define NS_IDOMSVGSYMBOLELEMENT_IID_STR "0ae058a5-5528-47ce-a48a-026f1fd8e6df"

#define NS_IDOMSVGSYMBOLELEMENT_IID \
  {0x0ae058a5, 0x5528, 0x47ce, \
    { 0xa4, 0x8a, 0x02, 0x6f, 0x1f, 0xd8, 0xe6, 0xdf }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMSVGSymbolElement : public nsIDOMSVGElement {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMSVGSYMBOLELEMENT_IID)

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMSVGSymbolElement, NS_IDOMSVGSYMBOLELEMENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMSVGSYMBOLELEMENT \
  /* no methods! */

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMSVGSYMBOLELEMENT(_to) \
  /* no methods! */

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMSVGSYMBOLELEMENT(_to) \
  /* no methods! */

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMSVGSymbolElement : public nsIDOMSVGSymbolElement
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMSVGSYMBOLELEMENT

  nsDOMSVGSymbolElement();

private:
  ~nsDOMSVGSymbolElement();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMSVGSymbolElement, nsIDOMSVGSymbolElement)

nsDOMSVGSymbolElement::nsDOMSVGSymbolElement()
{
  /* member initializers and constructor code */
}

nsDOMSVGSymbolElement::~nsDOMSVGSymbolElement()
{
  /* destructor code */
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMSVGSymbolElement_h__ */
