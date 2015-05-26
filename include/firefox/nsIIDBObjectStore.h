/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM /jds/packages/BUILD/SUNWfirefox-10.0.2/firefox/dom/indexedDB/nsIIDBObjectStore.idl
 */

#ifndef __gen_nsIIDBObjectStore_h__
#define __gen_nsIIDBObjectStore_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

#include "jspubtd.h"

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIIDBIndex; /* forward declaration */

class nsIIDBKeyRange; /* forward declaration */

class nsIIDBRequest; /* forward declaration */

class nsIIDBTransaction; /* forward declaration */

class nsIDOMDOMStringList; /* forward declaration */


/* starting interface:    nsIIDBObjectStore */
#define NS_IIDBOBJECTSTORE_IID_STR "adc6a1e2-9fd7-4d28-a7f9-9c653313124b"

#define NS_IIDBOBJECTSTORE_IID \
  {0xadc6a1e2, 0x9fd7, 0x4d28, \
    { 0xa7, 0xf9, 0x9c, 0x65, 0x33, 0x13, 0x12, 0x4b }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIIDBObjectStore : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IIDBOBJECTSTORE_IID)

  /* readonly attribute DOMString name; */
  NS_SCRIPTABLE NS_IMETHOD GetName(nsAString & aName) = 0;

  /* readonly attribute DOMString keyPath; */
  NS_SCRIPTABLE NS_IMETHOD GetKeyPath(nsAString & aKeyPath) = 0;

  /* readonly attribute nsIDOMDOMStringList indexNames; */
  NS_SCRIPTABLE NS_IMETHOD GetIndexNames(nsIDOMDOMStringList * *aIndexNames) = 0;

  /* readonly attribute nsIIDBTransaction transaction; */
  NS_SCRIPTABLE NS_IMETHOD GetTransaction(nsIIDBTransaction * *aTransaction) = 0;

  /* [implicit_jscontext] nsIIDBRequest get (in jsval key); */
  NS_SCRIPTABLE NS_IMETHOD Get(const JS::Value & key, JSContext* cx, nsIIDBRequest * *_retval NS_OUTPARAM) = 0;

  /* [implicit_jscontext,optional_argc] nsIIDBRequest getAll ([optional] in jsval key, [optional] in unsigned long limit); */
  NS_SCRIPTABLE NS_IMETHOD GetAll(const JS::Value & key, PRUint32 limit, JSContext* cx, PRUint8 _argc, nsIIDBRequest * *_retval NS_OUTPARAM) = 0;

  /* [implicit_jscontext,optional_argc] nsIIDBRequest add (in jsval value, [optional] in jsval key); */
  NS_SCRIPTABLE NS_IMETHOD Add(const JS::Value & value, const JS::Value & key, JSContext* cx, PRUint8 _argc, nsIIDBRequest * *_retval NS_OUTPARAM) = 0;

  /* [implicit_jscontext,optional_argc] nsIIDBRequest put (in jsval value, [optional] in jsval key); */
  NS_SCRIPTABLE NS_IMETHOD Put(const JS::Value & value, const JS::Value & key, JSContext* cx, PRUint8 _argc, nsIIDBRequest * *_retval NS_OUTPARAM) = 0;

  /* [implicit_jscontext] nsIIDBRequest delete (in jsval key); */
  NS_SCRIPTABLE NS_IMETHOD Delete(const JS::Value & key, JSContext* cx, nsIIDBRequest * *_retval NS_OUTPARAM) = 0;

  /* nsIIDBRequest clear (); */
  NS_SCRIPTABLE NS_IMETHOD Clear(nsIIDBRequest * *_retval NS_OUTPARAM) = 0;

  /* [implicit_jscontext,optional_argc] nsIIDBRequest openCursor ([optional] in jsval range, [optional] in unsigned short direction); */
  NS_SCRIPTABLE NS_IMETHOD OpenCursor(const JS::Value & range, PRUint16 direction, JSContext* cx, PRUint8 _argc, nsIIDBRequest * *_retval NS_OUTPARAM) = 0;

  /* [implicit_jscontext] nsIIDBIndex createIndex ([Null (Stringify)] in DOMString name, [Null (Stringify)] in DOMString keyPath, [optional] in jsval options); */
  NS_SCRIPTABLE NS_IMETHOD CreateIndex(const nsAString & name, const nsAString & keyPath, const JS::Value & options, JSContext* cx, nsIIDBIndex * *_retval NS_OUTPARAM) = 0;

  /* nsIIDBIndex index ([Null (Stringify)] in DOMString name); */
  NS_SCRIPTABLE NS_IMETHOD Index(const nsAString & name, nsIIDBIndex * *_retval NS_OUTPARAM) = 0;

  /* void deleteIndex ([Null (Stringify)] in DOMString name); */
  NS_SCRIPTABLE NS_IMETHOD DeleteIndex(const nsAString & name) = 0;

  /* [implicit_jscontext,optional_argc] nsIIDBRequest count ([optional] in jsval key); */
  NS_SCRIPTABLE NS_IMETHOD Count(const JS::Value & key, JSContext* cx, PRUint8 _argc, nsIIDBRequest * *_retval NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIIDBObjectStore, NS_IIDBOBJECTSTORE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIIDBOBJECTSTORE \
  NS_SCRIPTABLE NS_IMETHOD GetName(nsAString & aName); \
  NS_SCRIPTABLE NS_IMETHOD GetKeyPath(nsAString & aKeyPath); \
  NS_SCRIPTABLE NS_IMETHOD GetIndexNames(nsIDOMDOMStringList * *aIndexNames); \
  NS_SCRIPTABLE NS_IMETHOD GetTransaction(nsIIDBTransaction * *aTransaction); \
  NS_SCRIPTABLE NS_IMETHOD Get(const JS::Value & key, JSContext* cx, nsIIDBRequest * *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetAll(const JS::Value & key, PRUint32 limit, JSContext* cx, PRUint8 _argc, nsIIDBRequest * *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD Add(const JS::Value & value, const JS::Value & key, JSContext* cx, PRUint8 _argc, nsIIDBRequest * *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD Put(const JS::Value & value, const JS::Value & key, JSContext* cx, PRUint8 _argc, nsIIDBRequest * *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD Delete(const JS::Value & key, JSContext* cx, nsIIDBRequest * *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD Clear(nsIIDBRequest * *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD OpenCursor(const JS::Value & range, PRUint16 direction, JSContext* cx, PRUint8 _argc, nsIIDBRequest * *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD CreateIndex(const nsAString & name, const nsAString & keyPath, const JS::Value & options, JSContext* cx, nsIIDBIndex * *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD Index(const nsAString & name, nsIIDBIndex * *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD DeleteIndex(const nsAString & name); \
  NS_SCRIPTABLE NS_IMETHOD Count(const JS::Value & key, JSContext* cx, PRUint8 _argc, nsIIDBRequest * *_retval NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIIDBOBJECTSTORE(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetName(nsAString & aName) { return _to GetName(aName); } \
  NS_SCRIPTABLE NS_IMETHOD GetKeyPath(nsAString & aKeyPath) { return _to GetKeyPath(aKeyPath); } \
  NS_SCRIPTABLE NS_IMETHOD GetIndexNames(nsIDOMDOMStringList * *aIndexNames) { return _to GetIndexNames(aIndexNames); } \
  NS_SCRIPTABLE NS_IMETHOD GetTransaction(nsIIDBTransaction * *aTransaction) { return _to GetTransaction(aTransaction); } \
  NS_SCRIPTABLE NS_IMETHOD Get(const JS::Value & key, JSContext* cx, nsIIDBRequest * *_retval NS_OUTPARAM) { return _to Get(key, cx, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetAll(const JS::Value & key, PRUint32 limit, JSContext* cx, PRUint8 _argc, nsIIDBRequest * *_retval NS_OUTPARAM) { return _to GetAll(key, limit, cx, _argc, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD Add(const JS::Value & value, const JS::Value & key, JSContext* cx, PRUint8 _argc, nsIIDBRequest * *_retval NS_OUTPARAM) { return _to Add(value, key, cx, _argc, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD Put(const JS::Value & value, const JS::Value & key, JSContext* cx, PRUint8 _argc, nsIIDBRequest * *_retval NS_OUTPARAM) { return _to Put(value, key, cx, _argc, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD Delete(const JS::Value & key, JSContext* cx, nsIIDBRequest * *_retval NS_OUTPARAM) { return _to Delete(key, cx, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD Clear(nsIIDBRequest * *_retval NS_OUTPARAM) { return _to Clear(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD OpenCursor(const JS::Value & range, PRUint16 direction, JSContext* cx, PRUint8 _argc, nsIIDBRequest * *_retval NS_OUTPARAM) { return _to OpenCursor(range, direction, cx, _argc, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD CreateIndex(const nsAString & name, const nsAString & keyPath, const JS::Value & options, JSContext* cx, nsIIDBIndex * *_retval NS_OUTPARAM) { return _to CreateIndex(name, keyPath, options, cx, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD Index(const nsAString & name, nsIIDBIndex * *_retval NS_OUTPARAM) { return _to Index(name, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD DeleteIndex(const nsAString & name) { return _to DeleteIndex(name); } \
  NS_SCRIPTABLE NS_IMETHOD Count(const JS::Value & key, JSContext* cx, PRUint8 _argc, nsIIDBRequest * *_retval NS_OUTPARAM) { return _to Count(key, cx, _argc, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIIDBOBJECTSTORE(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetName(nsAString & aName) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetName(aName); } \
  NS_SCRIPTABLE NS_IMETHOD GetKeyPath(nsAString & aKeyPath) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetKeyPath(aKeyPath); } \
  NS_SCRIPTABLE NS_IMETHOD GetIndexNames(nsIDOMDOMStringList * *aIndexNames) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIndexNames(aIndexNames); } \
  NS_SCRIPTABLE NS_IMETHOD GetTransaction(nsIIDBTransaction * *aTransaction) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTransaction(aTransaction); } \
  NS_SCRIPTABLE NS_IMETHOD Get(const JS::Value & key, JSContext* cx, nsIIDBRequest * *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->Get(key, cx, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetAll(const JS::Value & key, PRUint32 limit, JSContext* cx, PRUint8 _argc, nsIIDBRequest * *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAll(key, limit, cx, _argc, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD Add(const JS::Value & value, const JS::Value & key, JSContext* cx, PRUint8 _argc, nsIIDBRequest * *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->Add(value, key, cx, _argc, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD Put(const JS::Value & value, const JS::Value & key, JSContext* cx, PRUint8 _argc, nsIIDBRequest * *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->Put(value, key, cx, _argc, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD Delete(const JS::Value & key, JSContext* cx, nsIIDBRequest * *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->Delete(key, cx, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD Clear(nsIIDBRequest * *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->Clear(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD OpenCursor(const JS::Value & range, PRUint16 direction, JSContext* cx, PRUint8 _argc, nsIIDBRequest * *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->OpenCursor(range, direction, cx, _argc, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD CreateIndex(const nsAString & name, const nsAString & keyPath, const JS::Value & options, JSContext* cx, nsIIDBIndex * *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->CreateIndex(name, keyPath, options, cx, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD Index(const nsAString & name, nsIIDBIndex * *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->Index(name, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD DeleteIndex(const nsAString & name) { return !_to ? NS_ERROR_NULL_POINTER : _to->DeleteIndex(name); } \
  NS_SCRIPTABLE NS_IMETHOD Count(const JS::Value & key, JSContext* cx, PRUint8 _argc, nsIIDBRequest * *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->Count(key, cx, _argc, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsIDBObjectStore : public nsIIDBObjectStore
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIIDBOBJECTSTORE

  nsIDBObjectStore();

private:
  ~nsIDBObjectStore();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsIDBObjectStore, nsIIDBObjectStore)

nsIDBObjectStore::nsIDBObjectStore()
{
  /* member initializers and constructor code */
}

nsIDBObjectStore::~nsIDBObjectStore()
{
  /* destructor code */
}

/* readonly attribute DOMString name; */
NS_IMETHODIMP nsIDBObjectStore::GetName(nsAString & aName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute DOMString keyPath; */
NS_IMETHODIMP nsIDBObjectStore::GetKeyPath(nsAString & aKeyPath)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMDOMStringList indexNames; */
NS_IMETHODIMP nsIDBObjectStore::GetIndexNames(nsIDOMDOMStringList * *aIndexNames)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIIDBTransaction transaction; */
NS_IMETHODIMP nsIDBObjectStore::GetTransaction(nsIIDBTransaction * *aTransaction)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] nsIIDBRequest get (in jsval key); */
NS_IMETHODIMP nsIDBObjectStore::Get(const JS::Value & key, JSContext* cx, nsIIDBRequest * *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext,optional_argc] nsIIDBRequest getAll ([optional] in jsval key, [optional] in unsigned long limit); */
NS_IMETHODIMP nsIDBObjectStore::GetAll(const JS::Value & key, PRUint32 limit, JSContext* cx, PRUint8 _argc, nsIIDBRequest * *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext,optional_argc] nsIIDBRequest add (in jsval value, [optional] in jsval key); */
NS_IMETHODIMP nsIDBObjectStore::Add(const JS::Value & value, const JS::Value & key, JSContext* cx, PRUint8 _argc, nsIIDBRequest * *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext,optional_argc] nsIIDBRequest put (in jsval value, [optional] in jsval key); */
NS_IMETHODIMP nsIDBObjectStore::Put(const JS::Value & value, const JS::Value & key, JSContext* cx, PRUint8 _argc, nsIIDBRequest * *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] nsIIDBRequest delete (in jsval key); */
NS_IMETHODIMP nsIDBObjectStore::Delete(const JS::Value & key, JSContext* cx, nsIIDBRequest * *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIIDBRequest clear (); */
NS_IMETHODIMP nsIDBObjectStore::Clear(nsIIDBRequest * *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext,optional_argc] nsIIDBRequest openCursor ([optional] in jsval range, [optional] in unsigned short direction); */
NS_IMETHODIMP nsIDBObjectStore::OpenCursor(const JS::Value & range, PRUint16 direction, JSContext* cx, PRUint8 _argc, nsIIDBRequest * *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] nsIIDBIndex createIndex ([Null (Stringify)] in DOMString name, [Null (Stringify)] in DOMString keyPath, [optional] in jsval options); */
NS_IMETHODIMP nsIDBObjectStore::CreateIndex(const nsAString & name, const nsAString & keyPath, const JS::Value & options, JSContext* cx, nsIIDBIndex * *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIIDBIndex index ([Null (Stringify)] in DOMString name); */
NS_IMETHODIMP nsIDBObjectStore::Index(const nsAString & name, nsIIDBIndex * *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void deleteIndex ([Null (Stringify)] in DOMString name); */
NS_IMETHODIMP nsIDBObjectStore::DeleteIndex(const nsAString & name)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext,optional_argc] nsIIDBRequest count ([optional] in jsval key); */
NS_IMETHODIMP nsIDBObjectStore::Count(const JS::Value & key, JSContext* cx, PRUint8 _argc, nsIIDBRequest * *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIIDBObjectStore_h__ */
