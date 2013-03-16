module sha

in "C header" `{
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	#if defined(__APPLE__) && defined(__MACH__)
		#define COMMON_DIGEST_FOR_OPENSSL
		#include <CommonCrypto/CommonDigest.h>
		#define SHA1 CC_SHA1
		#include <CommonCrypto/CommonHMAC.h>
		#define HMAC CCHmac
	#else
		#include <openssl/hmac.h>
		#include <openssl/sha.h>
		#include <openssl/rc4.h>
		#include <openssl/aes.h>
	#endif
`}

fun sha1(str: String):String import String::from_cstring`{

	char *c_str=NULL; c_str=String_to_cstring(str);
	int i = 0;
	unsigned char result[SHA_DIGEST_LENGTH];
	char *buf = malloc(SHA_DIGEST_LENGTH*2+1 * sizeof(char));

	SHA1(c_str, strlen(c_str), result);
	for(i = 0; i < SHA_DIGEST_LENGTH; i++)
		sprintf((char*)&(buf[i*2]), "%02x", (unsigned char)result[i]);
	
	return  new_String_from_cstring(buf);
`}

