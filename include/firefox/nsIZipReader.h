/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM /jds/packages/BUILD/SUNWfirefox-10.0.2/firefox/modules/libjar/nsIZipReader.idl
 */

#ifndef __gen_nsIZipReader_h__
#define __gen_nsIZipReader_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIUTF8StringEnumerator; /* forward declaration */

class nsIInputStream; /* forward declaration */

class nsIFile; /* forward declaration */

class nsIPrincipal; /* forward declaration */


/* starting interface:    nsIZipEntry */
#define NS_IZIPENTRY_IID_STR "e1c028bc-c478-11da-95a8-00e08161165f"

#define NS_IZIPENTRY_IID \
  {0xe1c028bc, 0xc478, 0x11da, \
    { 0x95, 0xa8, 0x00, 0xe0, 0x81, 0x61, 0x16, 0x5f }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIZipEntry : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IZIPENTRY_IID)

  /* readonly attribute unsigned short compression; */
  NS_SCRIPTABLE NS_IMETHOD GetCompression(PRUint16 *aCompression) = 0;

  /* readonly attribute unsigned long size; */
  NS_SCRIPTABLE NS_IMETHOD GetSize(PRUint32 *aSize) = 0;

  /* readonly attribute unsigned long realSize; */
  NS_SCRIPTABLE NS_IMETHOD GetRealSize(PRUint32 *aRealSize) = 0;

  /* readonly attribute unsigned long CRC32; */
  NS_SCRIPTABLE NS_IMETHOD GetCRC32(PRUint32 *aCRC32) = 0;

  /* readonly attribute boolean isDirectory; */
  NS_SCRIPTABLE NS_IMETHOD GetIsDirectory(bool *aIsDirectory) = 0;

  /* readonly attribute PRTime lastModifiedTime; */
  NS_SCRIPTABLE NS_IMETHOD GetLastModifiedTime(PRTime *aLastModifiedTime) = 0;

  /* readonly attribute boolean isSynthetic; */
  NS_SCRIPTABLE NS_IMETHOD GetIsSynthetic(bool *aIsSynthetic) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIZipEntry, NS_IZIPENTRY_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIZIPENTRY \
  NS_SCRIPTABLE NS_IMETHOD GetCompression(PRUint16 *aCompression); \
  NS_SCRIPTABLE NS_IMETHOD GetSize(PRUint32 *aSize); \
  NS_SCRIPTABLE NS_IMETHOD GetRealSize(PRUint32 *aRealSize); \
  NS_SCRIPTABLE NS_IMETHOD GetCRC32(PRUint32 *aCRC32); \
  NS_SCRIPTABLE NS_IMETHOD GetIsDirectory(bool *aIsDirectory); \
  NS_SCRIPTABLE NS_IMETHOD GetLastModifiedTime(PRTime *aLastModifiedTime); \
  NS_SCRIPTABLE NS_IMETHOD GetIsSynthetic(bool *aIsSynthetic); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIZIPENTRY(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetCompression(PRUint16 *aCompression) { return _to GetCompression(aCompression); } \
  NS_SCRIPTABLE NS_IMETHOD GetSize(PRUint32 *aSize) { return _to GetSize(aSize); } \
  NS_SCRIPTABLE NS_IMETHOD GetRealSize(PRUint32 *aRealSize) { return _to GetRealSize(aRealSize); } \
  NS_SCRIPTABLE NS_IMETHOD GetCRC32(PRUint32 *aCRC32) { return _to GetCRC32(aCRC32); } \
  NS_SCRIPTABLE NS_IMETHOD GetIsDirectory(bool *aIsDirectory) { return _to GetIsDirectory(aIsDirectory); } \
  NS_SCRIPTABLE NS_IMETHOD GetLastModifiedTime(PRTime *aLastModifiedTime) { return _to GetLastModifiedTime(aLastModifiedTime); } \
  NS_SCRIPTABLE NS_IMETHOD GetIsSynthetic(bool *aIsSynthetic) { return _to GetIsSynthetic(aIsSynthetic); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIZIPENTRY(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetCompression(PRUint16 *aCompression) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCompression(aCompression); } \
  NS_SCRIPTABLE NS_IMETHOD GetSize(PRUint32 *aSize) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSize(aSize); } \
  NS_SCRIPTABLE NS_IMETHOD GetRealSize(PRUint32 *aRealSize) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetRealSize(aRealSize); } \
  NS_SCRIPTABLE NS_IMETHOD GetCRC32(PRUint32 *aCRC32) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCRC32(aCRC32); } \
  NS_SCRIPTABLE NS_IMETHOD GetIsDirectory(bool *aIsDirectory) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIsDirectory(aIsDirectory); } \
  NS_SCRIPTABLE NS_IMETHOD GetLastModifiedTime(PRTime *aLastModifiedTime) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLastModifiedTime(aLastModifiedTime); } \
  NS_SCRIPTABLE NS_IMETHOD GetIsSynthetic(bool *aIsSynthetic) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIsSynthetic(aIsSynthetic); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsZipEntry : public nsIZipEntry
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIZIPENTRY

  nsZipEntry();

private:
  ~nsZipEntry();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsZipEntry, nsIZipEntry)

nsZipEntry::nsZipEntry()
{
  /* member initializers and constructor code */
}

nsZipEntry::~nsZipEntry()
{
  /* destructor code */
}

/* readonly attribute unsigned short compression; */
NS_IMETHODIMP nsZipEntry::GetCompression(PRUint16 *aCompression)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned long size; */
NS_IMETHODIMP nsZipEntry::GetSize(PRUint32 *aSize)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned long realSize; */
NS_IMETHODIMP nsZipEntry::GetRealSize(PRUint32 *aRealSize)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned long CRC32; */
NS_IMETHODIMP nsZipEntry::GetCRC32(PRUint32 *aCRC32)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean isDirectory; */
NS_IMETHODIMP nsZipEntry::GetIsDirectory(bool *aIsDirectory)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute PRTime lastModifiedTime; */
NS_IMETHODIMP nsZipEntry::GetLastModifiedTime(PRTime *aLastModifiedTime)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean isSynthetic; */
NS_IMETHODIMP nsZipEntry::GetIsSynthetic(bool *aIsSynthetic)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIZipReader */
#define NS_IZIPREADER_IID_STR "8fbf5023-3827-4fbc-a464-5db546e7f747"

#define NS_IZIPREADER_IID \
  {0x8fbf5023, 0x3827, 0x4fbc, \
    { 0xa4, 0x64, 0x5d, 0xb5, 0x46, 0xe7, 0xf7, 0x47 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIZipReader : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IZIPREADER_IID)

  /* void open (in nsIFile zipFile); */
  NS_SCRIPTABLE NS_IMETHOD Open(nsIFile *zipFile) = 0;

  /* void openInner (in nsIZipReader zipReader, in AUTF8String zipEntry); */
  NS_SCRIPTABLE NS_IMETHOD OpenInner(nsIZipReader *zipReader, const nsACString & zipEntry) = 0;

  /* readonly attribute nsIFile file; */
  NS_SCRIPTABLE NS_IMETHOD GetFile(nsIFile * *aFile) = 0;

  /* void close (); */
  NS_SCRIPTABLE NS_IMETHOD Close(void) = 0;

  /* void test (in AUTF8String aEntryName); */
  NS_SCRIPTABLE NS_IMETHOD Test(const nsACString & aEntryName) = 0;

  /* void extract (in AUTF8String zipEntry, in nsIFile outFile); */
  NS_SCRIPTABLE NS_IMETHOD Extract(const nsACString & zipEntry, nsIFile *outFile) = 0;

  /* nsIZipEntry getEntry (in AUTF8String zipEntry); */
  NS_SCRIPTABLE NS_IMETHOD GetEntry(const nsACString & zipEntry, nsIZipEntry * *_retval NS_OUTPARAM) = 0;

  /* boolean hasEntry (in AUTF8String zipEntry); */
  NS_SCRIPTABLE NS_IMETHOD HasEntry(const nsACString & zipEntry, bool *_retval NS_OUTPARAM) = 0;

  /* nsIUTF8StringEnumerator findEntries (in AUTF8String aPattern); */
  NS_SCRIPTABLE NS_IMETHOD FindEntries(const nsACString & aPattern, nsIUTF8StringEnumerator * *_retval NS_OUTPARAM) = 0;

  /* nsIInputStream getInputStream (in AUTF8String zipEntry); */
  NS_SCRIPTABLE NS_IMETHOD GetInputStream(const nsACString & zipEntry, nsIInputStream * *_retval NS_OUTPARAM) = 0;

  /* nsIInputStream getInputStreamWithSpec (in AUTF8String aJarSpec, in AUTF8String zipEntry); */
  NS_SCRIPTABLE NS_IMETHOD GetInputStreamWithSpec(const nsACString & aJarSpec, const nsACString & zipEntry, nsIInputStream * *_retval NS_OUTPARAM) = 0;

  /* nsIPrincipal getCertificatePrincipal (in AUTF8String aEntryName); */
  NS_SCRIPTABLE NS_IMETHOD GetCertificatePrincipal(const nsACString & aEntryName, nsIPrincipal * *_retval NS_OUTPARAM) = 0;

  /* readonly attribute PRUint32 manifestEntriesCount; */
  NS_SCRIPTABLE NS_IMETHOD GetManifestEntriesCount(PRUint32 *aManifestEntriesCount) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIZipReader, NS_IZIPREADER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIZIPREADER \
  NS_SCRIPTABLE NS_IMETHOD Open(nsIFile *zipFile); \
  NS_SCRIPTABLE NS_IMETHOD OpenInner(nsIZipReader *zipReader, const nsACString & zipEntry); \
  NS_SCRIPTABLE NS_IMETHOD GetFile(nsIFile * *aFile); \
  NS_SCRIPTABLE NS_IMETHOD Close(void); \
  NS_SCRIPTABLE NS_IMETHOD Test(const nsACString & aEntryName); \
  NS_SCRIPTABLE NS_IMETHOD Extract(const nsACString & zipEntry, nsIFile *outFile); \
  NS_SCRIPTABLE NS_IMETHOD GetEntry(const nsACString & zipEntry, nsIZipEntry * *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD HasEntry(const nsACString & zipEntry, bool *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD FindEntries(const nsACString & aPattern, nsIUTF8StringEnumerator * *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetInputStream(const nsACString & zipEntry, nsIInputStream * *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetInputStreamWithSpec(const nsACString & aJarSpec, const nsACString & zipEntry, nsIInputStream * *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetCertificatePrincipal(const nsACString & aEntryName, nsIPrincipal * *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetManifestEntriesCount(PRUint32 *aManifestEntriesCount); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIZIPREADER(_to) \
  NS_SCRIPTABLE NS_IMETHOD Open(nsIFile *zipFile) { return _to Open(zipFile); } \
  NS_SCRIPTABLE NS_IMETHOD OpenInner(nsIZipReader *zipReader, const nsACString & zipEntry) { return _to OpenInner(zipReader, zipEntry); } \
  NS_SCRIPTABLE NS_IMETHOD GetFile(nsIFile * *aFile) { return _to GetFile(aFile); } \
  NS_SCRIPTABLE NS_IMETHOD Close(void) { return _to Close(); } \
  NS_SCRIPTABLE NS_IMETHOD Test(const nsACString & aEntryName) { return _to Test(aEntryName); } \
  NS_SCRIPTABLE NS_IMETHOD Extract(const nsACString & zipEntry, nsIFile *outFile) { return _to Extract(zipEntry, outFile); } \
  NS_SCRIPTABLE NS_IMETHOD GetEntry(const nsACString & zipEntry, nsIZipEntry * *_retval NS_OUTPARAM) { return _to GetEntry(zipEntry, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD HasEntry(const nsACString & zipEntry, bool *_retval NS_OUTPARAM) { return _to HasEntry(zipEntry, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD FindEntries(const nsACString & aPattern, nsIUTF8StringEnumerator * *_retval NS_OUTPARAM) { return _to FindEntries(aPattern, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetInputStream(const nsACString & zipEntry, nsIInputStream * *_retval NS_OUTPARAM) { return _to GetInputStream(zipEntry, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetInputStreamWithSpec(const nsACString & aJarSpec, const nsACString & zipEntry, nsIInputStream * *_retval NS_OUTPARAM) { return _to GetInputStreamWithSpec(aJarSpec, zipEntry, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetCertificatePrincipal(const nsACString & aEntryName, nsIPrincipal * *_retval NS_OUTPARAM) { return _to GetCertificatePrincipal(aEntryName, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetManifestEntriesCount(PRUint32 *aManifestEntriesCount) { return _to GetManifestEntriesCount(aManifestEntriesCount); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIZIPREADER(_to) \
  NS_SCRIPTABLE NS_IMETHOD Open(nsIFile *zipFile) { return !_to ? NS_ERROR_NULL_POINTER : _to->Open(zipFile); } \
  NS_SCRIPTABLE NS_IMETHOD OpenInner(nsIZipReader *zipReader, const nsACString & zipEntry) { return !_to ? NS_ERROR_NULL_POINTER : _to->OpenInner(zipReader, zipEntry); } \
  NS_SCRIPTABLE NS_IMETHOD GetFile(nsIFile * *aFile) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetFile(aFile); } \
  NS_SCRIPTABLE NS_IMETHOD Close(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Close(); } \
  NS_SCRIPTABLE NS_IMETHOD Test(const nsACString & aEntryName) { return !_to ? NS_ERROR_NULL_POINTER : _to->Test(aEntryName); } \
  NS_SCRIPTABLE NS_IMETHOD Extract(const nsACString & zipEntry, nsIFile *outFile) { return !_to ? NS_ERROR_NULL_POINTER : _to->Extract(zipEntry, outFile); } \
  NS_SCRIPTABLE NS_IMETHOD GetEntry(const nsACString & zipEntry, nsIZipEntry * *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetEntry(zipEntry, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD HasEntry(const nsACString & zipEntry, bool *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->HasEntry(zipEntry, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD FindEntries(const nsACString & aPattern, nsIUTF8StringEnumerator * *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->FindEntries(aPattern, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetInputStream(const nsACString & zipEntry, nsIInputStream * *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetInputStream(zipEntry, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetInputStreamWithSpec(const nsACString & aJarSpec, const nsACString & zipEntry, nsIInputStream * *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetInputStreamWithSpec(aJarSpec, zipEntry, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetCertificatePrincipal(const nsACString & aEntryName, nsIPrincipal * *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCertificatePrincipal(aEntryName, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetManifestEntriesCount(PRUint32 *aManifestEntriesCount) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetManifestEntriesCount(aManifestEntriesCount); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsZipReader : public nsIZipReader
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIZIPREADER

  nsZipReader();

private:
  ~nsZipReader();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsZipReader, nsIZipReader)

nsZipReader::nsZipReader()
{
  /* member initializers and constructor code */
}

nsZipReader::~nsZipReader()
{
  /* destructor code */
}

/* void open (in nsIFile zipFile); */
NS_IMETHODIMP nsZipReader::Open(nsIFile *zipFile)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void openInner (in nsIZipReader zipReader, in AUTF8String zipEntry); */
NS_IMETHODIMP nsZipReader::OpenInner(nsIZipReader *zipReader, const nsACString & zipEntry)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIFile file; */
NS_IMETHODIMP nsZipReader::GetFile(nsIFile * *aFile)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void close (); */
NS_IMETHODIMP nsZipReader::Close()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void test (in AUTF8String aEntryName); */
NS_IMETHODIMP nsZipReader::Test(const nsACString & aEntryName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void extract (in AUTF8String zipEntry, in nsIFile outFile); */
NS_IMETHODIMP nsZipReader::Extract(const nsACString & zipEntry, nsIFile *outFile)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIZipEntry getEntry (in AUTF8String zipEntry); */
NS_IMETHODIMP nsZipReader::GetEntry(const nsACString & zipEntry, nsIZipEntry * *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean hasEntry (in AUTF8String zipEntry); */
NS_IMETHODIMP nsZipReader::HasEntry(const nsACString & zipEntry, bool *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIUTF8StringEnumerator findEntries (in AUTF8String aPattern); */
NS_IMETHODIMP nsZipReader::FindEntries(const nsACString & aPattern, nsIUTF8StringEnumerator * *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIInputStream getInputStream (in AUTF8String zipEntry); */
NS_IMETHODIMP nsZipReader::GetInputStream(const nsACString & zipEntry, nsIInputStream * *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIInputStream getInputStreamWithSpec (in AUTF8String aJarSpec, in AUTF8String zipEntry); */
NS_IMETHODIMP nsZipReader::GetInputStreamWithSpec(const nsACString & aJarSpec, const nsACString & zipEntry, nsIInputStream * *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIPrincipal getCertificatePrincipal (in AUTF8String aEntryName); */
NS_IMETHODIMP nsZipReader::GetCertificatePrincipal(const nsACString & aEntryName, nsIPrincipal * *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute PRUint32 manifestEntriesCount; */
NS_IMETHODIMP nsZipReader::GetManifestEntriesCount(PRUint32 *aManifestEntriesCount)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIZipReaderCache */
#define NS_IZIPREADERCACHE_IID_STR "72fc56e5-3e6e-4d11-8967-26ab96071032"

#define NS_IZIPREADERCACHE_IID \
  {0x72fc56e5, 0x3e6e, 0x4d11, \
    { 0x89, 0x67, 0x26, 0xab, 0x96, 0x07, 0x10, 0x32 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIZipReaderCache : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IZIPREADERCACHE_IID)

  /* void init (in unsigned long cacheSize); */
  NS_SCRIPTABLE NS_IMETHOD Init(PRUint32 cacheSize) = 0;

  /* nsIZipReader getZip (in nsIFile zipFile); */
  NS_SCRIPTABLE NS_IMETHOD GetZip(nsIFile *zipFile, nsIZipReader * *_retval NS_OUTPARAM) = 0;

  /* nsIZipReader getInnerZip (in nsIFile zipFile, in AUTF8String zipEntry); */
  NS_SCRIPTABLE NS_IMETHOD GetInnerZip(nsIFile *zipFile, const nsACString & zipEntry, nsIZipReader * *_retval NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIZipReaderCache, NS_IZIPREADERCACHE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIZIPREADERCACHE \
  NS_SCRIPTABLE NS_IMETHOD Init(PRUint32 cacheSize); \
  NS_SCRIPTABLE NS_IMETHOD GetZip(nsIFile *zipFile, nsIZipReader * *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetInnerZip(nsIFile *zipFile, const nsACString & zipEntry, nsIZipReader * *_retval NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIZIPREADERCACHE(_to) \
  NS_SCRIPTABLE NS_IMETHOD Init(PRUint32 cacheSize) { return _to Init(cacheSize); } \
  NS_SCRIPTABLE NS_IMETHOD GetZip(nsIFile *zipFile, nsIZipReader * *_retval NS_OUTPARAM) { return _to GetZip(zipFile, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetInnerZip(nsIFile *zipFile, const nsACString & zipEntry, nsIZipReader * *_retval NS_OUTPARAM) { return _to GetInnerZip(zipFile, zipEntry, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIZIPREADERCACHE(_to) \
  NS_SCRIPTABLE NS_IMETHOD Init(PRUint32 cacheSize) { return !_to ? NS_ERROR_NULL_POINTER : _to->Init(cacheSize); } \
  NS_SCRIPTABLE NS_IMETHOD GetZip(nsIFile *zipFile, nsIZipReader * *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetZip(zipFile, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetInnerZip(nsIFile *zipFile, const nsACString & zipEntry, nsIZipReader * *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetInnerZip(zipFile, zipEntry, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsZipReaderCache : public nsIZipReaderCache
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIZIPREADERCACHE

  nsZipReaderCache();

private:
  ~nsZipReaderCache();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsZipReaderCache, nsIZipReaderCache)

nsZipReaderCache::nsZipReaderCache()
{
  /* member initializers and constructor code */
}

nsZipReaderCache::~nsZipReaderCache()
{
  /* destructor code */
}

/* void init (in unsigned long cacheSize); */
NS_IMETHODIMP nsZipReaderCache::Init(PRUint32 cacheSize)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIZipReader getZip (in nsIFile zipFile); */
NS_IMETHODIMP nsZipReaderCache::GetZip(nsIFile *zipFile, nsIZipReader * *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIZipReader getInnerZip (in nsIFile zipFile, in AUTF8String zipEntry); */
NS_IMETHODIMP nsZipReaderCache::GetInnerZip(nsIFile *zipFile, const nsACString & zipEntry, nsIZipReader * *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#define NS_ZIPREADER_CID                             \
{ /* 88e2fd0b-f7f4-480c-9483-7846b00e8dad */         \
   0x88e2fd0b, 0xf7f4, 0x480c,                       \
  { 0x94, 0x83, 0x78, 0x46, 0xb0, 0x0e, 0x8d, 0xad } \
}
#define NS_ZIPREADERCACHE_CID                        \
{ /* 608b7f6f-4b60-40d6-87ed-d933bf53d8c1 */         \
   0x608b7f6f, 0x4b60, 0x40d6,                       \
  { 0x87, 0xed, 0xd9, 0x33, 0xbf, 0x53, 0xd8, 0xc1 } \
}

#endif /* __gen_nsIZipReader_h__ */
