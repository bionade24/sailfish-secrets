#ifndef SF_SECRETS_H
#define SF_SECRETS_H

#include <glib-object.h>
#include <gio/gio.h>

#define SF_SECRETS_ERROR (sf_secrets_error_quark())
GQuark sf_secrets_error_quark(void);

extern const gchar *SF_SECRETS_DEFAULT_AUTHENTICATION_PLUGIN;
extern const gchar *SF_SECRETS_DEFAULT_STORAGE_PLUGIN;
extern const gchar *SF_SECRETS_DEFAULT_ENCRYPTION_PLUGIN;
extern const gchar *SF_SECRETS_DEAFULT_ENCRYPTED_STORAGE_PLUGIN;

typedef enum SfSecretsResultCode_ {
    SF_SECRETS_RESULT_CODE_SUCCEEDED = 0,
    SF_SECRETS_RESULT_CODE_PENDING   = 1,
    SF_SECRETS_RESULT_CODE_FAILED    = 2
} SfSecretsResultCode;


typedef enum SfSecretsUserInteractionMode_ {
    SF_SECRETS_USER_INTERACTION_MODE_PREVENT = 0,
    SF_SECRETS_USER_INTERACTION_MODE_SYSTEM,
    SF_SECRETS_USER_INTERACTION_MODE_APPLICATION
} SfSecretsUserInteractionMode;

typedef enum SfSecretsAccessControlMode_ {
    SF_SECRETS_ACCESS_CONTROL_MODE_OWNER_ONLY = 0,
    SF_SECRETS_ACCESS_CONTROL_MODE_SYSTEM_ACCESS,
    SF_SECRETS_ACCESS_CONTROL_MODE_NONE
} SfSecretsAccessControlMode;

typedef enum SfSecretsDeviceUnlockSemantic_ {
    SF_SECRETS_DEVICE_UNLOCK_SEMANTIC_KEEP_UNLOCKED = 0,
    SF_SECRETS_DEVICE_UNLOCK_SEMANTIC_VERIFY_LOCK,
    SF_SECRETS_DEVICE_UNLOCK_SEMANTIC_RELOCK,
} SfSecretsDeviceUnlockSemantic;

typedef enum SfSecretsPluginState_ {
    SF_SECRETS_PLUGIN_STATE_UNKNOWN   = 0,
    SF_SECRETS_PLUGIN_STATE_AVAILABLE = 1 << 0,
    SF_SECRETS_PLUGIN_STATE_MASTER_UNLOCKED = 1 << 1,
    SF_SECRETS_PLUGIN_STATE_PLUGIN_UNLOCKED = 1 << 2,
    SF_SECRETS_PLUGIN_STATE_PLUGIN_SUPPORTS_LOCKING = 1 << 3,
    SF_SECRETS_PLUGIN_STATE_PLUGIN_SUPPORTS_SET_LOCK_CODE = 1 << 4,
} SfSecretsPluginState;

typedef enum SfSecretsError_ {
        SF_SECRETS_ERROR_NO = 0,
        SF_SECRETS_ERROR_UNKNOWN = 2,
        SF_SECRETS_ERROR_SERIALIZATION = 3,
        SF_SECRETS_ERROR_DAEMON = 5,
        SF_SECRETS_ERROR_DISCOVERY = 6,

        SF_SECRETS_ERROR_PERMISSIONS = 10,
        SF_SECRETS_ERROR_INCORRECT_AUTHENTICATION_CODE,
        SF_SECRETS_ERROR_AUTHENTICATION_TIMEOUT,
        SF_SECRETS_ERROR_OPERATION_NOT_SUPPORTED,
        SF_SECRETS_ERROR_OPERATION_REQUIRES_USER_INTERACTION,
        SF_SECRETS_ERROR_OPERATION_REQUIRES_APPLICATION_USER_INTERACTION,
        SF_SECRETS_ERROR_OPERATION_REQUIRES_SYSTEM_USER_INTERACTION,
        SF_SECRETS_ERROR_SECRET_MANAGER_NOT_INITIALIZED,

        SF_SECRETS_ERROR_SECRETS_DAEMON_REQUEST_PID = 20,
        SF_SECRETS_ERROR_SECRETS_DAEMON_REQUEST_QUEUE_FULL,
        SF_SECRETS_ERROR_SECRETS_DAEMON_LOCKED,
        SF_SECRETS_ERROR_SECRETS_DAEMON_NOT_LOCKED,

        SF_SECRETS_ERROR_SECRETS_PLUGIN_ENCRYPTION = 30,
        SF_SECRETS_ERROR_SECRETS_PLUGIN_DECRYPTION,
        SF_SECRETS_ERROR_SECRETS_PLUGIN_KEY_DERIVATION,
        SF_SECRETS_ERROR_SECRETS_PLUGIN_IS_LOCKED,

        SF_SECRETS_ERROR_INVALID_SECRET = 40,
        SF_SECRETS_ERROR_INVALID_SECRET_IDENTIFIER,
        SF_SECRETS_ERROR_INVALID_FILTER,
        SF_SECRETS_ERROR_INVALID_COLLECTION,
        SF_SECRETS_ERROR_INVALID_EXTENSION_PLUGIN,
        SF_SECRETS_ERROR_INVALID_APPLICATION_ID,
        SF_SECRETS_ERROR_COLLECTION_ALREADY_EXISTS,
        SF_SECRETS_ERROR_SECRET_ALREADY_EXISTS,

        SF_SECRETS_ERROR_COLLECTION_IS_LOCKED = 60,
        SF_SECRETS_ERROR_COLLECTION_IS_BUSY,

        SF_SECRETS_ERROR_DATABASE_QUERY = 70,
        SF_SECRETS_ERROR_DATABASE_TRANSACTION,
        SF_SECRETS_ERROR_DATABASE,

        SF_SECRETS_ERROR_INTERACTION_SERVICE_UNKNOWN = 80,
        SF_SECRETS_ERROR_INTERACTION_SERVICE_UNAVAILABLE,
        SF_SECRETS_ERROR_INTERACTION_SERVICE_REQUEST_INVALID,
        SF_SECRETS_ERROR_INTERACTION_SERVICE_REQUEST_FAILED,
        SF_SECRETS_ERROR_INTERACTION_SERVICE_REQUEST_BUSY,
        SF_SECRETS_ERROR_INTERACTION_SERVICE_RESPONSE_INVALID,

        SF_SECRETS_ERROR_INTERACTION_VIEW_UNAVAILABLE = 90,
        SF_SECRETS_ERROR_INTERACTION_VIEW_REQUEST,
        SF_SECRETS_ERROR_INTERACTION_VIEW_PARENT,
        SF_SECRETS_ERROR_INTERACTION_VIEW_CHILD,
        SF_SECRETS_ERROR_INTERACTION_VIEW,
        SF_SECRETS_ERROR_INTERACTION_VIEW_USER_CANCELED,

        SF_SECRETS_ERROR_NETWORK = 98,
        SF_SECRETS_ERROR_NETWORK_SSL = 99,
        SF_SECRETS_ERROR_HTTP_CONTINUE = 100,
        SF_SECRETS_ERROR_HTTP_SWITCHING_PROTOCOL = 101,
        SF_SECRETS_ERROR_HTTP_OK = 200,
        SF_SECRETS_ERROR_HTTP_CREATED = 201,
        SF_SECRETS_ERROR_HTTP_ACCEPTED = 202,
        SF_SECRETS_ERROR_HTTP_NON_AUTHORITATIVE_INFORMATION = 203,
        SF_SECRETS_ERROR_HTTP_NO_CONTENT = 204,
        SF_SECRETS_ERROR_HTTP_RESET_CONTENT = 205,
        SF_SECRETS_ERROR_HTTP_PARTIAL_CONTENT = 206,
        SF_SECRETS_ERROR_HTTP_MULTIPLE_CHOICE = 300,
        SF_SECRETS_ERROR_HTTP_MOVED_PERMANENTLY = 301,
        SF_SECRETS_ERROR_HTTP_FOUND = 302,
        SF_SECRETS_ERROR_HTTP_SEE_OTHER = 303,
        SF_SECRETS_ERROR_HTTP_NOT_MODIFIED = 304,
        SF_SECRETS_ERROR_HTTP_USE_PROXY = 305,
        SF_SECRETS_ERROR_HTTP_UNUSED = 306,
        SF_SECRETS_ERROR_HTTP_TEMPORARY_REDIRECT = 307,
        SF_SECRETS_ERROR_HTTP_PERMANENT_REDIRECT = 308,
        SF_SECRETS_ERROR_HTTP_BAD_REQUEST = 400,
        SF_SECRETS_ERROR_HTTP_UNAUTHORIZED = 401,
        SF_SECRETS_ERROR_HTTP_PAYMENT_REQUIRED = 402,
        SF_SECRETS_ERROR_HTTP_FORBIDDEN = 403,
        SF_SECRETS_ERROR_HTTP_NOT_FOUND = 404,
        SF_SECRETS_ERROR_HTTP_METHOD_NOT_ALLOWED = 405,
        SF_SECRETS_ERROR_HTTP_NOT_ACCEPTABLE = 406,
        SF_SECRETS_ERROR_HTTP_PROXY_AUTHENTICATION_REQUIRED = 407,
        SF_SECRETS_ERROR_HTTP_REQUEST_TIMEOUT = 408,
        SF_SECRETS_ERROR_HTTP_CONFLICT = 409,
        SF_SECRETS_ERROR_HTTP_GONE = 410,
        SF_SECRETS_ERROR_HTTP_LENGTH_REQUIRED = 411,
        SF_SECRETS_ERROR_HTTP_PRECONDITION_FAILED = 412,
        SF_SECRETS_ERROR_HTTP_PAYLOAD_TOO_LARGE = 413,
        SF_SECRETS_ERROR_HTTP_URI_TOO_LONG = 414,
        SF_SECRETS_ERROR_HTTP_UNSUPPORTED_MEDIA_TYPE = 415,
        SF_SECRETS_ERROR_HTTP_REQUEST_RANGE_NOT_SATISFIABLE = 416,
        SF_SECRETS_ERROR_HTTP_EXPECTATION_FAILED = 417,
        SF_SECRETS_ERROR_HTTP_MISDIRECTED_REQUEST = 421,
        SF_SECRETS_ERROR_HTTP_UPGRADE_REQUIRED = 426,
        SF_SECRETS_ERROR_HTTP_PRECONDITION_REQUIRED = 428,
        SF_SECRETS_ERROR_HTTP_TOO_MANY_REQUESTS = 429,
        SF_SECRETS_ERROR_HTTP_REQUEST_HEADER_FIELDS_TOO_LARGE = 431,
        SF_SECRETS_ERROR_HTTP_UNAVAILABLE_FOR_LEGAL_REASONS = 451,
        SF_SECRETS_ERROR_HTTP_INTERNAL_SERVER = 500,
        SF_SECRETS_ERROR_HTTP_NOT_IMPLEMENTED = 501,
        SF_SECRETS_ERROR_HTTP_BAD_GATEWAY = 502,
        SF_SECRETS_ERROR_HTTP_SERVICE_UNAVAILABLE = 503,
        SF_SECRETS_ERROR_HTTP_GATEWAY_TIMEOUT = 504,
        SF_SECRETS_ERROR_HTTP_VERSION_NOT_SUPPORTED = 505,
        SF_SECRETS_ERROR_HTTP_VARIANT_ALSO_NEGOTIATES = 506,
        SF_SECRETS_ERROR_HTTP_INSUFFICIENT_STORAGE = 507,
        SF_SECRETS_ERROR_HTTP_NETWORK_AUTHENTICATION_REQUIRED = 511,

        SF_SECRETS_ERROR_OTHER = 1024,
} SfSecretsError;

typedef enum SfSecretsFilterOperator_ {
    SF_SECRETS_FILTER_OPERATOR_OR = 0,
    SF_SECRETS_FILTER_OPERATOR_AND
} SfSecretsFilterOperator;

typedef enum SfSecretsOperation_ {
    SF_SECRETS_OPERATION_UNKNOWN_OPERATION    = 0,

    SF_SECRETS_OPERATION_REQUEST_USER_DATA     = 1 << 0,   // usually used in conjunction with StoreSecret, i.e. store data requested from user.

    SF_SECRETS_OPERATION_UNLOCK_DATABASE      = 1 << 1,
    SF_SECRETS_OPERATION_LOCK_DATABASE        = 1 << 2,
    SF_SECRETS_OPERATION_MODIFY_LOCK_DATABASE  = 1 << 3,

    SF_SECRETS_OPERATION_UNLOCK_PLUGIN        = 1 << 4,
    SF_SECRETS_OPERATION_LOCK_PLUGIN          = 1 << 5,
    SF_SECRETS_OPERATION_MODIFY_LOCK_PLUGIN    = 1 << 6,

    SF_SECRETS_OPERATION_CREATE_COLLECTION    = 1 << 7,
    SF_SECRETS_OPERATION_UNLOCK_COLLECTION    = 1 << 8,
    SF_SECRETS_OPERATION_LOCK_COLLECTION      = 1 << 9,
    SF_SECRETS_OPERATION_MODIFY_LOCK_COLLECTION= 1 << 10,
    SF_SECRETS_OPERATION_DELETE_COLLECTION    = 1 << 11,

    SF_SECRETS_OPERATION_READ_SECRET          = 1 << 12,
    SF_SECRETS_OPERATION_STORE_SECRET         = 1 << 13,
    SF_SECRETS_OPERATION_UNLOCK_SECRET        = 1 << 14,
    SF_SECRETS_OPERATION_LOCK_SECRET          = 1 << 15,
    SF_SECRETS_OPERATION_MODIFY_LOCK_SECRET    = 1 << 16,
    SF_SECRETS_OPERATION_DELETE_SECRET        = 1 << 17,

    SF_SECRETS_OPERATION_ENCRYPT             = 1 << 18,
    SF_SECRETS_OPERATION_DECRYPT             = 1 << 19,
    SF_SECRETS_OPERATION_SIGN                = 1 << 20,
    SF_SECRETS_OPERATION_VERIFY              = 1 << 21,
    SF_SECRETS_OPERATION_DERIVE_DIGEST        = 1 << 22,
    SF_SECRETS_OPERATION_DERIVE_MAC           = 1 << 23,
    SF_SECRETS_OPERATION_DERIVE_KEY           = 1 << 24,
    SF_SECRETS_OPERATION_STORE_KEY            = 1 << 25,
    SF_SECRETS_OPERATION_IMPORT_KEY           = 1 << 26,

    SF_SECRETS_OPERATION_CREATE_PASSWORD      = 1 << 27,

    // reserved
    SF_SECRETS_OPERATION_LAST_OPERATION       = 1 << 30
} SfSecretsOperation;

typedef enum SfSecretsPrompt_ {
    SF_SECRETS_PROMPT_MESSAGE,
    SF_SECRETS_PROMPT_INSTRUCTION                 = 0x10,
    SF_SECRETS_PROMPT_NEW_INSTRUCTION,
    SF_SECRETS_PROMPT_REPEAT_INSTRUCTION,
    SF_SECRETS_PROMPT_ACCEPT                      = 0x20,
    SF_SECRETS_PROMPT_CANCEL                      = 0x30,
} SfSecretsPrompt;

typedef enum SfSecretsLockCodeTargetType {
    SF_SECRETS_LOCK_CODE_TARGET_TYPE_METADATA_DATABASE = 0,
    SF_SECRETS_LOCK_CODE_TARGET_TYPE_EXTENSION_PLUGIN,
} SfSecretsLockCodeTargetType;

typedef enum SfSecretsLockStatus {
    SF_SECRETS_LOCK_STATUS_UNKNOWN = 0,
    SF_SECRETS_LOCK_STATUS_UNSUPPORTED,
    SF_SECRETS_LOCK_STATUS_UNLOCKED,
    SF_SECRETS_LOCK_STATUS_LOCKED,
} SfSecretsLockStatus;

struct SfSecretsPluginInfo_ {
    gchar *display_name;
    gchar *name;
    int version;
    SfSecretsPluginState state;
};
typedef struct SfSecretsPluginInfo_ SfSecretsPluginInfo;

typedef enum SfSecretsEchoMode_ {
        SF_SECRETS_ECHO_MODE_UNKNOWN = 0,
        SF_SECRETS_ECHO_MODE_NORMAL,
        SF_SECRETS_ECHO_MODE_PASSWORD,
        SF_SECRETS_ECHO_MODE_NO,
} SfSecretsEchoMode;

typedef enum SfSecretsInputType_ {
    SF_SECRETS_INPUT_TYPE_UNKNOWN        = 0,
    SF_SECRETS_INPUT_TYPE_AUTHENTICATION = 1,  // returns non-empty data if the user authenticates via system dialog
    SF_SECRETS_INPUT_TYPE_CONFIRMATION   = 2,  // returns non-empty data if the user allows the operation
    SF_SECRETS_INPUT_TYPE_NUMERIC        = 4,  // returns the numeric (e.g. PIN) data from the user
    SF_SECRETS_INPUT_TYPE_ALPHANUMERIC   = 8,  // returns the alphanumeric (e.g. passphrase) data from the user
    SF_SECRETS_INPUT_TYPE_FINGERPRINT    = 16, // returns the fingerprint data from the user
    SF_SECRETS_INPUT_TYPE_IRIS           = 32, // returns the iris data from the user
    SF_SECRETS_INPUT_TYPE_RETINA         = 64, // returns the retina data from the user
    // reserved
    SF_SECRETS_INPUT_TYPE_LAST           = 65536
} SfSecretsInputType;

typedef enum SfSecretsHealth_ {
        SF_SECRETS_HEALTH_OK = 0,
        SF_SECRETS_HEALTH_UNKNOWN,
        SF_SECRETS_HEALTH_CORRUPTED,
        SF_SECRETS_HEALTH_OTHER_ERROR,
} SfSecretsHealth;

void sf_secrets_plugin_info_free(SfSecretsPluginInfo *info);
SfSecretsPluginInfo *sf_secrets_plugin_info_copy(const SfSecretsPluginInfo *info);

#endif
