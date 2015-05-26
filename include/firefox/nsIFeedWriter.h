/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM /jds/packages/BUILD/SUNWfirefox-10.0.2/firefox/browser/components/feeds/public/nsIFeedWriter.idl
 */

#ifndef __gen_nsIFeedWriter_h__
#define __gen_nsIFeedWriter_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMWindow; /* forward declaration */


/* starting interface:    nsIFeedWriter */
#define NS_IFEEDWRITER_IID_STR "67003393-018c-4e96-af10-c6c51a049fad"

#define NS_IFEEDWRITER_IID \
  {0x67003393, 0x018c, 0x4e96, \
    { 0xaf, 0x10, 0xc6, 0xc5, 0x1a, 0x04, 0x9f, 0xad }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIFeedWriter : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IFEEDWRITER_IID)

  /* void init (in nsIDOMWindow aWindow); */
  NS_SCRIPTABLE NS_IMETHOD Init(nsIDOMWindow *aWindow) = 0;

  /* void writeContent (); */
  NS_SCRIPTABLE NS_IMETHOD WriteContent(void) = 0;

  /* void close (); */
  NS_SCRIPTABLE NS_IMETHOD Close(void) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIFeedWriter, NS_IFEEDWRITER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIFEEDWRITER \
  NS_SCRIPTABLE NS_IMETHOD Init(nsIDOMWindow *aWindow); \
  NS_SCRIPTABLE NS_IMETHOD WriteContent(void); \
  NS_SCRIPTABLE NS_IMETHOD Close(void); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIFEEDWRITER(_to) \
  NS_SCRIPTABLE NS_IMETHOD Init(nsIDOMWindow *aWindow) { return _to Init(aWindow); } \
  NS_SCRIPTABLE NS_IMETHOD WriteContent(void) { return _to WriteContent(); } \
  NS_SCRIPTABLE NS_IMETHOD Close(void) { return _to Close(); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIFEEDWRITER(_to) \
  NS_SCRIPTABLE NS_IMETHOD Init(nsIDOMWindow *aWindow) { return !_to ? NS_ERROR_NULL_POINTER : _to->Init(aWindow); } \
  NS_SCRIPTABLE NS_IMETHOD WriteContent(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->WriteContent(); } \
  NS_SCRIPTABLE NS_IMETHOD Close(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Close(); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsFeedWriter : public nsIFeedWriter
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIFEEDWRITER

  nsFeedWriter();

private:
  ~nsFeedWriter();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsFeedWriter, nsIFeedWriter)

nsFeedWriter::nsFeedWriter()
{
  /* member initializers and constructor code */
}

nsFeedWriter::~nsFeedWriter()
{
  /* destructor code */
}

/* void init (in nsIDOMWindow aWindow); */
NS_IMETHODIMP nsFeedWriter::Init(nsIDOMWindow *aWindow)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void writeContent (); */
NS_IMETHODIMP nsFeedWriter::WriteContent()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void close (); */
NS_IMETHODIMP nsFeedWriter::Close()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIFeedWriter_h__ */
