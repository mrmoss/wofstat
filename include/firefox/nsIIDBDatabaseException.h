/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM /jds/packages/BUILD/SUNWfirefox-10.0.2/firefox/dom/indexedDB/nsIIDBDatabaseException.idl
 */

#ifndef __gen_nsIIDBDatabaseException_h__
#define __gen_nsIIDBDatabaseException_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIIDBDatabaseException */
#define NS_IIDBDATABASEEXCEPTION_IID_STR "7aad2542-a5cb-4a57-b20c-c7d16b8582ab"

#define NS_IIDBDATABASEEXCEPTION_IID \
  {0x7aad2542, 0xa5cb, 0x4a57, \
    { 0xb2, 0x0c, 0xc7, 0xd1, 0x6b, 0x85, 0x82, 0xab }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIIDBDatabaseException : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IIDBDATABASEEXCEPTION_IID)

  enum { UNKNOWN_ERR = 1U };

  enum { NON_TRANSIENT_ERR = 2U };

  enum { NOT_FOUND_ERR = 3U };

  enum { CONSTRAINT_ERR = 4U };

  enum { DATA_ERR = 5U };

  enum { NOT_ALLOWED_ERR = 6U };

  enum { TRANSACTION_INACTIVE_ERR = 7U };

  enum { ABORT_ERR = 8U };

  enum { READ_ONLY_ERR = 9U };

  enum { TIMEOUT_ERR = 10U };

  enum { QUOTA_ERR = 11U };

  enum { VERSION_ERR = 12U };

  /* readonly attribute unsigned short code; */
  NS_SCRIPTABLE NS_IMETHOD GetCode(PRUint16 *aCode) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIIDBDatabaseException, NS_IIDBDATABASEEXCEPTION_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIIDBDATABASEEXCEPTION \
  NS_SCRIPTABLE NS_IMETHOD GetCode(PRUint16 *aCode); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIIDBDATABASEEXCEPTION(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetCode(PRUint16 *aCode) { return _to GetCode(aCode); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIIDBDATABASEEXCEPTION(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetCode(PRUint16 *aCode) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCode(aCode); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsIDBDatabaseException : public nsIIDBDatabaseException
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIIDBDATABASEEXCEPTION

  nsIDBDatabaseException();

private:
  ~nsIDBDatabaseException();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsIDBDatabaseException, nsIIDBDatabaseException)

nsIDBDatabaseException::nsIDBDatabaseException()
{
  /* member initializers and constructor code */
}

nsIDBDatabaseException::~nsIDBDatabaseException()
{
  /* destructor code */
}

/* readonly attribute unsigned short code; */
NS_IMETHODIMP nsIDBDatabaseException::GetCode(PRUint16 *aCode)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIIDBDatabaseException_h__ */
