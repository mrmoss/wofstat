/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM /jds/packages/BUILD/SUNWfirefox-10.0.2/firefox/dom/interfaces/svg/nsIDOMSVGPolygonElement.idl
 */

#ifndef __gen_nsIDOMSVGPolygonElement_h__
#define __gen_nsIDOMSVGPolygonElement_h__


#ifndef __gen_nsIDOMSVGElement_h__
#include "nsIDOMSVGElement.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMSVGPolygonElement */
#define NS_IDOMSVGPOLYGONELEMENT_IID_STR "b94c1af4-f464-41c9-9d38-b8e47f869aa9"

#define NS_IDOMSVGPOLYGONELEMENT_IID \
  {0xb94c1af4, 0xf464, 0x41c9, \
    { 0x9d, 0x38, 0xb8, 0xe4, 0x7f, 0x86, 0x9a, 0xa9 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMSVGPolygonElement : public nsIDOMSVGElement {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMSVGPOLYGONELEMENT_IID)

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMSVGPolygonElement, NS_IDOMSVGPOLYGONELEMENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMSVGPOLYGONELEMENT \
  /* no methods! */

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMSVGPOLYGONELEMENT(_to) \
  /* no methods! */

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMSVGPOLYGONELEMENT(_to) \
  /* no methods! */

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMSVGPolygonElement : public nsIDOMSVGPolygonElement
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMSVGPOLYGONELEMENT

  nsDOMSVGPolygonElement();

private:
  ~nsDOMSVGPolygonElement();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMSVGPolygonElement, nsIDOMSVGPolygonElement)

nsDOMSVGPolygonElement::nsDOMSVGPolygonElement()
{
  /* member initializers and constructor code */
}

nsDOMSVGPolygonElement::~nsDOMSVGPolygonElement()
{
  /* destructor code */
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMSVGPolygonElement_h__ */
