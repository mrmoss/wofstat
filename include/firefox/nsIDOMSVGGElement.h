/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM /jds/packages/BUILD/SUNWfirefox-10.0.2/firefox/dom/interfaces/svg/nsIDOMSVGGElement.idl
 */

#ifndef __gen_nsIDOMSVGGElement_h__
#define __gen_nsIDOMSVGGElement_h__


#ifndef __gen_nsIDOMSVGElement_h__
#include "nsIDOMSVGElement.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMSVGGElement */
#define NS_IDOMSVGGELEMENT_IID_STR "e0b50fbd-1d1f-44b9-8458-6d54600b2f73"

#define NS_IDOMSVGGELEMENT_IID \
  {0xe0b50fbd, 0x1d1f, 0x44b9, \
    { 0x84, 0x58, 0x6d, 0x54, 0x60, 0x0b, 0x2f, 0x73 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMSVGGElement : public nsIDOMSVGElement {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMSVGGELEMENT_IID)

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMSVGGElement, NS_IDOMSVGGELEMENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMSVGGELEMENT \
  /* no methods! */

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMSVGGELEMENT(_to) \
  /* no methods! */

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMSVGGELEMENT(_to) \
  /* no methods! */

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMSVGGElement : public nsIDOMSVGGElement
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMSVGGELEMENT

  nsDOMSVGGElement();

private:
  ~nsDOMSVGGElement();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMSVGGElement, nsIDOMSVGGElement)

nsDOMSVGGElement::nsDOMSVGGElement()
{
  /* member initializers and constructor code */
}

nsDOMSVGGElement::~nsDOMSVGGElement()
{
  /* destructor code */
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMSVGGElement_h__ */
