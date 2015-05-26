/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM /jds/packages/BUILD/SUNWfirefox-10.0.2/firefox/dom/interfaces/svg/nsIDOMSVGDocument.idl
 */

#ifndef __gen_nsIDOMSVGDocument_h__
#define __gen_nsIDOMSVGDocument_h__


#ifndef __gen_nsIDOMDocument_h__
#include "nsIDOMDocument.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMSVGSVGElement; /* forward declaration */


/* starting interface:    nsIDOMSVGDocument */
#define NS_IDOMSVGDOCUMENT_IID_STR "4368b131-bfe9-4f34-848d-00139217c1d1"

#define NS_IDOMSVGDOCUMENT_IID \
  {0x4368b131, 0xbfe9, 0x4f34, \
    { 0x84, 0x8d, 0x00, 0x13, 0x92, 0x17, 0xc1, 0xd1 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMSVGDocument : public nsIDOMDocument {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMSVGDOCUMENT_IID)

  /* readonly attribute DOMString domain; */
  NS_SCRIPTABLE NS_IMETHOD GetDomain(nsAString & aDomain) = 0;

  /* readonly attribute DOMString URL; */
  NS_SCRIPTABLE NS_IMETHOD GetURL(nsAString & aURL) = 0;

  /* readonly attribute nsIDOMSVGSVGElement rootElement; */
  NS_SCRIPTABLE NS_IMETHOD GetRootElement(nsIDOMSVGSVGElement * *aRootElement) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMSVGDocument, NS_IDOMSVGDOCUMENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMSVGDOCUMENT \
  NS_SCRIPTABLE NS_IMETHOD GetDomain(nsAString & aDomain); \
  NS_SCRIPTABLE NS_IMETHOD GetURL(nsAString & aURL); \
  NS_SCRIPTABLE NS_IMETHOD GetRootElement(nsIDOMSVGSVGElement * *aRootElement); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMSVGDOCUMENT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetDomain(nsAString & aDomain) { return _to GetDomain(aDomain); } \
  NS_SCRIPTABLE NS_IMETHOD GetURL(nsAString & aURL) { return _to GetURL(aURL); } \
  NS_SCRIPTABLE NS_IMETHOD GetRootElement(nsIDOMSVGSVGElement * *aRootElement) { return _to GetRootElement(aRootElement); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMSVGDOCUMENT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetDomain(nsAString & aDomain) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDomain(aDomain); } \
  NS_SCRIPTABLE NS_IMETHOD GetURL(nsAString & aURL) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetURL(aURL); } \
  NS_SCRIPTABLE NS_IMETHOD GetRootElement(nsIDOMSVGSVGElement * *aRootElement) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetRootElement(aRootElement); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMSVGDocument : public nsIDOMSVGDocument
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMSVGDOCUMENT

  nsDOMSVGDocument();

private:
  ~nsDOMSVGDocument();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMSVGDocument, nsIDOMSVGDocument)

nsDOMSVGDocument::nsDOMSVGDocument()
{
  /* member initializers and constructor code */
}

nsDOMSVGDocument::~nsDOMSVGDocument()
{
  /* destructor code */
}

/* readonly attribute DOMString domain; */
NS_IMETHODIMP nsDOMSVGDocument::GetDomain(nsAString & aDomain)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute DOMString URL; */
NS_IMETHODIMP nsDOMSVGDocument::GetURL(nsAString & aURL)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMSVGSVGElement rootElement; */
NS_IMETHODIMP nsDOMSVGDocument::GetRootElement(nsIDOMSVGSVGElement * *aRootElement)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMSVGDocument_h__ */
