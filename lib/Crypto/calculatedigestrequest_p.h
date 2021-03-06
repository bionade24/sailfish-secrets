/*
 * Copyright (C) 2018 Jolla Ltd.
 * Contact: Chris Adams <chris.adams@jollamobile.com>
 * All rights reserved.
 * BSD 3-Clause License, see LICENSE.
 */

#ifndef LIBSAILFISHCRYPTO_CALCULATEDIGESTREQUEST_P_H
#define LIBSAILFISHCRYPTO_CALCULATEDIGESTREQUEST_P_H

#include "Crypto/cryptoglobal.h"
#include "Crypto/signrequest.h"
#include "Crypto/cryptomanager.h"

#include <QtCore/QPointer>
#include <QtCore/QScopedPointer>
#include <QtCore/QString>

#include <QtDBus/QDBusPendingCallWatcher>

namespace Sailfish {

namespace Crypto {

class CalculateDigestRequestPrivate
{
    Q_DISABLE_COPY(CalculateDigestRequestPrivate)

public:
    explicit CalculateDigestRequestPrivate();

    QPointer<Sailfish::Crypto::CryptoManager> m_manager;
    QVariantMap m_customParameters;
    QByteArray m_data;
    Sailfish::Crypto::CryptoManager::SignaturePadding m_padding;
    Sailfish::Crypto::CryptoManager::DigestFunction m_digestFunction;
    QString m_cryptoPluginName;
    QByteArray m_digest;

    QScopedPointer<QDBusPendingCallWatcher> m_watcher;
    Sailfish::Crypto::Request::Status m_status;
    Sailfish::Crypto::Result m_result;
};

} // namespace Crypto

} // namespace Sailfish

#endif // LIBSAILFISHCRYPTO_CALCULATEDIGESTREQUEST_P_H
