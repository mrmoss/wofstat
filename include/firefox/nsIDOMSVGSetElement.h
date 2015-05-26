/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM /jds/packages/BUILD/SUNWfirefox-10.0.2/firefox/dom/interfaces/svg/nsIDOMSVGSetElement.idl
 */

#ifndef __gen_nsIDOMSVGSetElement_h__
#define __gen_nsIDOMSVGSetElement_h__


#ifndef __gen_nsIDOMSVGAnimationElement_h__
#include "nsIDOMSVGAnimationElement.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMSVGSetElement */
#define NS_IDOMSVGSETELEMENT_IID_STR "2161719b-cfdb-4fd4-b501-a439537fb12b"

#define NS_IDOMSVGSETELEMENT_IID \
  {0x2161719b, 0xcfdb, 0x4fd4, \
    { 0xb5, 0x01, 0xa4, 0x39, 0x53, 0x7f, 0xb1, 0x2b }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMSVGSetElement : public nsIDOMSVGAnimationElement {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMSVGSETELEMENT_IID)

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMSVGSetElement, NS_IDOMSVGSETELEMENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMSVGSETELEMENT \
  /* no methods! */

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMSVGSETELEMENT(_to) \
  /* no methods! */

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMSVGSETELEMENT(_to) \
  /* no methods! */

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMSVGSetElement : public nsIDOMSVGSetElement
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMSVGSETELEMENT

  nsDOMSVGSetElement();

private:
  ~nsDOMSVGSetElement();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMSVGSetElement, nsIDOMSVGSetElement)

nsDOMSVGSetElement::nsDOMSVGSetElement()
{
  /* member initializers and constructor code */
}

nsDOMSVGSetElement::~nsDOMSVGSetElement()
{
  /* destructor code */
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMSVGSetElement_h__ */
