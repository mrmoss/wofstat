/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM /jds/packages/BUILD/SUNWfirefox-10.0.2/firefox/dom/interfaces/svg/nsIDOMSVGPolylineElement.idl
 */

#ifndef __gen_nsIDOMSVGPolylineElement_h__
#define __gen_nsIDOMSVGPolylineElement_h__


#ifndef __gen_nsIDOMSVGElement_h__
#include "nsIDOMSVGElement.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMSVGPolylineElement */
#define NS_IDOMSVGPOLYLINEELEMENT_IID_STR "c2a0becc-3b3d-45a9-8f5c-b13963aadf6b"

#define NS_IDOMSVGPOLYLINEELEMENT_IID \
  {0xc2a0becc, 0x3b3d, 0x45a9, \
    { 0x8f, 0x5c, 0xb1, 0x39, 0x63, 0xaa, 0xdf, 0x6b }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMSVGPolylineElement : public nsIDOMSVGElement {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMSVGPOLYLINEELEMENT_IID)

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMSVGPolylineElement, NS_IDOMSVGPOLYLINEELEMENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMSVGPOLYLINEELEMENT \
  /* no methods! */

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMSVGPOLYLINEELEMENT(_to) \
  /* no methods! */

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMSVGPOLYLINEELEMENT(_to) \
  /* no methods! */

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMSVGPolylineElement : public nsIDOMSVGPolylineElement
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMSVGPOLYLINEELEMENT

  nsDOMSVGPolylineElement();

private:
  ~nsDOMSVGPolylineElement();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMSVGPolylineElement, nsIDOMSVGPolylineElement)

nsDOMSVGPolylineElement::nsDOMSVGPolylineElement()
{
  /* member initializers and constructor code */
}

nsDOMSVGPolylineElement::~nsDOMSVGPolylineElement()
{
  /* destructor code */
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMSVGPolylineElement_h__ */
