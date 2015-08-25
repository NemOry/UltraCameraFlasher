#include "applicationui.hpp"

#include "Flashlight.hpp"

#include <bb/cascades/Application>
#include <bb/cascades/QmlDocument>
#include <bb/cascades/AbstractPane>
#include <bb/cascades/LocaleHandler>
#include <QtCore/QtCore>
 #include <QTimer>

#include <bb/system/InvokeRequest>
#include <bb/cascades/Invocation>
#include <bb/system/SystemDialog>
#include <bb/system/SystemToast>
#include <bb/system/phone/Call>
#include <bb/device/Led>

using namespace bb::cascades;
using namespace bb::system;
using namespace bb::system::phone;

ApplicationUI::ApplicationUI(bb::cascades::Application *app) :
        QObject(app)
{
	timer = new QTimer(this);
	connect(timer, SIGNAL(timeout()), this, SLOT(timedout()));

	phone = new Phone(this);

	connect(phone, SIGNAL(callUpdated(bb::system::phone::Call&)), this, SLOT(onCallUpdated(bb::system::phone::Call&)));

    QmlDocument *qml = QmlDocument::create("asset:///main.qml").parent(this);
    qml->setContextProperty("_app", this);
    AbstractPane *root = qml->createRootObject<AbstractPane>();

    app->setScene(root);
}

void ApplicationUI::onCallUpdated(const bb::system::phone::Call &call)
{
    CallState::Type state = call.callState();
    qDebug() << "call updated: callId=" << call.callId() << " callState=" << state;

    if (bb::system::phone::CallState::Connected == state)
    {
        qDebug() << "call connected, do something ...";
    }
}

bool ApplicationUI::LEDStatus()
{
	return true;
}

void ApplicationUI::toggleLED()
{

}

bool ApplicationUI::flashlightStatus()
{
	return flashlight.enabled();
}

void ApplicationUI::toggleFlashlight()
{
	repeatedTimes = 0;
	maxTimes = 0;
	timer->stop();
	flashlight.setEnabled(!flashlight.enabled());
}

void ApplicationUI::startFlashing(int interval, int times)
{
	stopFlashing();
	maxTimes = times;
    timer->start(interval);
}

void ApplicationUI::stopFlashing()
{
	repeatedTimes = 0;
	maxTimes = 0;
	flashlight.setEnabled(false);
    timer->stop();
}

void ApplicationUI::timedout()
{
	flashlight.setEnabled(!flashlight.enabled());

	repeatedTimes++;

	if(repeatedTimes >= maxTimes)
	{
		stopFlashing();
	}
}

void ApplicationUI::onSystemLanguageChanged()
{
    QCoreApplication::instance()->removeTranslator(m_pTranslator);
    // Initiate, load and install the application translation files.
    QString locale_string = QLocale().name();
    QString file_name = QString("FlashNotification_%1").arg(locale_string);
    if (m_pTranslator->load(file_name, "app/native/qm")) {
        QCoreApplication::instance()->installTranslator(m_pTranslator);
    }
}

QString ApplicationUI::getSetting(const QString &objectName, const QString &defaultValue)
{
	QSettings settings;

	if (settings.value(objectName).isNull()
			|| settings.value(objectName) == "") {
		return defaultValue;
	}

	return settings.value(objectName).toString();
}

void ApplicationUI::setSetting(const QString &objectName, const QString &inputValue)
{
	QSettings settings;
	settings.setValue(objectName, QVariant(inputValue));
}

void ApplicationUI::showToast(const QString &text) {
	SystemToast *toast = new SystemToast(this);
	toast->setBody(text);
	toast->setPosition(SystemUiPosition::MiddleCenter);
	toast->show();
}

void ApplicationUI::showDialog(const QString &title, const QString &text) {
	SystemDialog *dialog = new SystemDialog(this);
	dialog->setTitle(title);
	dialog->setBody(text);
	dialog->setEmoticonsEnabled(true);
	dialog->show();
}

// --------------------- INVOCATIONS --------------------- //

void ApplicationUI::invokeShare(QString text)
{
	InvokeRequest request;
	request.setMimeType("text/plain");
	request.setAction("bb.action.SHARE");
	request.setData(text.toAscii());
	invokeManager->invoke(request);
}

void ApplicationUI::invokeEmail(QString email, QString subject, QString body) {
	InvokeRequest request;
	request.setTarget("sys.pim.uib.email.hybridcomposer");
	request.setAction("bb.action.SENDEMAIL");
	request.setUri(
			"mailto:" + email + "?subject=" + subject.replace(" ", "%20")
					+ "&body=" + body.replace(" ", "%20"));
	invokeManager->invoke(request);
}

void ApplicationUI::invokeBBWorld(QString appurl) {
	InvokeRequest request;
	request.setMimeType("application/x-bb-appworld");
	request.setAction("bb.action.OPEN");
	request.setUri(appurl);
	invokeManager->invoke(request);
}

void ApplicationUI::invokeBrowser(QString url) {
	InvokeRequest request;
	request.setTarget("sys.browser");
	request.setAction("bb.action.OPEN");
	request.setUri(url);
	invokeManager->invoke(request);
}

void ApplicationUI::invokeOpenWithFacebook(QString accountid) {
	InvokeRequest request;
	request.setTarget("com.rim.bb.app.facebook");
	request.setAction("bb.action.OPEN");

	QVariantMap payload;
	payload["object_type"] = "page";
	payload["object_id"] = accountid;

	request.setMetadata(payload);
	invokeManager->invoke(request);
}

void ApplicationUI::invokeOpenWithTwitter(QString accountid) {
	InvokeRequest request;
	request.setTarget("com.twitter.urihandler");
	request.setAction("bb.action.VIEW");
	request.setUri("twitter:connect:" + accountid);
	invokeManager->invoke(request);
}
