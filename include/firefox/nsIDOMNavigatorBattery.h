/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM /jds/packages/BUILD/SUNWfirefox-10.0.2/firefox/dom/battery/nsIDOMNavigatorBattery.idl
 */

#ifndef __gen_nsIDOMNavigatorBattery_h__
#define __gen_nsIDOMNavigatorBattery_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMBatteryManager; /* forward declaration */


/* starting interface:    nsIDOMNavigatorBattery */
#define NS_IDOMNAVIGATORBATTERY_IID_STR "a19eedd7-6c26-4676-bd34-7ca74ca5f565"

#define NS_IDOMNAVIGATORBATTERY_IID \
  {0xa19eedd7, 0x6c26, 0x4676, \
    { 0xbd, 0x34, 0x7c, 0xa7, 0x4c, 0xa5, 0xf5, 0x65 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMNavigatorBattery : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMNAVIGATORBATTERY_IID)

  /* readonly attribute nsIDOMBatteryManager mozBattery; */
  NS_SCRIPTABLE NS_IMETHOD GetMozBattery(nsIDOMBatteryManager * *aMozBattery) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMNavigatorBattery, NS_IDOMNAVIGATORBATTERY_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMNAVIGATORBATTERY \
  NS_SCRIPTABLE NS_IMETHOD GetMozBattery(nsIDOMBatteryManager * *aMozBattery); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMNAVIGATORBATTERY(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetMozBattery(nsIDOMBatteryManager * *aMozBattery) { return _to GetMozBattery(aMozBattery); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMNAVIGATORBATTERY(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetMozBattery(nsIDOMBatteryManager * *aMozBattery) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMozBattery(aMozBattery); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMNavigatorBattery : public nsIDOMNavigatorBattery
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMNAVIGATORBATTERY

  nsDOMNavigatorBattery();

private:
  ~nsDOMNavigatorBattery();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMNavigatorBattery, nsIDOMNavigatorBattery)

nsDOMNavigatorBattery::nsDOMNavigatorBattery()
{
  /* member initializers and constructor code */
}

nsDOMNavigatorBattery::~nsDOMNavigatorBattery()
{
  /* destructor code */
}

/* readonly attribute nsIDOMBatteryManager mozBattery; */
NS_IMETHODIMP nsDOMNavigatorBattery::GetMozBattery(nsIDOMBatteryManager * *aMozBattery)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMNavigatorBattery_h__ */
