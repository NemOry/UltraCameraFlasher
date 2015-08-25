#ifndef ApplicationUI_HPP_
#define ApplicationUI_HPP_

#include <QObject>
#include <QtCore/QtCore>
#include <QTimer>
#include <bb/system/InvokeManager>
#include <bb/system/phone/Call>
#include <bb/system/phone/Phone>
using namespace bb::system::phone;

using bb::system::InvokeManager;

#include "Flashlight.hpp"

namespace bb
{
    namespace cascades
    {
        class Application;
        class LocaleHandler;

        namespace system
		{
			class InvokeManager;
		}
    }
}

class QTranslator;

/*!
 * @brief Application object
 *
 *
 */

class ApplicationUI : public QObject
{
    Q_OBJECT
public:
    ApplicationUI(bb::cascades::Application *app);
    virtual ~ApplicationUI() { }

    Q_INVOKABLE void onSystemLanguageChanged();
    Q_INVOKABLE void timedout();
    Q_INVOKABLE bool LEDStatus();
	Q_INVOKABLE void toggleLED();
    Q_INVOKABLE bool flashlightStatus();
    Q_INVOKABLE void toggleFlashlight();
    Q_INVOKABLE void startFlashing(int interval, int times);
    Q_INVOKABLE void stopFlashing();
    Q_INVOKABLE void onCallUpdated(const bb::system::phone::Call &call);

    Q_INVOKABLE void invokeEmail(QString email, QString subject, QString body);
	Q_INVOKABLE void invokeShare(QString text);
	Q_INVOKABLE void invokeBBWorld(QString appurl);
	Q_INVOKABLE void invokeBrowser(QString url);
	Q_INVOKABLE void invokeOpenWithFacebook(QString accountid);
	Q_INVOKABLE void invokeOpenWithTwitter(QString accountid);

	Q_INVOKABLE void showToast(const QString &text);
	Q_INVOKABLE void showDialog(const QString &title, const QString &text);
	Q_INVOKABLE QString getSetting(const QString &objectName, const QString &defaultValue);
	Q_INVOKABLE void setSetting(const QString &objectName, const QString &inputValue);

private:
    QTranslator* m_pTranslator;
    bb::cascades::LocaleHandler* m_pLocaleHandler;

    QTimer* timer;
    int maxTimes;
    int repeatedTimes;
    InvokeManager* invokeManager;
    Flashlight flashlight;

    bb::system::phone::Phone* phone;
};

#endif /* ApplicationUI_HPP_ */
