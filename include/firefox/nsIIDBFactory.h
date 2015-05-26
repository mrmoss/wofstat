/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM /jds/packages/BUILD/SUNWfirefox-10.0.2/firefox/dom/indexedDB/nsIIDBFactory.idl
 */

#ifndef __gen_nsIIDBFactory_h__
#define __gen_nsIIDBFactory_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIIDBKeyRange; /* forward declaration */

class nsIIDBOpenDBRequest; /* forward declaration */


/* starting interface:    nsIIDBFactory */
#define NS_IIDBFACTORY_IID_STR "885abbb7-cf81-4945-b5f1-07fed07ada82"

#define NS_IIDBFACTORY_IID \
  {0x885abbb7, 0xcf81, 0x4945, \
    { 0xb5, 0xf1, 0x07, 0xfe, 0xd0, 0x7a, 0xda, 0x82 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIIDBFactory : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IIDBFACTORY_IID)

  /* [optional_argc] nsIIDBOpenDBRequest open ([Null (Stringify)] in DOMString name, [optional] in long long version); */
  NS_SCRIPTABLE NS_IMETHOD Open(const nsAString & name, PRInt64 version, PRUint8 _argc, nsIIDBOpenDBRequest * *_retval NS_OUTPARAM) = 0;

  /* nsIIDBOpenDBRequest deleteDatabase (in AString name); */
  NS_SCRIPTABLE NS_IMETHOD DeleteDatabase(const nsAString & name, nsIIDBOpenDBRequest * *_retval NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIIDBFactory, NS_IIDBFACTORY_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIIDBFACTORY \
  NS_SCRIPTABLE NS_IMETHOD Open(const nsAString & name, PRInt64 version, PRUint8 _argc, nsIIDBOpenDBRequest * *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD DeleteDatabase(const nsAString & name, nsIIDBOpenDBRequest * *_retval NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIIDBFACTORY(_to) \
  NS_SCRIPTABLE NS_IMETHOD Open(const nsAString & name, PRInt64 version, PRUint8 _argc, nsIIDBOpenDBRequest * *_retval NS_OUTPARAM) { return _to Open(name, version, _argc, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD DeleteDatabase(const nsAString & name, nsIIDBOpenDBRequest * *_retval NS_OUTPARAM) { return _to DeleteDatabase(name, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIIDBFACTORY(_to) \
  NS_SCRIPTABLE NS_IMETHOD Open(const nsAString & name, PRInt64 version, PRUint8 _argc, nsIIDBOpenDBRequest * *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->Open(name, version, _argc, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD DeleteDatabase(const nsAString & name, nsIIDBOpenDBRequest * *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->DeleteDatabase(name, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsIDBFactory : public nsIIDBFactory
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIIDBFACTORY

  nsIDBFactory();

private:
  ~nsIDBFactory();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsIDBFactory, nsIIDBFactory)

nsIDBFactory::nsIDBFactory()
{
  /* member initializers and constructor code */
}

nsIDBFactory::~nsIDBFactory()
{
  /* destructor code */
}

/* [optional_argc] nsIIDBOpenDBRequest open ([Null (Stringify)] in DOMString name, [optional] in long long version); */
NS_IMETHODIMP nsIDBFactory::Open(const nsAString & name, PRInt64 version, PRUint8 _argc, nsIIDBOpenDBRequest * *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIIDBOpenDBRequest deleteDatabase (in AString name); */
NS_IMETHODIMP nsIDBFactory::DeleteDatabase(const nsAString & name, nsIIDBOpenDBRequest * *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIIDBFactory_h__ */
