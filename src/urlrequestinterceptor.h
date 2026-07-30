#ifndef URLREQUESTINTERCEPTOR_H
#define URLREQUESTINTERCEPTOR_H

#include <QWebEngineUrlRequestInfo>
#include <QWebEngineUrlRequestInterceptor>

// The whole game ships inside the binary (qrc), so no request should ever
// leave the process; block everything except local/internal schemes.
class UrlRequestInterceptor : public QWebEngineUrlRequestInterceptor
{
    Q_OBJECT

public:
    using QWebEngineUrlRequestInterceptor::QWebEngineUrlRequestInterceptor;

    void interceptRequest(QWebEngineUrlRequestInfo &info) override
    {
        const QString scheme = info.requestUrl().scheme();
        const bool local = scheme == QLatin1String("qrc")
                || scheme == QLatin1String("data")
                || scheme == QLatin1String("blob")
                || scheme == QLatin1String("devtools");
        info.block(!local);
    }
};

#endif // URLREQUESTINTERCEPTOR_H
