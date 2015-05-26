/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM /jds/packages/BUILD/SUNWfirefox-10.0.2/firefox/dom/interfaces/core/nsIDOMNodeList.idl
 */

#ifndef __gen_nsIDOMNodeList_h__
#define __gen_nsIDOMNodeList_h__


#ifndef __gen_domstubs_h__
#include "domstubs.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIContent; /* forward declaration */


/* starting interface:    nsIDOMNodeList */
#define NS_IDOMNODELIST_IID_STR "496852ba-e48d-4fa5-982e-e0dc1b475bf1"

#define NS_IDOMNODELIST_IID \
  {0x496852ba, 0xe48d, 0x4fa5, \
    { 0x98, 0x2e, 0xe0, 0xdc, 0x1b, 0x47, 0x5b, 0xf1 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMNodeList : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMNODELIST_IID)

  /* [forward(getNodeAt),getter] nsIDOMNode item (in unsigned long index); */
  NS_SCRIPTABLE NS_IMETHOD Item(PRUint32 index, nsIDOMNode * *_retval NS_OUTPARAM) = 0;

  /* readonly attribute unsigned long length; */
  NS_SCRIPTABLE NS_IMETHOD GetLength(PRUint32 *aLength) = 0;

  /* [noscript,nostdcall,notxpcom] nsIContent getNodeAt (in unsigned long index); */
  virtual nsIContent * GetNodeAt(PRUint32 index) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMNodeList, NS_IDOMNODELIST_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMNODELIST \
  NS_SCRIPTABLE NS_IMETHOD Item(PRUint32 index, nsIDOMNode * *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetLength(PRUint32 *aLength); \
  virtual nsIContent * GetNodeAt(PRUint32 index); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMNODELIST(_to) \
  NS_SCRIPTABLE NS_IMETHOD Item(PRUint32 index, nsIDOMNode * *_retval NS_OUTPARAM) { return _to Item(index, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetLength(PRUint32 *aLength) { return _to GetLength(aLength); } \
  virtual nsIContent * GetNodeAt(PRUint32 index) { return _to GetNodeAt(index); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMNODELIST(_to) \
  NS_SCRIPTABLE NS_IMETHOD Item(PRUint32 index, nsIDOMNode * *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->Item(index, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetLength(PRUint32 *aLength) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLength(aLength); } \
  virtual nsIContent * GetNodeAt(PRUint32 index) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetNodeAt(index); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMNodeList : public nsIDOMNodeList
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMNODELIST

  nsDOMNodeList();

private:
  ~nsDOMNodeList();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMNodeList, nsIDOMNodeList)

nsDOMNodeList::nsDOMNodeList()
{
  /* member initializers and constructor code */
}

nsDOMNodeList::~nsDOMNodeList()
{
  /* destructor code */
}

/* [forward(getNodeAt),getter] nsIDOMNode item (in unsigned long index); */
NS_IMETHODIMP nsDOMNodeList::Item(PRUint32 index, nsIDOMNode * *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned long length; */
NS_IMETHODIMP nsDOMNodeList::GetLength(PRUint32 *aLength)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript,nostdcall,notxpcom] nsIContent getNodeAt (in unsigned long index); */
nsIContent * nsDOMNodeList::GetNodeAt(PRUint32 index)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMNodeList_h__ */
