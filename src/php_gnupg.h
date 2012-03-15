/*
  +--------------------------------------------------------------------+
  | PECL :: gnupg                                                      |
  +--------------------------------------------------------------------+
  | Redistribution and use in source and binary forms, with or without |
  | modification, are permitted provided that the conditions mentioned |
  | in the accompanying LICENSE file are met.                          |
  +--------------------------------------------------------------------+
  | Copyright (c) 2006, Thilo Raufeisen <traufeisen@php.net>           |
  +--------------------------------------------------------------------+
*/

/* $Id: php_gnupg.h 256443 2008-03-31 09:39:35Z sfox $ */

#ifndef PHP_GNUPG_H
#define PHP_GNUPG_H

extern zend_module_entry gnupg_module_entry;
#define phpext_gnupg_ptr &gnupg_module_entry

#define PHP_GNUPG_VERSION "1.3.2-dev"

#ifdef PHP_WIN32
#define PHP_GNUPG_API __declspec(dllexport)
#else
#define PHP_GNUPG_API
#endif

#ifdef ZTS
#include "TSRM.h"
#endif

#include <gpgme.h>

typedef struct gnupg_object{
	zend_object zo;
	gpgme_ctx_t ctx;
    gpgme_error_t err;
    int errormode;
    char* errortxt;
    int signmode;
    gpgme_key_t *encryptkeys;
    unsigned int encrypt_size;
    HashTable *signkeys;
    HashTable *decryptkeys;
} gnupg_object;

zend_class_entry *gnupg_class_entry;

PHP_MINIT_FUNCTION(gnupg);
PHP_MSHUTDOWN_FUNCTION(gnupg);
PHP_MINFO_FUNCTION(gnupg);

PHP_FUNCTION(gnupg_keyinfo);
PHP_FUNCTION(gnupg_verify);
PHP_FUNCTION(gnupg_geterror);
PHP_FUNCTION(gnupg_setsignmode);
PHP_FUNCTION(gnupg_setarmor);
PHP_FUNCTION(gnupg_sign);
PHP_FUNCTION(gnupg_clearsignkeys);
PHP_FUNCTION(gnupg_clearencryptkeys);
PHP_FUNCTION(gnupg_cleardecryptkeys);
PHP_FUNCTION(gnupg_getprotocol);
PHP_FUNCTION(gnupg_encrypt);
PHP_FUNCTION(gnupg_encryptsign);
PHP_FUNCTION(gnupg_decrypt);
PHP_FUNCTION(gnupg_decryptverify);
PHP_FUNCTION(gnupg_export);
PHP_FUNCTION(gnupg_import);
PHP_FUNCTION(gnupg_init);
PHP_FUNCTION(gnupg_addsignkey);
PHP_FUNCTION(gnupg_addencryptkey);
PHP_FUNCTION(gnupg_adddecryptkey);
PHP_FUNCTION(gnupg_deletekey);
PHP_FUNCTION(gnupg_gettrustlist);
PHP_FUNCTION(gnupg_listsignatures);
PHP_FUNCTION(gnupg_seterrormode);

#ifdef ZTS
#define GNUPG_G(v) TSRMG(gnupg_globals_id, zend_gnupg_globals *, v)
#else
#define GNUPG_G(v) (gnupg_globals.v)
#endif

#endif	/* PHP_GNUPG_H */


/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * vim600: noet sw=4 ts=4 fdm=marker
 * vim<600: noet sw=4 ts=4
 */
