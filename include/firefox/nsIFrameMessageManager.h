/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM /jds/packages/BUILD/SUNWfirefox-10.0.2/firefox/content/base/public/nsIFrameMessageManager.idl
 */

#ifndef __gen_nsIFrameMessageManager_h__
#define __gen_nsIFrameMessageManager_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

#include "jspubtd.h"

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMWindow; /* forward declaration */

class nsIDocShell; /* forward declaration */

class nsIContent; /* forward declaration */


/* starting interface:    nsIFrameMessageListener */
#define NS_IFRAMEMESSAGELISTENER_IID_STR "938fcb95-3d63-46be-aa72-94d08fd3b418"

#define NS_IFRAMEMESSAGELISTENER_IID \
  {0x938fcb95, 0x3d63, 0x46be, \
    { 0xaa, 0x72, 0x94, 0xd0, 0x8f, 0xd3, 0xb4, 0x18 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIFrameMessageListener : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IFRAMEMESSAGELISTENER_IID)

  /* void receiveMessage (); */
  NS_SCRIPTABLE NS_IMETHOD ReceiveMessage(void) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIFrameMessageListener, NS_IFRAMEMESSAGELISTENER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIFRAMEMESSAGELISTENER \
  NS_SCRIPTABLE NS_IMETHOD ReceiveMessage(void); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIFRAMEMESSAGELISTENER(_to) \
  NS_SCRIPTABLE NS_IMETHOD ReceiveMessage(void) { return _to ReceiveMessage(); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIFRAMEMESSAGELISTENER(_to) \
  NS_SCRIPTABLE NS_IMETHOD ReceiveMessage(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->ReceiveMessage(); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsFrameMessageListener : public nsIFrameMessageListener
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIFRAMEMESSAGELISTENER

  nsFrameMessageListener();

private:
  ~nsFrameMessageListener();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsFrameMessageListener, nsIFrameMessageListener)

nsFrameMessageListener::nsFrameMessageListener()
{
  /* member initializers and constructor code */
}

nsFrameMessageListener::~nsFrameMessageListener()
{
  /* destructor code */
}

/* void receiveMessage (); */
NS_IMETHODIMP nsFrameMessageListener::ReceiveMessage()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIFrameMessageManager */
#define NS_IFRAMEMESSAGEMANAGER_IID_STR "a27d8fcd-8de9-4a51-87f4-2b83bba901d5"

#define NS_IFRAMEMESSAGEMANAGER_IID \
  {0xa27d8fcd, 0x8de9, 0x4a51, \
    { 0x87, 0xf4, 0x2b, 0x83, 0xbb, 0xa9, 0x01, 0xd5 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIFrameMessageManager : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IFRAMEMESSAGEMANAGER_IID)

  /* void addMessageListener (in AString aMessage, in nsIFrameMessageListener aListener); */
  NS_SCRIPTABLE NS_IMETHOD AddMessageListener(const nsAString & aMessage, nsIFrameMessageListener *aListener) = 0;

  /* void removeMessageListener (in AString aMessage, in nsIFrameMessageListener aListener); */
  NS_SCRIPTABLE NS_IMETHOD RemoveMessageListener(const nsAString & aMessage, nsIFrameMessageListener *aListener) = 0;

  /* [implicit_jscontext,optional_argc] void sendAsyncMessage ([optional] in AString messageName, [optional] in jsval obj); */
  NS_SCRIPTABLE NS_IMETHOD SendAsyncMessage(const nsAString & messageName, const JS::Value & obj, JSContext* cx, PRUint8 _argc) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIFrameMessageManager, NS_IFRAMEMESSAGEMANAGER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIFRAMEMESSAGEMANAGER \
  NS_SCRIPTABLE NS_IMETHOD AddMessageListener(const nsAString & aMessage, nsIFrameMessageListener *aListener); \
  NS_SCRIPTABLE NS_IMETHOD RemoveMessageListener(const nsAString & aMessage, nsIFrameMessageListener *aListener); \
  NS_SCRIPTABLE NS_IMETHOD SendAsyncMessage(const nsAString & messageName, const JS::Value & obj, JSContext* cx, PRUint8 _argc); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIFRAMEMESSAGEMANAGER(_to) \
  NS_SCRIPTABLE NS_IMETHOD AddMessageListener(const nsAString & aMessage, nsIFrameMessageListener *aListener) { return _to AddMessageListener(aMessage, aListener); } \
  NS_SCRIPTABLE NS_IMETHOD RemoveMessageListener(const nsAString & aMessage, nsIFrameMessageListener *aListener) { return _to RemoveMessageListener(aMessage, aListener); } \
  NS_SCRIPTABLE NS_IMETHOD SendAsyncMessage(const nsAString & messageName, const JS::Value & obj, JSContext* cx, PRUint8 _argc) { return _to SendAsyncMessage(messageName, obj, cx, _argc); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIFRAMEMESSAGEMANAGER(_to) \
  NS_SCRIPTABLE NS_IMETHOD AddMessageListener(const nsAString & aMessage, nsIFrameMessageListener *aListener) { return !_to ? NS_ERROR_NULL_POINTER : _to->AddMessageListener(aMessage, aListener); } \
  NS_SCRIPTABLE NS_IMETHOD RemoveMessageListener(const nsAString & aMessage, nsIFrameMessageListener *aListener) { return !_to ? NS_ERROR_NULL_POINTER : _to->RemoveMessageListener(aMessage, aListener); } \
  NS_SCRIPTABLE NS_IMETHOD SendAsyncMessage(const nsAString & messageName, const JS::Value & obj, JSContext* cx, PRUint8 _argc) { return !_to ? NS_ERROR_NULL_POINTER : _to->SendAsyncMessage(messageName, obj, cx, _argc); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsFrameMessageManager : public nsIFrameMessageManager
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIFRAMEMESSAGEMANAGER

  nsFrameMessageManager();

private:
  ~nsFrameMessageManager();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsFrameMessageManager, nsIFrameMessageManager)

nsFrameMessageManager::nsFrameMessageManager()
{
  /* member initializers and constructor code */
}

nsFrameMessageManager::~nsFrameMessageManager()
{
  /* destructor code */
}

/* void addMessageListener (in AString aMessage, in nsIFrameMessageListener aListener); */
NS_IMETHODIMP nsFrameMessageManager::AddMessageListener(const nsAString & aMessage, nsIFrameMessageListener *aListener)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void removeMessageListener (in AString aMessage, in nsIFrameMessageListener aListener); */
NS_IMETHODIMP nsFrameMessageManager::RemoveMessageListener(const nsAString & aMessage, nsIFrameMessageListener *aListener)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext,optional_argc] void sendAsyncMessage ([optional] in AString messageName, [optional] in jsval obj); */
NS_IMETHODIMP nsFrameMessageManager::SendAsyncMessage(const nsAString & messageName, const JS::Value & obj, JSContext* cx, PRUint8 _argc)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsISyncMessageSender */
#define NS_ISYNCMESSAGESENDER_IID_STR "21e5d940-d457-4c0f-bb5e-35c159ed19e3"

#define NS_ISYNCMESSAGESENDER_IID \
  {0x21e5d940, 0xd457, 0x4c0f, \
    { 0xbb, 0x5e, 0x35, 0xc1, 0x59, 0xed, 0x19, 0xe3 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsISyncMessageSender : public nsIFrameMessageManager {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ISYNCMESSAGESENDER_IID)

  /* [implicit_jscontext,optional_argc] jsval sendSyncMessage ([optional] in AString messageName, [optional] in jsval obj); */
  NS_SCRIPTABLE NS_IMETHOD SendSyncMessage(const nsAString & messageName, const JS::Value & obj, JSContext* cx, PRUint8 _argc, JS::Value *_retval NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsISyncMessageSender, NS_ISYNCMESSAGESENDER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSISYNCMESSAGESENDER \
  NS_SCRIPTABLE NS_IMETHOD SendSyncMessage(const nsAString & messageName, const JS::Value & obj, JSContext* cx, PRUint8 _argc, JS::Value *_retval NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSISYNCMESSAGESENDER(_to) \
  NS_SCRIPTABLE NS_IMETHOD SendSyncMessage(const nsAString & messageName, const JS::Value & obj, JSContext* cx, PRUint8 _argc, JS::Value *_retval NS_OUTPARAM) { return _to SendSyncMessage(messageName, obj, cx, _argc, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSISYNCMESSAGESENDER(_to) \
  NS_SCRIPTABLE NS_IMETHOD SendSyncMessage(const nsAString & messageName, const JS::Value & obj, JSContext* cx, PRUint8 _argc, JS::Value *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->SendSyncMessage(messageName, obj, cx, _argc, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsSyncMessageSender : public nsISyncMessageSender
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSISYNCMESSAGESENDER

  nsSyncMessageSender();

private:
  ~nsSyncMessageSender();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsSyncMessageSender, nsISyncMessageSender)

nsSyncMessageSender::nsSyncMessageSender()
{
  /* member initializers and constructor code */
}

nsSyncMessageSender::~nsSyncMessageSender()
{
  /* destructor code */
}

/* [implicit_jscontext,optional_argc] jsval sendSyncMessage ([optional] in AString messageName, [optional] in jsval obj); */
NS_IMETHODIMP nsSyncMessageSender::SendSyncMessage(const nsAString & messageName, const JS::Value & obj, JSContext* cx, PRUint8 _argc, JS::Value *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIContentFrameMessageManager */
#define NS_ICONTENTFRAMEMESSAGEMANAGER_IID_STR "78a1d024-60e3-4b7b-98cd-4c6b84b4f060"

#define NS_ICONTENTFRAMEMESSAGEMANAGER_IID \
  {0x78a1d024, 0x60e3, 0x4b7b, \
    { 0x98, 0xcd, 0x4c, 0x6b, 0x84, 0xb4, 0xf0, 0x60 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIContentFrameMessageManager : public nsISyncMessageSender {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ICONTENTFRAMEMESSAGEMANAGER_IID)

  /* readonly attribute nsIDOMWindow content; */
  NS_SCRIPTABLE NS_IMETHOD GetContent(nsIDOMWindow * *aContent) = 0;

  /* readonly attribute nsIDocShell docShell; */
  NS_SCRIPTABLE NS_IMETHOD GetDocShell(nsIDocShell * *aDocShell) = 0;

  /* void dump (in DOMString aStr); */
  NS_SCRIPTABLE NS_IMETHOD Dump(const nsAString & aStr) = 0;

  /* void privateNoteIntentionalCrash (); */
  NS_SCRIPTABLE NS_IMETHOD PrivateNoteIntentionalCrash(void) = 0;

  /* DOMString atob (in DOMString aAsciiString); */
  NS_SCRIPTABLE NS_IMETHOD Atob(const nsAString & aAsciiString, nsAString & _retval NS_OUTPARAM) = 0;

  /* DOMString btoa (in DOMString aBase64Data); */
  NS_SCRIPTABLE NS_IMETHOD Btoa(const nsAString & aBase64Data, nsAString & _retval NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIContentFrameMessageManager, NS_ICONTENTFRAMEMESSAGEMANAGER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSICONTENTFRAMEMESSAGEMANAGER \
  NS_SCRIPTABLE NS_IMETHOD GetContent(nsIDOMWindow * *aContent); \
  NS_SCRIPTABLE NS_IMETHOD GetDocShell(nsIDocShell * *aDocShell); \
  NS_SCRIPTABLE NS_IMETHOD Dump(const nsAString & aStr); \
  NS_SCRIPTABLE NS_IMETHOD PrivateNoteIntentionalCrash(void); \
  NS_SCRIPTABLE NS_IMETHOD Atob(const nsAString & aAsciiString, nsAString & _retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD Btoa(const nsAString & aBase64Data, nsAString & _retval NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSICONTENTFRAMEMESSAGEMANAGER(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetContent(nsIDOMWindow * *aContent) { return _to GetContent(aContent); } \
  NS_SCRIPTABLE NS_IMETHOD GetDocShell(nsIDocShell * *aDocShell) { return _to GetDocShell(aDocShell); } \
  NS_SCRIPTABLE NS_IMETHOD Dump(const nsAString & aStr) { return _to Dump(aStr); } \
  NS_SCRIPTABLE NS_IMETHOD PrivateNoteIntentionalCrash(void) { return _to PrivateNoteIntentionalCrash(); } \
  NS_SCRIPTABLE NS_IMETHOD Atob(const nsAString & aAsciiString, nsAString & _retval NS_OUTPARAM) { return _to Atob(aAsciiString, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD Btoa(const nsAString & aBase64Data, nsAString & _retval NS_OUTPARAM) { return _to Btoa(aBase64Data, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSICONTENTFRAMEMESSAGEMANAGER(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetContent(nsIDOMWindow * *aContent) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetContent(aContent); } \
  NS_SCRIPTABLE NS_IMETHOD GetDocShell(nsIDocShell * *aDocShell) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDocShell(aDocShell); } \
  NS_SCRIPTABLE NS_IMETHOD Dump(const nsAString & aStr) { return !_to ? NS_ERROR_NULL_POINTER : _to->Dump(aStr); } \
  NS_SCRIPTABLE NS_IMETHOD PrivateNoteIntentionalCrash(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->PrivateNoteIntentionalCrash(); } \
  NS_SCRIPTABLE NS_IMETHOD Atob(const nsAString & aAsciiString, nsAString & _retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->Atob(aAsciiString, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD Btoa(const nsAString & aBase64Data, nsAString & _retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->Btoa(aBase64Data, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsContentFrameMessageManager : public nsIContentFrameMessageManager
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSICONTENTFRAMEMESSAGEMANAGER

  nsContentFrameMessageManager();

private:
  ~nsContentFrameMessageManager();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsContentFrameMessageManager, nsIContentFrameMessageManager)

nsContentFrameMessageManager::nsContentFrameMessageManager()
{
  /* member initializers and constructor code */
}

nsContentFrameMessageManager::~nsContentFrameMessageManager()
{
  /* destructor code */
}

/* readonly attribute nsIDOMWindow content; */
NS_IMETHODIMP nsContentFrameMessageManager::GetContent(nsIDOMWindow * *aContent)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDocShell docShell; */
NS_IMETHODIMP nsContentFrameMessageManager::GetDocShell(nsIDocShell * *aDocShell)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void dump (in DOMString aStr); */
NS_IMETHODIMP nsContentFrameMessageManager::Dump(const nsAString & aStr)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void privateNoteIntentionalCrash (); */
NS_IMETHODIMP nsContentFrameMessageManager::PrivateNoteIntentionalCrash()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* DOMString atob (in DOMString aAsciiString); */
NS_IMETHODIMP nsContentFrameMessageManager::Atob(const nsAString & aAsciiString, nsAString & _retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* DOMString btoa (in DOMString aBase64Data); */
NS_IMETHODIMP nsContentFrameMessageManager::Btoa(const nsAString & aBase64Data, nsAString & _retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIInProcessContentFrameMessageManager */
#define NS_IINPROCESSCONTENTFRAMEMESSAGEMANAGER_IID_STR "1f7af930-a232-4a84-a049-73eaa45f2db5"

#define NS_IINPROCESSCONTENTFRAMEMESSAGEMANAGER_IID \
  {0x1f7af930, 0xa232, 0x4a84, \
    { 0xa0, 0x49, 0x73, 0xea, 0xa4, 0x5f, 0x2d, 0xb5 }}

class NS_NO_VTABLE nsIInProcessContentFrameMessageManager : public nsIContentFrameMessageManager {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IINPROCESSCONTENTFRAMEMESSAGEMANAGER_IID)

  /* [notxpcom] nsIContent getOwnerContent (); */
  NS_IMETHOD_(nsIContent *) GetOwnerContent(void) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIInProcessContentFrameMessageManager, NS_IINPROCESSCONTENTFRAMEMESSAGEMANAGER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIINPROCESSCONTENTFRAMEMESSAGEMANAGER \
  NS_IMETHOD_(nsIContent *) GetOwnerContent(void); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIINPROCESSCONTENTFRAMEMESSAGEMANAGER(_to) \
  NS_IMETHOD_(nsIContent *) GetOwnerContent(void) { return _to GetOwnerContent(); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIINPROCESSCONTENTFRAMEMESSAGEMANAGER(_to) \
  NS_IMETHOD_(nsIContent *) GetOwnerContent(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOwnerContent(); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsInProcessContentFrameMessageManager : public nsIInProcessContentFrameMessageManager
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIINPROCESSCONTENTFRAMEMESSAGEMANAGER

  nsInProcessContentFrameMessageManager();

private:
  ~nsInProcessContentFrameMessageManager();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsInProcessContentFrameMessageManager, nsIInProcessContentFrameMessageManager)

nsInProcessContentFrameMessageManager::nsInProcessContentFrameMessageManager()
{
  /* member initializers and constructor code */
}

nsInProcessContentFrameMessageManager::~nsInProcessContentFrameMessageManager()
{
  /* destructor code */
}

/* [notxpcom] nsIContent getOwnerContent (); */
NS_IMETHODIMP_(nsIContent *) nsInProcessContentFrameMessageManager::GetOwnerContent()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsITreeItemFrameMessageManager */
#define NS_ITREEITEMFRAMEMESSAGEMANAGER_IID_STR "e91b0939-a74a-4c4f-8cfd-17dd42e8642a"

#define NS_ITREEITEMFRAMEMESSAGEMANAGER_IID \
  {0xe91b0939, 0xa74a, 0x4c4f, \
    { 0x8c, 0xfd, 0x17, 0xdd, 0x42, 0xe8, 0x64, 0x2a }}

class NS_NO_VTABLE NS_SCRIPTABLE nsITreeItemFrameMessageManager : public nsIFrameMessageManager {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ITREEITEMFRAMEMESSAGEMANAGER_IID)

  /* readonly attribute unsigned long childCount; */
  NS_SCRIPTABLE NS_IMETHOD GetChildCount(PRUint32 *aChildCount) = 0;

  /* nsITreeItemFrameMessageManager getChildAt (in unsigned long aIndex); */
  NS_SCRIPTABLE NS_IMETHOD GetChildAt(PRUint32 aIndex, nsITreeItemFrameMessageManager * *_retval NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsITreeItemFrameMessageManager, NS_ITREEITEMFRAMEMESSAGEMANAGER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSITREEITEMFRAMEMESSAGEMANAGER \
  NS_SCRIPTABLE NS_IMETHOD GetChildCount(PRUint32 *aChildCount); \
  NS_SCRIPTABLE NS_IMETHOD GetChildAt(PRUint32 aIndex, nsITreeItemFrameMessageManager * *_retval NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSITREEITEMFRAMEMESSAGEMANAGER(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetChildCount(PRUint32 *aChildCount) { return _to GetChildCount(aChildCount); } \
  NS_SCRIPTABLE NS_IMETHOD GetChildAt(PRUint32 aIndex, nsITreeItemFrameMessageManager * *_retval NS_OUTPARAM) { return _to GetChildAt(aIndex, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSITREEITEMFRAMEMESSAGEMANAGER(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetChildCount(PRUint32 *aChildCount) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetChildCount(aChildCount); } \
  NS_SCRIPTABLE NS_IMETHOD GetChildAt(PRUint32 aIndex, nsITreeItemFrameMessageManager * *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetChildAt(aIndex, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsTreeItemFrameMessageManager : public nsITreeItemFrameMessageManager
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSITREEITEMFRAMEMESSAGEMANAGER

  nsTreeItemFrameMessageManager();

private:
  ~nsTreeItemFrameMessageManager();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsTreeItemFrameMessageManager, nsITreeItemFrameMessageManager)

nsTreeItemFrameMessageManager::nsTreeItemFrameMessageManager()
{
  /* member initializers and constructor code */
}

nsTreeItemFrameMessageManager::~nsTreeItemFrameMessageManager()
{
  /* destructor code */
}

/* readonly attribute unsigned long childCount; */
NS_IMETHODIMP nsTreeItemFrameMessageManager::GetChildCount(PRUint32 *aChildCount)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsITreeItemFrameMessageManager getChildAt (in unsigned long aIndex); */
NS_IMETHODIMP nsTreeItemFrameMessageManager::GetChildAt(PRUint32 aIndex, nsITreeItemFrameMessageManager * *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIChromeFrameMessageManager */
#define NS_ICHROMEFRAMEMESSAGEMANAGER_IID_STR "14e1f147-793d-4788-bbbb-ae806ecdddbb"

#define NS_ICHROMEFRAMEMESSAGEMANAGER_IID \
  {0x14e1f147, 0x793d, 0x4788, \
    { 0xbb, 0xbb, 0xae, 0x80, 0x6e, 0xcd, 0xdd, 0xbb }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIChromeFrameMessageManager : public nsITreeItemFrameMessageManager {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ICHROMEFRAMEMESSAGEMANAGER_IID)

  /* void loadFrameScript (in AString aURL, in boolean aAllowDelayedLoad); */
  NS_SCRIPTABLE NS_IMETHOD LoadFrameScript(const nsAString & aURL, bool aAllowDelayedLoad) = 0;

  /* void removeDelayedFrameScript (in AString aURL); */
  NS_SCRIPTABLE NS_IMETHOD RemoveDelayedFrameScript(const nsAString & aURL) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIChromeFrameMessageManager, NS_ICHROMEFRAMEMESSAGEMANAGER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSICHROMEFRAMEMESSAGEMANAGER \
  NS_SCRIPTABLE NS_IMETHOD LoadFrameScript(const nsAString & aURL, bool aAllowDelayedLoad); \
  NS_SCRIPTABLE NS_IMETHOD RemoveDelayedFrameScript(const nsAString & aURL); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSICHROMEFRAMEMESSAGEMANAGER(_to) \
  NS_SCRIPTABLE NS_IMETHOD LoadFrameScript(const nsAString & aURL, bool aAllowDelayedLoad) { return _to LoadFrameScript(aURL, aAllowDelayedLoad); } \
  NS_SCRIPTABLE NS_IMETHOD RemoveDelayedFrameScript(const nsAString & aURL) { return _to RemoveDelayedFrameScript(aURL); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSICHROMEFRAMEMESSAGEMANAGER(_to) \
  NS_SCRIPTABLE NS_IMETHOD LoadFrameScript(const nsAString & aURL, bool aAllowDelayedLoad) { return !_to ? NS_ERROR_NULL_POINTER : _to->LoadFrameScript(aURL, aAllowDelayedLoad); } \
  NS_SCRIPTABLE NS_IMETHOD RemoveDelayedFrameScript(const nsAString & aURL) { return !_to ? NS_ERROR_NULL_POINTER : _to->RemoveDelayedFrameScript(aURL); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsChromeFrameMessageManager : public nsIChromeFrameMessageManager
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSICHROMEFRAMEMESSAGEMANAGER

  nsChromeFrameMessageManager();

private:
  ~nsChromeFrameMessageManager();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsChromeFrameMessageManager, nsIChromeFrameMessageManager)

nsChromeFrameMessageManager::nsChromeFrameMessageManager()
{
  /* member initializers and constructor code */
}

nsChromeFrameMessageManager::~nsChromeFrameMessageManager()
{
  /* destructor code */
}

/* void loadFrameScript (in AString aURL, in boolean aAllowDelayedLoad); */
NS_IMETHODIMP nsChromeFrameMessageManager::LoadFrameScript(const nsAString & aURL, bool aAllowDelayedLoad)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void removeDelayedFrameScript (in AString aURL); */
NS_IMETHODIMP nsChromeFrameMessageManager::RemoveDelayedFrameScript(const nsAString & aURL)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIFrameMessageManager_h__ */
